#include "GeneralIncludes.h"

Spider::Spider(std::string texture, MushroomField* theField, int horizantalDivisions, int verticalDivisions)
	: Enemy(texture, theField, horizantalDivisions, verticalDivisions)
{
	//Individual Sprite information
	MainSprite.setScale(2, 2);
	MainSprite.setOrigin( MainSprite.getTextureRect().width / 2.0f, MainSprite.getTextureRect().height / 2.0f);
	
	MainSprite.setPosition(Pos);

	spiderWidth = MainSprite.getTextureRect().width;
	spiderHeight = MainSprite.getTextureRect().height;

	SetCollider(MainSprite, bitmap, true);
	RegisterCollision<Spider>(*this);
	//Set animation and rotation for movement
	MainSprite.SetAnimation(0, 3);


}

void Spider::Initialize(sf::Vector2f pos, int moveDirection)
{
	Pos = pos;
	xMoveDir = moveDirection;
	SPEED = 2.0f;
	adjustedSPEED = 0 - SPEED;//Move down to start
	distnaceToNextLookAhead = -1;
	health = 1;
	SoundManager::StartSpiderLoop();
	RegisterCollision<Spider>(*this);
}

void Spider::Update()
{
	if(distnaceToNextLookAhead < 0)
	{
		CheckIfMushroom();
		CheckIfAtBounds();
		MainSprite.Update();
	}
	distnaceToNextLookAhead -= SPEED;
	Move();

	MainSprite.setPosition(Pos);
}

void Spider::Draw()
{
	WindowManager::MainWindow.draw(MainSprite);
}

void Spider::Destroy()
{
	DeregisterCollision<Spider>(*this);
	SoundManager::StopSpiderLoop();
	SoundManager::PlayKillSound();
}

void Spider::Collision(Bullet* other)
{
	health--;
	if(health < 1)
	{
		MarkForDestroy();
		WaveManager::ResetAlarmForSpider();

		if(myKiller->getPosition().x - Pos.y < 3)
		{
			scoreAddAmount = 900;
			ExplosionSpiderFactory::CreateExplosionSpider(Pos, "900");
		}
		else if(myKiller->getPosition().x - Pos.y < 24)
		{
			scoreAddAmount = 600;
			ExplosionSpiderFactory::CreateExplosionSpider(Pos, "600");
		}
		else
		{
			scoreAddAmount = 300;
			ExplosionSpiderFactory::CreateExplosionSpider(Pos, "300");
		}
		ScoreManager::AddScore(scoreAddAmount);
	}
}

void Spider::Move()
{
	if(diag)
	{
		Pos.y += adjustedSPEED;
		Pos.x += SPEED * xMoveDir;
	}
	else
	{
		Pos.y += adjustedSPEED;
	}
}

//Checks current POS and if there is a shroom if so destroy it
void Spider::CheckIfMushroom()
{
	int X = (Pos.x / 16);
	int Y = (Pos.y / 16) - 1;

	if(field->isInstance(X, Y) && X >=0 && X <= 29)//Can only eat mushrooms within the field
		field->getElement(X, Y)->MarkForDestroy();
	if(X < -1 || X > 30)
	{
		WaveManager::ResetAlarmForSpider();
		MarkForDestroy();
	}

	diag = rand() % 2;

	distnaceToNextLookAhead = SpriteSize;
}

void Spider::CheckIfAtBounds()
{
	if(Pos.y - spiderHeight <= (51*spiderHeight) ||
		Pos.y + spiderHeight >= WindowManager::MainWindow.getView().getSize().y)
	{
		adjustedSPEED *= -1;
	}
}

void Spider::SetKiller(Blaster* killer)
{
	myKiller = killer;
}
