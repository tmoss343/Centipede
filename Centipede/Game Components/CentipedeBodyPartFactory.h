#ifndef _CentipedeBodyPartFactory
#define _CentipedeBodyPartFactory

#include <stack>
class CentipedeBodyPart;
class MushroomField;
class Centipede;

class CentipedeBodyPartFactory
{
private:
	static std::stack<CentipedeBodyPart*> recycledItems;

public:
	CentipedeBodyPartFactory();
	~CentipedeBodyPartFactory();


	static CentipedeBodyPart* CreateCentipedeBodyPart(MushroomField* mushroomField, sf::Vector2f pos, Centipede* creator, int buildNumber, int speed);

	static void RecycleCentipedeBodyPart(GameObject* b);
};


#endif _CentipedeBodyPartFactory