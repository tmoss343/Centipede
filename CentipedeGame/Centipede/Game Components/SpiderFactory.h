#ifndef _SpiderFactory
#define _SpiderFactory

#include <stack>
class Spider;
class MushroomField;

class SpiderFactory
{
private:
	static std::stack<Spider*> recycledItems;

public:
	SpiderFactory();
	~SpiderFactory();


	static Spider* CreateSpider(std::string texture, MushroomField* theField, sf::Vector2f pos, int frameWidth, int frameHeight, int moveDirection);

	static void RecycleSpider(GameObject* b);
};


#endif _SpiderFactory