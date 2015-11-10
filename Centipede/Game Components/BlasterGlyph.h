#ifndef _BlasterGlyph
#define _BlasterGlyph

#include "SpriteSheet.h"

class BlasterGlyph : public SpriteSheet
{
public:
	BlasterGlyph();

private:
	virtual int CharToIndex( char& c ); 
};


#endif _BlasterGlyph