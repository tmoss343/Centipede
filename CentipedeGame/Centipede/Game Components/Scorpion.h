#ifndef _Scorpion
#define _Scorpion

#include "Enemy.h"
class Bullet;

class Scorpion : public Enemy
{
public:
	Scorpion(std::string texture, MushroomField* theField, int horizantalDivisions, int verticalDivisions);
	virtual void Update();
	virtual void Draw();
	virtual void Destroy();

	virtual void Collision( GameObject *other ){};
	void Collision( Bullet *other );

	void Initialize(sf::Vector2f pos, int moveDirection);

private:
	float scorpionWidth, scorpionHeight, distnaceToNextLookAhead;
	
	void CheckInfectMushroom();
	void Move();
};

#endif _Scorpion