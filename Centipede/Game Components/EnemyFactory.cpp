#include "TEAL\CommonElements.h"
#include "EnemyFactory.h"
#include "Mushroom.h"

template <typename T>
std::stack<T*> EnemyFactory::recycledItems;

template <typename T>
EnemyFactory::EnemyFactory()
{
}

template <typename T>
T* EnemyFactory::CreateMushroom(sf::Vector2f pos)
{
	T* e;

	if ( recycledItems.empty() )
	{
		e = new T(pos);

		e->SetExternalManagement( RecycleMushroom );
	}
	else
	{
		e = recycledItems.top();
		recycledItems.pop();	


		e->RegisterToCurrentScene();  
	}

	return e;
}

template <typename T>
void EnemyFactory::RecycleEnemy(GameObject* m)
{
	recycledItems.push( (T*) m);
}

template <typename T>
EnemyFactory::~EnemyFactory()
{
	while ( ! recycledItems.empty() ) 
	{
		delete recycledItems.top();
		recycledItems.pop();
	}
}