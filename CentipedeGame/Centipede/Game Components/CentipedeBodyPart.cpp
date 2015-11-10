#include "GeneralIncludes.h"
#include <math.h>

CentipedeBodyPart::CentipedeBodyPart()
{
}

void CentipedeBodyPart::Initialize(MushroomField* field, sf::Vector2f position, Centipede* theCreator, int speed, int buildNumber)
{
	//inheirted graphics info
	bitmap = ResourceManager::GetTextureBitmap("Centipede Head");
	MainSprite = AnimatedSprite(ResourceManager::GetTexture("Centipede Head"), 8, 2);
	MainSprite.setScale(2,2);
	MainSprite.setOrigin( MainSprite.getTextureRect().width / 2.0f, MainSprite.getTextureRect().height / 2.0f);
	
	MainSprite.setPosition(Pos);

	centipedeBodyPartWidth = MainSprite.getTextureRect().width * 2;
	centipedeBodyPartHeight = MainSprite.getTextureRect().height * 2;

	SetCollider(MainSprite, bitmap, true);
	RegisterCollision<CentipedeBodyPart>(*this);

	//Set animation and rotation for movement
	MainSprite.SetAnimation(0, 7);
	MainSprite.setRotation(180);
	//private variables
	mushroomField = field;
	creator = theCreator;

	beenToTheEnd = false;
	hasAncestor = false;
	hasDescendant = false;
	turning = false;
	poisoned = false;
	
	SPEED = speed;

	moveDir = 1;
	distanceToNextLookAhead = SpriteSize;
	numberInBuildList = buildNumber;
	Pos = position;

	centipedeBodyPartWidth = SpriteSize;
	centipedeBodyPartHeight = SpriteSize;

	SpawnOffset = sf::Vector2f(HalfSpriteSize, HalfSpriteSize);

	currentState = Enumerators::centipedeMovementMode::Right;
	previousState = currentState;

	//Adjusted Speed set for the first time
	directionalSPEED = SPEED * moveDir;

	SoundManager::StartCentipedeLoop();
}

void CentipedeBodyPart::Destroy()
{
	DeregisterCollision<CentipedeBodyPart>(*this);
}

void CentipedeBodyPart::Update()
{
	if(distanceToNextLookAhead <= 0)
	{
		LookAhead();
		MainSprite.Update();
	}
	distanceToNextLookAhead -= SPEED;
	if(currentState == Enumerators::centipedeMovementMode::Left || currentState == Enumerators::centipedeMovementMode::Right)
	{
		Move();
	}
	else if(currentState == Enumerators::centipedeMovementMode::Turning)
	{
		Turn();
	}

	MainSprite.setPosition(Pos);
}

void CentipedeBodyPart::Draw()
{
	WindowManager::MainWindow.draw(MainSprite);
}

CentipedeBodyPart* CentipedeBodyPart::GetAncestor()
{
	return ancestor;
}

void CentipedeBodyPart::Collision(Bullet* other)
{
	if(hasDescendant)
		descendant->RemoveAncestor();
 	ScoreManager::AddScore(30);
	WaveManager::CentipedeBodyPartDeath();
	//Create Mushroom at the point of death
	int X = (Pos.x / 16) + moveDir;//Adjust to offset given its move position so a body part doesn't miss hitting it
	int Y = (Pos.y / 16) - 1;//Adjusting for the offset of the grid to the size of the window
	if(!mushroomField->isInstance(X, Y))
	{
		mushroomField->SpawnShroom( X, Y);
	}

	MarkForDestroy();
}

void CentipedeBodyPart::Move()
{
	Pos.x += directionalSPEED;
}

void CentipedeBodyPart::Turn()
{
	MainSprite.SetAnimation(8, 15);
	//Down or Up movement
	if(Pos.y <= (51*centipedeBodyPartHeight / 2) && beenToTheEnd)
	{
		directionalSPEED = SPEED * 1;
		beenToTheEnd = false;
	}
	else if(beenToTheEnd && !poisoned)
	{
		directionalSPEED = SPEED * -1;
	} 
	else
	{
		directionalSPEED = SPEED * 1;
	}
	TransitionRow(directionalSPEED);

	if( distanceToNextLookAhead <= 0)
	{
		MainSprite.SetAnimation(0, 7);
		moveDir *= -1;
		directionalSPEED = SPEED * moveDir;
	}
	if(Pos.y + centipedeBodyPartHeight / 2 >= WindowManager::MainWindow.getView().getSize().y)
	{
		beenToTheEnd = true;
		poisoned = false;
	}
}

