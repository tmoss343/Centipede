#include "GeneralIncludes.h"

Flea::Flea(std::string texture, MushroomField* theField, int horizantalDivisions, int verticalDivisions)
	: Enemy(texture, theField, horizantalDivisions, verticalDivisions)
{
	//Individual Sprite information
	MainSprite.setOrigin( MainSprite.getTextureRect().width / 2.0f, MainSprite.getTextureRect().height / 2.0f);
	
	MainSprite.setPosition(Pos);

	fleaWidth = MainSprite.getTextureRect().width;
	fleaHeight = MainSprite.getTextureRect().height;

	SetCollider(MainSprite, bitmap, true);
	RegisterCollision<Flea>(*this);
	//Set animation and rotation for movement
	MainSprite.SetAnimation(0, 3);

	scoreAddAmount = 30;
}

void Flea::Initialize(sf::Vector2f pos)
{
	if(field->GetMushroomInPlayerArea() < 3 && WaveManager::GetCurrentWave() > 0)//Conitions for a flea to ever spawn.
	{
		Pos = pos;
		SPEED = 4.0f;
		distnaceToNextLookAhead = 0;
		health = 2;
		RegisterCollision<Flea>(*this);
	}
	else
	{
		MarkForDestroy();
	}
}

void Flea::Update()
{
	if(distnaceToNextLookAhead <= 0)
	{
		CheckIfMushroom();
	}
	distnaceToNextLookAhead -= SPEED;
	Move();

	MainSprite.Update();
	MainSprite.setPosition(Pos);
}

void Flea::Draw()
{
	WindowManager::MainWindow.draw(MainSprite);
}

void Flea::Destroy()
{
	DeregisterCollision<Flea>(*this);
	ExplosionFactory::CreateExplosion(Pos, "Death");
	WaveManager::ResetAlarmForFlea();
}

void Flea::Collision(Bullet* other)
{
	health--;
	if(health < 1)
		MarkForDestroy();

	ScoreManager::AddScore(scoreAddAmount);
}

void Flea::Move()
{
	Pos.y += SPEED;
}

//Checks current POS and if there is a shroom infect it
void Flea::CheckIfMushroom()
{
	int X = (Pos.x / 16) - 1;//adjusting position for rounding
	int Y = (Pos.y / 16) - 1;//Adjust for within field

	if(!field->isInstance(X, Y) && X >=0 && X <= 29 && Y < 30 && field->GetMushroomInPlayerArea() < 3)
		field->SpawnShroom(X, Y);
	if(Y > 30)
		MarkForDestroy();

	distnaceToNextLookAhead = SpriteSize * (rand() % 10);
}
