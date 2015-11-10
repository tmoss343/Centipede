#ifndef _ExplosionMushroomFactory
#define _ExplosionMushroomFactory

#include <stack>
#include "TEAL\CommonElements.h"
class ExplosionMushroom;

class ExplosionMushroomFactory
{
private:
	static std::stack<ExplosionMushroom*> recycledItems;

public:
	ExplosionMushroomFactory();
	~ExplosionMushroomFactory();


	static ExplosionMushroom* CreateExplosionMushroom(sf::Vector2f pos, std::string texture, int i, int j, int size);

	static void RecycleExplosionMushroom(GameObject* b);
};


#endif _ExplosionMushroomFactory