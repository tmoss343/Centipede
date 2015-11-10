#ifndef _EnemyFactory
#define _EnemyFactory

#include <stack>

template <typename T>
class EnemyFactory
{
private:
	static std::stack<<T>*> recycledItems;

public:
	EnemyFactory();
	~EnemyFactory();

	static <T>* CreateObject(sf::Vector2f pos);

	static void RecycleObject(GameObject* b);
};


#endif _EnemyFactory