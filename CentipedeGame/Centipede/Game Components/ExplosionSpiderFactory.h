#ifndef _ExplosionSpiderFactory
#define _ExplosionSpiderFactory

#include <stack>
class ExplosionSpider;

class ExplosionSpiderFactory
{
private:
	static std::stack<ExplosionSpider*> recycledItems;

public:
	ExplosionSpiderFactory();
	~ExplosionSpiderFactory();


	static ExplosionSpider* CreateExplosionSpider(sf::Vector2f pos, std::string texture);

	static void RecycleExplosionSpider(GameObject* b);
};


#endif _ExplosionSpiderFactory