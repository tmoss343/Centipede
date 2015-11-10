#include "GeneralIncludes.h"

Centipede::Centipede(	MushroomField* field, int size, int speed, float xPos )
{
	mushroomField = field;
	centipedeSize = 0;
	centipedeOffset = sf::Vector2f(xPos,  -24.0f);
	head = true;
	while(centipedeSize < size)
	{
		lastBodyPartBuilt = CentipedeBodyPartFactory::CreateCentipedeBodyPart(mushroomField, centipedeOffset, this, centipedeSize, speed);
		
		if(!head)
		{
			lastBodyPartBuilt->setAncestor(previous);
			previous->setDescendant(lastBodyPartBuilt);
		}

		previous = lastBodyPartBuilt;

		if(head)
			head = false;
		bodyPartsAlive.push_back(lastBodyPartBuilt);
		centipedeSize++;
	}
	centipedeSize = size;
}

Centipede::~Centipede()
{
	//if(mushroomField)
		//delete mushroomField;
}

void Centipede::EmptyCentipede()
{
	while(!bodyPartsAlive.empty())
	{
		lastBodyPartBuilt = bodyPartsAlive.front();
		GetLastBodyPartBuilt()->MarkForDestroy();
		bodyPartsAlive.pop_front();
	}
}

CentipedeBodyPart* Centipede::GetLastBodyPartBuilt()
{
	return lastBodyPartBuilt;
}
