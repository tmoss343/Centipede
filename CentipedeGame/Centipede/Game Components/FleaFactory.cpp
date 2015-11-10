#include "GeneralIncludes.h"

std::stack<Flea*> FleaFactory::recycledItems;

FleaFactory::FleaFactory()
{
}

Flea* FleaFactory::CreateFlea(std::string texture, MushroomField* theField, sf::Vector2f pos, int frameWidth, int frameHeight)
{
	Flea* f;
	if ( recycledItems.empty() )
	{
		f = new Flea(texture, theField, frameWidth, frameHeight);


		f->SetExternalManagement( RecycleFlea );
	}
	else
	{
		f = recycledItems.top();
		recycledItems.pop();	


		f->RegisterToCurrentScene();  
	}
	f->Initialize(pos);
	return f;
}

void FleaFactory::RecycleFlea(GameObject* b)
{
	recycledItems.push( (Flea*) b);
}

FleaFactory::~FleaFactory()
{
	while ( ! recycledItems.empty() ) 
	{
		delete recycledItems.top();
		recycledItems.pop();
	}
}