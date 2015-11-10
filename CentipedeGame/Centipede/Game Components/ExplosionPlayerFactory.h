#ifndef _ExplosionPlayerFactory
#define _ExplosionPlayerFactory

#include <stack>
class ExplosionPlayer;
class Player;

class ExplosionPlayerFactory
{
private:
	static std::stack<ExplosionPlayer*> recycledItems;

public:
	ExplosionPlayerFactory();
	~ExplosionPlayerFactory();


	static ExplosionPlayer* CreateExplosionPlayer(sf::Vector2f pos, std::string texture, Blaster* theBlaster);

	static void RecycleExplosionPlayer(GameObject* b);
};


#endif _ExplosionFactory