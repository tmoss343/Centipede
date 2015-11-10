#ifndef _ExplosionPlayer
#define _ExplosionPlayer

#include "TEAL\CommonElements.h"
class Player;
class Blaster;

class ExplosionPlayer : public GameObject
{
public:
	ExplosionPlayer();
	virtual void Update();
	virtual void Draw();
	virtual void Destroy();

	virtual void Alarm0();

	void Initialize( sf::Vector2f pos, std::string texture, Blaster* theBlaster );

private:
	AnimatedSprite MainSprite;

	sf::Vector2f Pos;
	float Speed;
	Player* player;
	Blaster* blaster;
};


#endif _Explosion