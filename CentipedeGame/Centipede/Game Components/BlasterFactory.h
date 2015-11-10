#ifndef _BlasterFactory
#define _BlasterFactory

#include <stack>
class Blaster;
class Player;

class BlasterFactory
{
private:
	static std::stack<Blaster*> recycledItems;

public:
	BlasterFactory();
	~BlasterFactory();


	static Blaster* CreateBlaster(bool isPlayer);

	static void RecycleBlaster(GameObject* b);
};


#endif _BlasterFactory