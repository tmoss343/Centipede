#ifndef _BulletFactory
#define _BulletFactory

#include <stack>
class Bullet;
class Blaster;

class BulletFactory
{
private:
	static std::stack<Bullet*> recycledItems;

public:
	BulletFactory();
	~BulletFactory();


	static void CreateBullet(sf::Vector2f pos, Blaster* parent);

	static void RecycleBullet(GameObject* b);  // Arguments must be GameObject since it will be called by the base class
};


#endif _BulletFactory