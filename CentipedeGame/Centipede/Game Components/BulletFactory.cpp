#include "TEAL\CommonElements.h"
#include "GeneralIncludes.h"

std::stack<Bullet*> BulletFactory::recycledItems;

BulletFactory::BulletFactory()
{
}

void BulletFactory::CreateBullet(sf::Vector2f pos, Blaster* parent)
{
	Bullet* b;

	if ( recycledItems.empty() )
	{
		b = new Bullet(pos, parent);


		b->SetExternalManagement( RecycleBullet );
	}
	else
	{
		b = recycledItems.top();
		recycledItems.pop();	


		b->RegisterToCurrentScene();  
	}

	b->Initialize(pos);
	parent->setBullet(b);
}

void BulletFactory::RecycleBullet(GameObject* b)
{
	recycledItems.push( (Bullet*) b);
}

BulletFactory::~BulletFactory()
{
	while ( ! recycledItems.empty() ) 
	{
		delete recycledItems.top();
		recycledItems.pop();
	}
}