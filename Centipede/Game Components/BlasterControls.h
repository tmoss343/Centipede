#ifndef _BlasterControls
#define _BlasterControls

class Blaster;

class BlasterControls
{
public:
	BlasterControls(Blaster* blaster);

	virtual void Update() = 0;

protected:
	Blaster* myBlaster;
};

#endif _BlasterControls