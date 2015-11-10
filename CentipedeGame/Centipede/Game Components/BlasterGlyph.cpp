#include "GeneralIncludes.h"
#include "TEAL\ResourceManager.h"

BlasterGlyph::BlasterGlyph()
	: SpriteSheet( ResourceManager::GetTexture("Blaster"), 1, 1 )
{
	MainSprite.setScale(1, 1);
}

// Computing the magic value of the cellIndex for each char
int BlasterGlyph::CharToIndex( char& c )
{
	return 0;
}