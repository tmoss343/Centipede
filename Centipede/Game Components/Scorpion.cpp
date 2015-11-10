#include "GeneralIncludes.h"

Scorpion::Scorpion(std::string texture, MushroomField* theField, int horizantalDivisions, int verticalDivisions)
	: Enemy(texture, theField, horizantalDivisions, verticalDivisions)
{
	//Individual Sprite information
	MainSprite.setOrigin( MainSprite.getTextureRect().width / 2.0f, MainSprite.getTextureRect().height / 2.0f);
	
	MainSprite.setPosition(Pos);

	scorpionWidth = MainSprite.getTextureRect().width;
	scorpionHeight = MainSprite.getTextureRect().height;

	SetCollider(MainSprite, bitmap, true);
	//Set animation and rotation for movement
	MainSprite.SetAnimation(0, 3);

	scoreAddAmount = 30;
}

void Scorpion::Initialize(sf::Vector2f pos, int moveDirection)
{
	Pos = pos;
	SPEED = 2.0f;
	adjustedSPEED = SPEED * moveDirection;
	distnaceToNextLookAhead = 0;
	health = 1;
	SoundManager::StartScorpionLoop();
	RegisterCollision<Scorpion>(*this);
}

void Scorpion::Update()
{
	if(distnaceToNextLookAhead <= 0)
	{
		CheckInfectMushroom();
		MainSprite.Update();
	}
	distnaceToNextLookAhead -= SPEED;
	Move();

	MainSprite.setPosition(Pos);
}

void Scorpion::Draw()
{
	WindowManager::MainWindow.draw(MainSprite);
}

void Scorpion::Destroy()
{
	DeregisterCollision<Scorpion>(*this);
	SoundManager::StopScorpionLoop();
	ExplosionFactory::CreateExplosion(Pos, "Death");
	SoundManager::PlayKillSound();
	WaveManager::ResetAlarmForScorpion();
}

void Scorpion::Collision(Bullet* other)
{
	health--;
	if(health < 1)
		MarkForDestroy();

	ScoreManager::AddScore(scoreAddAmount);
}

void Scorpion::Move()
{
	Pos.x += adjustedSPEED;
}

//Checks current POS and if there is a shroom infect it
void Scorpion::CheckInfectMushroom()
{
	int X = (Pos.x / 16);
	int Y = (Pos.y / 16) - 1;

	if(field->isInstance(X, Y) && X >=0 && X <= 29)
		field->getElement(X, Y)->Infect();
	if(X < -1 || X > 30)
		MarkForDestroy();

	distnaceToNextLookAhead = SpriteSize;
}