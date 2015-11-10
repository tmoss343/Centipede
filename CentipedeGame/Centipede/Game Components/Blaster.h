#ifndef _Blaster
#define _Blaster

#include "DisplayObject.h"
class Mushroom;
class Bullet;
class Player;
class CentipedeBodyPart;
class Spider;
class Scorpion;
class Flea;
class BlasterControls;

class Blaster : public GameObject
{
public:
	Blaster();
	void Initialize(bool playerControl);

	virtual void Update();
	virtual void Draw();
	virtual void Destroy();
	
	virtual void Collision( GameObject *other ){};
	void Collision(Mushroom *other);
	void Collision(CentipedeBodyPart *other);
	void Collision(Spider *other);
	void Collision(Flea *other);

	void getNewBullet();
	void setBullet(Bullet* curBullet);
	void setPosition(sf::Vector2f pos);
	void setPositionOfLastUpdate(sf::Vector2f pos);
	void setBulletPointer(Bullet* theBullet);

	sf::Vector2f getPosition();
	bool CanFire();

	void UP();
	void DOWN();
	void LEFT();
	void RIGHT();
	void ShootBullet();
	//AI movements
	void CheckIfAtBounds();
	void Move();

	float GetSpeed();

private:
	void CheckIfIHaveBullet();
	int xMoveDir, yMoveDir;
	float SPEED;
	float MAXHEIGHT;

	bool canFire;

	Bullet* bullet;
	BlasterControls* myControls;
	sf::Vector2f PosOfLastUpdate, Pos;
	
	AnimatedSprite MainSprite;
	CollisionTools::TextureBitmap bitmap;

	sf::Sound FireSound;
};

#endif _Blaster