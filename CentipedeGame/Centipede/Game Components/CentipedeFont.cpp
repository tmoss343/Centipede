#include "GeneralIncludes.h"
#include "TEAL\ResourceManager.h"

CentipedeFont::CentipedeFont()
	: SpriteSheet( ResourceManager::GetTexture("CentipedeFont"), 16, 3 )
{
	MainSprite.setScale(2, 2);
}

// Computing the magic value of the cellIndex for each char
int CentipedeFont::CharToIndex( char& c )
{
	int cellIndex = 0;

	if ( c >= '0' && c <= '9')
		cellIndex = (int) c - (int) '0';	
	else if ( c >= 'A' && c <= 'Z')
		cellIndex = (int) c - (int) 'A' + 17;
	else
		switch (c)
		{
		case ' ':	// Space
			cellIndex = 16;
			break;
		case ':':	// Colon
			cellIndex = 10;
			break;
		case '/':	// Half
			cellIndex = 11;
			break;
		case '[':	// Copyright
			cellIndex = 12;
			break;
		case ']':	// Publisher
			cellIndex = 14;
			break;
		default:
			cellIndex = 0;
		}

	return cellIndex;
}