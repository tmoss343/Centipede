#include "TEAL\CommonElements.h"
#include "GeneralIncludes.h"

std::stack<Blaster*> BlasterFactory::recycledItems;

BlasterFactory::BlasterFactory()
{
}

Blaster* BlasterFactory::CreateBlaster(bool isPlayer)
{
	Blaster* b;

	if ( recycledItems.empty() )
	{
		b = new Blaster();

		b->SetExternalManagement( RecycleBlaster );
	}
	else
	{
		b = recycledItems.top();
		recycledItems.pop();	


		b->RegisterToCurrentScene();  
	}
	b->Initialize(isPlayer);

	return b;
}

void BlasterFactory::RecycleBlaster(GameObject* b)
{
	recycledItems.push( (Blaster*) b);
}

BlasterFactory::~BlasterFactory()
{
	while ( ! recycledItems.empty() ) 
	{
		delete recycledItems.top();
		recycledItems.pop();
	}
}