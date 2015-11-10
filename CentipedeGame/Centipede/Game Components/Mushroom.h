#ifndef _Mushroom
#define _Mushroom

#include "TEAL\CommonElements.h"
class MushroomField;

class Bullet;

class Mushroom : public GameObject
{
public:
	Mushroom(sf::Vector2f p);

	void Initialize(sf::Vector2f p, MushroomField* theField);

	virtual void Update();
	virtual void Draw();
	virtual void Destroy();

	void regenMushroomHealth(int i, int j, int boardSize);
	void Infect();
	void Heal();
	void GotHit();
	bool isInfected();
	int getHealth();

	sf::Vector2f getPosition();

private:
	MushroomField* field;
	sf::Vector2f Pos;
	AnimatedSprite MainSprite;
	CollisionTools::TextureBitmap bitmap;

	int health, X, Y;

	bool infected;

	void chooseMainSprite();
};
#endif _Mushroom