void CentipedeBodyPart::TransitionRow(int dir)
{
	int rot;
	if(moveDir == -1)
	{
		rot = 270;
		if(dir == -1)
			rot -= 90;
	}
	else
	{
		rot = 0;
		if(dir == -1)
			rot += 90;
	}
	MainSprite.setRotation(rot);
	
	Pos.y += directionalSPEED;
}

Enumerators::centipedeMovementMode CentipedeBodyPart::Follow(CentipedeBodyPart* olderSibling)
{
	Enumerators::centipedeMovementMode ancestralMovement = olderSibling->previousState;
	poisoned = olderSibling->isPoisoned();

	if(ancestralMovement == Enumerators::centipedeMovementMode::Left)
	{
		MainSprite.setRotation(0);
		return Enumerators::centipedeMovementMode::Left;
	}
	else if(ancestralMovement == Enumerators::centipedeMovementMode::Right)
	{
		MainSprite.setRotation(180);
		return Enumerators::centipedeMovementMode::Right;
	}
	else if(ancestralMovement == Enumerators::centipedeMovementMode::Turning)
	{
		return Enumerators::centipedeMovementMode::Turning;
	}
	else
		return Enumerators::centipedeMovementMode::Following;
}

void CentipedeBodyPart::LookAhead()
{
	previousState = currentState;

	int X = (Pos.x / 16);
	int Y = (Pos.y / 16);
	X += moveDir;
	Y -= 1;

	if(hasAncestor)
	{
		currentState = Follow(ancestor);
	}
	else if(mushroomField->isInstance(X, Y) || HUD::IsInstanceOfGlyph(X, Y) || poisoned)
	{
		currentState = Enumerators::centipedeMovementMode::Turning;
		if(mushroomField->isInstance(X, Y) && Y >= 0 && Y < 30 && X >= 0 && X < 30 && mushroomField->getElement(X, Y)->isInfected() && !poisoned)
			poisoned = true;
	}
	else if(currentState == Enumerators::centipedeMovementMode::Turning)
	{
		if(moveDir == 1)
		{
			currentState = Enumerators::centipedeMovementMode::Right;
			MainSprite.setRotation(180);
		}
		else
		{
			currentState = Enumerators::centipedeMovementMode::Left;
			MainSprite.setRotation(0);
		}
	}
	distanceToNextLookAhead = SpriteSize;
}

void CentipedeBodyPart::setAncestor(CentipedeBodyPart* olderSibling)
{
	ancestor = olderSibling;
	currentState = Enumerators::centipedeMovementMode::Following;
	hasAncestor = true;
	bitmap = ResourceManager::GetTextureBitmap("Centipede Body");
	MainSprite = AnimatedSprite(ResourceManager::GetTexture("Centipede Body"), 8, 2);
	MainSprite.setScale(2,2);
	MainSprite.setOrigin( MainSprite.getTextureRect().width / 2.0f, MainSprite.getTextureRect().height / 2.0f);
}
void CentipedeBodyPart::setDescendant(CentipedeBodyPart* youngerSibling)
{
	hasDescendant = true;
	descendant = youngerSibling;
}

void CentipedeBodyPart::RemoveAncestor()
{
	if(hasAncestor)
	{
		hasAncestor = false;
		bitmap = ResourceManager::GetTextureBitmap("Centipede Head");
		MainSprite = AnimatedSprite(ResourceManager::GetTexture("Centipede Head"), 8, 2);
		MainSprite.setScale(2,2);
		MainSprite.setOrigin( MainSprite.getTextureRect().width / 2.0f, MainSprite.getTextureRect().height / 2.0f);
	}
}

bool CentipedeBodyPart::isPoisoned()
{
	return poisoned;
}