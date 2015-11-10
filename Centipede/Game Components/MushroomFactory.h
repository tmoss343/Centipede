#ifndef _MushroomFactory
#define _MushroomFactory

#include <stack>
class Mushroom;
class MushroomField;

class MushroomFactory
{
private:
	static std::stack<Mushroom*> recycledItems;

public:
	MushroomFactory();
	~MushroomFactory();


	static Mushroom* CreateMushroom(sf::Vector2f pos, MushroomField* field);

	static void RecycleMushroom(GameObject* b);
};


#endif _MushroomFactory