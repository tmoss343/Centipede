#ifndef _ExplosionSpider
#define _ExplosionSpider

#include "TEAL\CommonElements.h"

class ExplosionSpider : public GameObject
{
public:
	ExplosionSpider();
	virtual void Update();
	virtual void Draw();

	void Initialize( sf::Vector2f pos, std::string texture );

	virtual void Alarm0();

private:
	AnimatedSprite MainSprite;

	sf::Vector2f Pos;
	float Speed;
};


#endif _ExplosionSpider