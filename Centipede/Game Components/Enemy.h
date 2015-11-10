#ifndef _Enemy
#define _Enemy

#include "TEAL\CommonElements.h"
class Bullet;
class MushroomField;

class Enemy : public GameObject
{
public:
	Enemy(std::string texture, MushroomField* theField, int horizantalDivisions, int verticalDivisions);

	sf::Vector2f GetPosition();

protected:
	MushroomField* field;
	float SPEED, adjustedSPEED;
	int health, scoreAddAmount;
	sf::Vector2f PosOfLastUpdate, Pos;

	AnimatedSprite MainSprite;
	CollisionTools::TextureBitmap bitmap;
private:
	std::string strTexture;
};

#endif _Enemy