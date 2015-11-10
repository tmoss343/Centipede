#ifndef _CentipedeFont
#define _CentipedeFont

#include "SpriteSheet.h"

class CentipedeFont : public SpriteSheet
{
public:
	CentipedeFont();

private:
	virtual int CharToIndex( char& c ); 
};


#endif _CentipedeFont