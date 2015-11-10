#ifndef _ExplosionMushroom
#define _ExplosionMushroom

#include "TEAL\CommonElements.h"

class ExplosionMushroom : public GameObject
{
public:
	ExplosionMushroom();
	virtual void Update();
	virtual void Draw();
	virtual void Destroy();

	void Initialize( sf::Vector2f pos, std::string texture, int i, int j, int size );

private:
	AnimatedSprite MainSprite;

	sf::Vector2f Pos;
	float Speed;
	int nextCol, nextRow, boardSize;
};


#endif _Explosion