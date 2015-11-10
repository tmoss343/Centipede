#include "GeneralIncludes.h"

Bullet::Bullet(sf::Vector2f p, Blaster* theParent)
{
	SPEED = 14.3f;

	bitmap = ResourceManager::GetTextureBitmap("Bullets");
	MainSprite = AnimatedSprite(  ResourceManager::GetTexture("Bullets"), 1, 1);
	
	MainSprite.setOrigin( MainSprite.getTextureRect().width / 2.0f, MainSprite.getTextureRect().height / 2.0f);
	MainSprite.setScale(1,1);
	MainSprite.setPosition(Pos);

	SetCollider(MainSprite, bitmap);

	parent = theParent;

	MainSprite.setPosition(Pos);

	currentState = Enumerators::bulletMode::Holstered;
}

void Bullet::Initialize(sf::Vector2f p)
{
	distanceToNextLookAhead = 0;
	Pos = p;
}

void Bullet::Update()
{
	MainSprite.Update();

	if(currentState == Enumerators::bulletMode::Holstered)
		Pos = sf::Vector2f(parent->getPosition().x, parent->getPosition().y - 5);
	else
		Move();

	MainSprite.setPosition(Pos);
}

void Bullet::Draw()
{
	WindowManager::MainWindow.draw(MainSprite);
}

void Bullet::Destroy()
{
	parent->setBulletPointer(NULL);
	DeregisterCollision<Bullet>( *this );
}

void Bullet::Collision( CentipedeBodyPart *other )
{
	MarkForDestroy();
}

void Bullet::Collision( Scorpion *other )
{
	MarkForDestroy();
}

void Bullet::Collision( Spider *other )
{
	other->SetKiller(parent);
	MarkForDestroy();
}

void Bullet::Collision( Flea *other )
{
	MarkForDestroy();
}

void Bullet::setStateToFire()
{
	RegisterCollision<Bullet>( *this );
	currentState = Enumerators::bulletMode::Firing;
	SoundManager::PlayBulletSound();
}

void Bullet::setStateToHolstered()
{
	currentState = Enumerators::bulletMode::Holstered;
}

void Bullet::callToDestroy()
{
	MarkForDestroy();
}

void Bullet::CheckIfGlyph(int X, int Y)
{
	if(HUD::IsInstanceOfGlyph(X, Y))
	{
		MarkForDestroy();
	}
}

void Bullet::CheckIfMusrhoom(int X, int Y)
{
	if(LevelManager::GetMushroomField()->isInstance(X, Y) && Y >=0 && Y <= 29)
	{
		LevelManager::GetMushroomField()->getElement(X, Y)->GotHit();
		MarkForDestroy();
	}
}

void Bullet::Move()
{
	Pos.y -= SPEED;
	distanceToNextLookAhead -= SPEED;

	if(distanceToNextLookAhead < 0)
	{
		int X = (Pos.x / 16);
		int Y = (Pos.y / 16) - 1;
		CheckIfMusrhoom(X, Y);
		if(!LevelManager::IsPlayerControlled())
		{
			CheckIfGlyph(X, Y);
		}
		distanceToNextLookAhead = HalfSpriteSize;
	}

	if (Pos.y < 0 ) 
	{
		MarkForDestroy();
	}
}