#include "TEAL\CommonElements.h"
#include "GeneralIncludes.h"

std::stack<CentipedeBodyPart*> CentipedeBodyPartFactory::recycledItems;

CentipedeBodyPartFactory::CentipedeBodyPartFactory()
{
}

CentipedeBodyPart* CentipedeBodyPartFactory::CreateCentipedeBodyPart(MushroomField* mushroomField, sf::Vector2f pos, Centipede* theCreator, int buildNumber,  int speed)
{
	CentipedeBodyPart* c;

	if ( recycledItems.empty() )
	{
		c = new CentipedeBodyPart();


		c->SetExternalManagement( RecycleCentipedeBodyPart );
	}
	else
	{
		c = recycledItems.top();
		recycledItems.pop();	


		c->RegisterToCurrentScene();  
	}
	c->Initialize(mushroomField, pos, theCreator, speed, buildNumber);

	return c;
}

void CentipedeBodyPartFactory::RecycleCentipedeBodyPart(GameObject* b)
{
	recycledItems.push( (CentipedeBodyPart*) b);
}

CentipedeBodyPartFactory::~CentipedeBodyPartFactory()
{
	while ( ! recycledItems.empty() ) 
	{
		delete recycledItems.top();
		recycledItems.pop();
	}
}