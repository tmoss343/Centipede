#include "ExplosionMushroomFactory.h"
#include "ExplosionMushroom.h"

std::stack<ExplosionMushroom*> ExplosionMushroomFactory::recycledItems;

ExplosionMushroomFactory::ExplosionMushroomFactory()
{
}

ExplosionMushroom* ExplosionMushroomFactory::CreateExplosionMushroom(sf::Vector2f pos, std::string texture, int i, int j, int size)
{
	ExplosionMushroom* e;

	if ( recycledItems.empty() )
	{
		e = new ExplosionMushroom();


		e->SetExternalManagement( RecycleExplosionMushroom );
	}
	else
	{
		e = recycledItems.top();
		recycledItems.pop();	


		e->RegisterToCurrentScene();  
	}
	e->Initialize(pos, texture, i, j, size);

	return e;
}

void ExplosionMushroomFactory::RecycleExplosionMushroom(GameObject* b)
{
	recycledItems.push( (ExplosionMushroom*) b);
}

ExplosionMushroomFactory::~ExplosionMushroomFactory()
{
	while ( ! recycledItems.empty() ) 
	{
		delete recycledItems.top();
		recycledItems.pop();
	}
}