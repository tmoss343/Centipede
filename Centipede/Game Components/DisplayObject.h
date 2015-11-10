#ifndef _DisplayObject
#define _DisplayObject

#include "TEAL\CommonElements.h"

class DisplayObject : public GameObject
{
public:
	void SwitchActive();
	bool GetActive();
protected:
	bool active;
};

#endif _DisplayObject