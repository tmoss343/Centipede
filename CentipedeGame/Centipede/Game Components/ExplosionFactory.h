#ifndef _ExplosionFactory
#define _ExplosionFactory

#include <stack>
class Explosion;

class ExplosionFactory
{
private:
	static std::stack<Explosion*> recycledItems;

public:
	ExplosionFactory();
	~ExplosionFactory();


	static Explosion* CreateExplosion(sf::Vector2f pos, std::string texture);

	static void RecycleExplosion(GameObject* b);
};


#endif _ExplosionFactory