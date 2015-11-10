#ifndef _Explosion
#define _Explosion

#include "TEAL\CommonElements.h"

class Explosion : public GameObject
{
public:
	Explosion();
	virtual void Update();
	virtual void Draw();

	void Initialize( sf::Vector2f pos, std::string texture );

private:
	AnimatedSprite MainSprite;

	sf::Vector2f Pos;
	float Speed;
};


#endif _Explosion