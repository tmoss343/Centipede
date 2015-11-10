#include "GeneralIncludes.h"

std::stack<ExplosionPlayer*> ExplosionPlayerFactory::recycledItems;

ExplosionPlayerFactory::ExplosionPlayerFactory()
{
}

ExplosionPlayer* ExplosionPlayerFactory::CreateExplosionPlayer(sf::Vector2f pos, std::string texture, Blaster* theBlaster)
{
	ExplosionPlayer* e;

	if ( recycledItems.empty() )
	{
		e = new ExplosionPlayer();


		e->SetExternalManagement( RecycleExplosionPlayer );
	}
	else
	{
		e = recycledItems.top();
		recycledItems.pop();	


		e->RegisterToCurrentScene();  
	}
	e->Initialize(pos, texture, theBlaster);

	return e;
}

void ExplosionPlayerFactory::RecycleExplosionPlayer(GameObject* b)
{
	recycledItems.push( (ExplosionPlayer*) b);
}

ExplosionPlayerFactory::~ExplosionPlayerFactory()
{
	while ( ! recycledItems.empty() ) 
	{
		delete recycledItems.top();
		recycledItems.pop();
	}
}