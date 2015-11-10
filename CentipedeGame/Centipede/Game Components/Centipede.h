#ifndef _Centipede
#define _Centipede

#include "TEAL\CommonElements.h"
#include <list>
class CentipedeBodyPart;
class MushroomField;

class Centipede
{
public:
	Centipede(	MushroomField* field , int size, int speed, float xPos);

	~Centipede();
	void EmptyCentipede();

	CentipedeBodyPart* GetLastBodyPartBuilt();

private:
	MushroomField* mushroomField;
	CentipedeBodyPart* lastBodyPartBuilt;
	std::list<CentipedeBodyPart*> bodyPartsAlive;
	
	sf::Vector2f centipedeOffset;
	CentipedeBodyPart* previous;
	int centipedeSize;
	bool head;

};
#endif _Centipede