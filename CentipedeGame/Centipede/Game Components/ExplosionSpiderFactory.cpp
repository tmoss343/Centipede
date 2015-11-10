#include "ExplosionSpider.h"
#include "ExplosionSpiderFactory.h"

std::stack<ExplosionSpider*> ExplosionSpiderFactory::recycledItems;

ExplosionSpiderFactory::ExplosionSpiderFactory()
{
}

ExplosionSpider* ExplosionSpiderFactory::CreateExplosionSpider(sf::Vector2f pos, std::string texture)
{
	ExplosionSpider* e;

	if ( recycledItems.empty() )
	{
		e = new ExplosionSpider();


		e->SetExternalManagement( RecycleExplosionSpider );
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

void ExplosionSpiderFactory::RecycleExplosionSpider(GameObject* b)
{
	recycledItems.push( (ExplosionSpider*) b);
}

ExplosionSpiderFactory::~ExplosionSpiderFactory()
{
	while ( ! recycledItems.empty() ) 
	{
		delete recycledItems.top();
		recycledItems.pop();
	}
}