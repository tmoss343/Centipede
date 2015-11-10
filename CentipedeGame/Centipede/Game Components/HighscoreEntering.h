#ifndef _HighscoreEntering
#define _HighscoreEntering

#include "TEAL/CommonElements.h"
#include <list>
#include "CentipedeFont.h"

class HighscoreEntering : public GameObject
{
public:
	HighscoreEntering();
	virtual void TextEntered(sf::Uint32 UnicodeValue);
	virtual void Draw();
	virtual void Destroy();

private:
	CentipedeFont myfont;
	std::list<Glyph> symbols;
	std::string name;
	sf::Vector2f nextpos;
	int nameLen;
	int maxLen;
};


#endif _HighscoreEntering