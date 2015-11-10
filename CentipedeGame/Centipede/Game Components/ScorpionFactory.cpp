#include "GeneralIncludes.h"

std::stack<Scorpion*> ScorpionFactory::recycledItems;

ScorpionFactory::ScorpionFactory()
{
}

Scorpion* ScorpionFactory::CreateScorpion(std::string texture, MushroomField* theField, sf::Vector2f pos, int frameWidth, int frameHeight, int moveDirection)
{
	Scorpion* e;

	if ( recycledItems.empty() )
	{
		e = new Scorpion(texture, theField, frameWidth, frameHeight);


		e->SetExternalManagement( RecycleScorpion );
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

void ScorpionFactory::RecycleScorpion(GameObject* b)
{
	recycledItems.push( (Scorpion*) b);
}

ScorpionFactory::~ScorpionFactory()
{
	while ( ! recycledItems.empty() ) 
	{
		delete recycledItems.top();
		recycledItems.pop();
	}
}