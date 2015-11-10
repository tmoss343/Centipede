#include "GeneralIncludes.h"

std::stack<Explosion*> ExplosionFactory::recycledItems;

ExplosionFactory::ExplosionFactory()
{
}

Explosion* ExplosionFactory::CreateExplosion(sf::Vector2f pos, std::string texture)
{
	Explosion* e;

	if ( recycledItems.empty() )
	{
		e = new Explosion();


		e->SetExternalManagement( RecycleExplosion );
	}
	else
	{
		e = recycledItems.top();
		recycledItems.pop();	


		e->RegisterToCurrentScene();  
	}
	e->Initialize(pos, texture);

	return e;
}

void ExplosionFactory::RecycleExplosion(GameObject* b)
{
	recycledItems.push( (Explosion*) b);
}

ExplosionFactory::~ExplosionFactory()
{
	while ( ! recycledItems.empty() ) 
	{
		delete recycledItems.top();
		recycledItems.pop();
	}
}