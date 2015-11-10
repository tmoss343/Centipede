#ifndef _ScorpionFactory
#define _ScorpionFactory

#include <stack>
class Scorpion;
class MushroomField;

class ScorpionFactory
{
private:
	static std::stack<Scorpion*> recycledItems;

public:
	ScorpionFactory();
	~ScorpionFactory();


	static Scorpion* CreateScorpion(std::string texture, MushroomField* theField, sf::Vector2f pos, int frameWidth, int frameHeight, int moveDirection);

	static void RecycleScorpion(GameObject* b);
};


#endif _ScorpionFactory