#ifndef _Flea
#define _Flea

#include "Enemy.h"
class Bullet;

class Flea : public Enemy
{
public:
	Flea(std::string texture, MushroomField* theField, int horizantalDivisions, int verticalDivisions);
	virtual void Update();
	virtual void Draw();
	virtual void Destroy();

	virtual void Collision( GameObject *other ){};
	void Collision( Bullet *other );

	void Initialize(sf::Vector2f pos);

private:
	float fleaWidth, fleaHeight, distnaceToNextLookAhead;
	
	void CheckIfMushroom();
	void Move();
};

#endif _Scorpion