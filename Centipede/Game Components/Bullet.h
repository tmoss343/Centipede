#ifndef _Bullet
#define _Bullet

#include "TEAL\CommonElements.h"
#include "Enums.h"
class Mushroom;
class Blaster;
class CentipedeBodyPart;
class Scorpion;
class Spider;
class Flea;

class Bullet : public GameObject
{
public:
	Bullet(sf::Vector2f p, Blaster* theParent);

	void Initialize(sf::Vector2f p); 

	virtual void Update();
	virtual void Draw();
	virtual void Destroy();

	virtual void Collision( GameObject *go){};
	void Collision( CentipedeBodyPart *other );
	void Collision( Scorpion *other );
	void Collision( Spider *other );
	void Collision( Flea *other );

	void setStateToFire();
	void setStateToHolstered();
	void callToDestroy();

private:

	void CheckIfMusrhoom(int X, int Y);
	void CheckIfGlyph(int X, int Y);
	void Move();
	
	sf::Vector2f Pos;

	Blaster* parent;

	Enumerators::bulletMode currentState;

	float SPEED, distanceToNextLookAhead;

	AnimatedSprite MainSprite;
	CollisionTools::TextureBitmap bitmap;
	
};

#endif _Bullet