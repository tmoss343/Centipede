#ifndef _Spider
#define _Spider

#include "Enemy.h"
class Bullet;
class Blaster;

class Spider : public Enemy
{
public:
	Spider(std::string texture, MushroomField* theField, int horizantalDivisions, int verticalDivisions);
	virtual void Update();
	virtual void Draw();
	virtual void Destroy();

	virtual void Collision( GameObject *other ){};
	void Collision( Bullet *other );


	void Initialize(sf::Vector2f pos, int moveDirection);

	void SetKiller(Blaster* killer);

private:
	Blaster* myKiller;
	float spiderWidth, spiderHeight, distnaceToNextLookAhead;
	bool diag; //Chooses whether to go strait diagonal
	int xMoveDir;
	
	void CheckIfMushroom();
	void CheckIfAtBounds();
	void Move();
};

#endif _Spider