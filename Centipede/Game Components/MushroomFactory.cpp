#include "TEAL\CommonElements.h"
#include "GeneralIncludes.h"

std::stack<Mushroom*> MushroomFactory::recycledItems;

MushroomFactory::MushroomFactory()
{
}

Mushroom* MushroomFactory::CreateMushroom(sf::Vector2f pos, MushroomField* field)
{
	Mushroom* m;

	if ( recycledItems.empty() )
	{
		m = new Mushroom(pos);

		m->SetExternalManagement( RecycleMushroom );
	}
	else
	{
		m = recycledItems.top();
		recycledItems.pop();	


		m->RegisterToCurrentScene();  
	}
	m->Initialize(pos, field);

	return m;
}

void MushroomFactory::RecycleMushroom(GameObject* m)
{
	recycledItems.push( (Mushroom*) m);
}

MushroomFactory::~MushroomFactory()
{
	while ( ! recycledItems.empty() ) 
	{
		delete recycledItems.top();
		recycledItems.pop();
	}
}