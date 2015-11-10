#include "GeneralIncludes.h"
#include <math.h>

Mushroom::Mushroom(sf::Vector2f p)
{
	health = 0;
	Pos = p;
	infected = false;

	bitmap = ResourceManager::GetTextureBitmap("Mushroom");
	MainSprite = AnimatedSprite(ResourceManager::GetTexture("Mushroom"), 4, 2);

	MainSprite.setOrigin( MainSprite.getTextureRect().width / 2.0f, MainSprite.getTextureRect().height / 2.0f );
	MainSprite.setScale(1,1);
	MainSprite.setPosition(Pos);
}

void Mushroom::Initialize(sf::Vector2f p, MushroomField* theField)
{
	health = 0;
	Pos = p;
	infected = false;
	field = theField;

	X = (Pos.x / 16);
	Y = (Pos.y / 16);
	Y -= 1;
}

void Mushroom::Destroy()
{
	DeregisterCollision<Mushroom>(*this);

	if(Pos.y >= 408)
		field->AddToMushroomInPlayerArea(-1);

	field->SetElement(X, Y, NULL);
}

void Mushroom::Update()
{
	MainSprite.Update();
	chooseMainSprite();
	MainSprite.setPosition(Pos);
}

void Mushroom::Draw()
{
	WindowManager::MainWindow.draw(MainSprite);
}

void Mushroom::chooseMainSprite()
{
	if (infected)
	{
		if(health < 8)
		{
			MainSprite.SetFrame(health);
		}
	}
	else
	{
		if(health < 4)
		{
			MainSprite.SetFrame(health);
		}
	}
}

void Mushroom::regenMushroomHealth(int i, int j, int boardSize)
{
	if(health > 0)
	{
		health = 0;
		Heal();
		ExplosionMushroomFactory::CreateExplosionMushroom(sf::Vector2f(HalfSpriteSize + (SpriteSize*i), 24 + (SpriteSize*j)), "Death", i, j, boardSize);
	}
	else
	{
		if(j < boardSize)
			j++;
		else
		{
			i++;//reset the array/column that you will be iterating through
			j = 0;
		}
		LevelManager::GetMushroomField()->RepairMushrooms(i, j);
	}
}

int Mushroom::getHealth()
{
	return health;
}

sf::Vector2f Mushroom::getPosition()
{
	return Pos;
}

void Mushroom::Infect()
{
	health = 4;
	infected = true;
}

void Mushroom::Heal()
{
	infected = false;
}

void Mushroom::GotHit()
{
	health += 1;
	if (infected)
	{
		if(health > 7)
		{
			ScoreManager::AddScore(1);
			field->DestructionOfAMushroom(X, Y);
			MarkForDestroy();
		}
	}
	else
	{
		if(health > 3)
		{
			ScoreManager::AddScore(1);
			field->DestructionOfAMushroom(X, Y);
			MarkForDestroy();
		}
	}
}

bool Mushroom::isInfected()
{
	return infected;
}