#ifndef _PlayerControls
#define _PlayerControls

#include "BlasterControls.h"

class PlayerControls : public BlasterControls
{
public:
	PlayerControls(Blaster* myBlaster);

	void Update();
};

#endif _BlasterControls