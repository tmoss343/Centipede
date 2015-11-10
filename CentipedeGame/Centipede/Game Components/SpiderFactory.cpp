#include "TEAL\CommonElements.h"
#include "GeneralIncludes.h"
std::stack<Spider*> SpiderFactory::recycledItems;

SpiderFactory::SpiderFactory()
{
}

Spider* SpiderFactory::CreateSpider(std::string texture, MushroomField* theField, sf::Vector2f pos, int frameWidth, int frameHeight, int moveDirection)
{
	Spider* e;

	if ( recycledItems.empty() )
	{
		e = new Spider(texture, theField, frameWidth, frameHeight);


		e->SetExternalManagement( RecycleSpider );
	}
	else
	{
		e = recycledItems.top();
		recycledItems.pop();	


		e->RegisterToCurrentScene();  
	}
	e->Initialize(pos, moveDirection);

	return e;
}

void SpiderFactory::RecycleSpider(GameObject* b)
{
	recycledItems.push( (Spider*) b);
}

SpiderFactory::~SpiderFactory()
{
	while ( ! recycledItems.empty() ) 
	{
		delete recycledItems.top();
		recycledItems.pop();
	}
}