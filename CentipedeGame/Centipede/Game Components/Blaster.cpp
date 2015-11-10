#include "GeneralIncludes.h"

Blaster::Blaster()
{
	MAXHEIGHT = 10;
	//
	bitmap = ResourceManager::GetTextureBitmap("Blaster");
	MainSprite = AnimatedSprite(ResourceManager::GetTexture("Blaster"), 1, 1);
	
	MainSprite.setOrigin( MainSprite.getTextureRect().width / 2.0f, MainSprite.getTextureRect().height / 2.0f);
	MainSprite.setScale(1,1);
	MainSprite.setPosition(Pos);

	RegisterInput( InputFlags::KeyPressed );

	xMoveDir = 1;
	yMoveDir = -1;

	bullet = NULL;
}

void Blaster::Initialize(bool playerControl)
{
	Pos = sf::Vector2f(WindowManager::MainWindow.getSize().x/2, 474);
	//
	SetCollider(MainSprite, bitmap, true);
	RegisterCollision<Blaster>(*this);
	//

	if(playerControl)
	{
		myControls = new PlayerControls(this);
		SPEED = 10;
	}
	else
	{
		myControls = new AIControls(this);
		SPEED = 2;
	}
	if(!bullet)
	{
		getNewBullet();
	}
}

void Blaster::Destroy()
{
	bullet->callToDestroy();

	DeregisterCollision<Blaster>(*this);
	ExplosionPlayerFactory::CreateExplosionPlayer(Pos, "PlayerExplosion", this);

	if(myControls)
	{
		delete myControls;
	}
}

void Blaster::Update()
{
	setPositionOfLastUpdate( getPosition() );
	MainSprite.Update();

	myControls->Update();
	
	Tools::Clamp<float>(Pos.x, (float) MainSprite.getTextureRect().width / 2, (float) WindowManager::MainWindow.getView().getSize().x - MainSprite.getTextureRect().width / 2);
	Tools::Clamp<float>(Pos.y, (float) 51*((MainSprite.getTextureRect().width) / 2), (float) WindowManager::MainWindow.getView().getSize().y - (MainSprite.getTextureRect().height / 2));		

 	MainSprite.setPosition(Pos);

}

void Blaster::Draw()
{
	WindowManager::MainWindow.draw(MainSprite);
}

void Blaster::UP()
{
	Pos += sf::Vector2f(0, -SPEED);
}

void Blaster::DOWN()
{
	Pos += sf::Vector2f(0, SPEED);
}

void Blaster::LEFT()
{
	Pos += sf::Vector2f(-SPEED, 0);
}

void Blaster::RIGHT()
{
	Pos += sf::Vector2f( SPEED, 0);
}

void Blaster::ShootBullet()
{
	bullet->setStateToFire();
	canFire = false;
}

void Blaster::Move()
{
	Pos.y += SPEED * yMoveDir;
	Pos.x += SPEED * xMoveDir;
}

void Blaster::CheckIfAtBounds()
{
	if(Pos.y - (MainSprite.getTextureRect().width) / 2 <= (51*(MainSprite.getTextureRect().width) / 2) ||
		Pos.y + (MainSprite.getTextureRect().width) / 2 >= WindowManager::MainWindow.getView().getSize().y)
	{
		yMoveDir *= -1;
	}

	if(Pos.x == WindowManager::MainWindow.getView().getSize().x - (MainSprite.getTextureRect().width) / 2 ||
		Pos.x == 0 + (MainSprite.getTextureRect().width) / 2)
	{
		xMoveDir *= -1;
	}
}

float Blaster::GetSpeed()
{
	return SPEED;
}

void Blaster::Collision(Mushroom *other)
{
	setPosition(PosOfLastUpdate);
}

void Blaster::Collision(CentipedeBodyPart *other)
{
	MarkForDestroy();
}

void Blaster::Collision(Spider *other)
{
	MarkForDestroy();
}

void Blaster::Collision(Flea *other)
{
	MarkForDestroy();
}

sf::Vector2f Blaster::getPosition()
{
	return Pos;
}

bool Blaster::CanFire()
{
	return canFire;
}

void Blaster::getNewBullet()
{
	BulletFactory::CreateBullet(sf::Vector2f(Pos.x, Pos.y - 5), this);
	bullet->setStateToHolstered();
	canFire = true;
}

void Blaster::setPosition(sf::Vector2f pos)
{
	Pos = pos;
}

void Blaster::setPositionOfLastUpdate(sf::Vector2f pos)
{
	PosOfLastUpdate = pos;
}

void Blaster::setBulletPointer(Bullet* theBullet)
{
	bullet = theBullet;
	CheckIfIHaveBullet();
}

void Blaster::setBullet(Bullet* curBullet)
{
	bullet = curBullet;
}

void Blaster::CheckIfIHaveBullet()
{
	if(!bullet)
	{
		getNewBullet();
	}
}