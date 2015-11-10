#ifndef _AIControls
#define _AIControls

#include "BlasterControls.h"

class AIControls : public BlasterControls
{
public:
	AIControls(Blaster* myBlaster);

	void Update();
private:
	float distnaceToNextLookAhead;
};

#endif _BlasterControls