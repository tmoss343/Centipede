#ifndef _FleaFactory
#define _FleaFactory

#include <stack>
class Flea;
class MushroomField;

class FleaFactory
{
private:
	static std::stack<Flea*> recycledItems;

public:
	FleaFactory();
	~FleaFactory();


	static Flea* CreateFlea(std::string texture, MushroomField* theField, sf::Vector2f pos, int frameWidth, int frameHeight);

	static void RecycleFlea(GameObject* b);
};


#endif _FleaFactory