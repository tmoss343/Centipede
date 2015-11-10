#include "GeneralIncludes.h"

HighscoreEntering::HighscoreEntering()
{
	maxLen = 3;
	nameLen = 0;
	
	RegisterInput( InputFlags::TextEntered );

	std::string text = "ENTER YOUR NAME  ";
	nextpos = sf::Vector2f(16*6, 512/2);
	
	for (int i=0; i < text.length(); i++)
	{
		symbols.push_back(  myfont.GetGlyph(text.at(i), nextpos) );
		nextpos.x += 16;
	}
}

void HighscoreEntering::TextEntered(sf::Uint32 UnicodeValue) 
{
	if(nameLen < 3)
	{
		symbols.push_back( myfont.GetGlyph( (char) UnicodeValue, nextpos ) );
		nextpos.x += 16;
		name += (char)UnicodeValue;
	}
	nameLen++;
	if(nameLen == 3)
	{
		HUD::UpdateTheHighscoreFile(ScoreManager::GetHighscoreToUpdate(), name);
		LevelManager::PostGameOverCheck();
		MarkForDestroy();
	}
}

void HighscoreEntering::Draw()
{
	std::list<Glyph>::iterator it;
	for (it = symbols.begin(); it != symbols.end(); it++)
		it->Draw();
}

void HighscoreEntering::Destroy()
{
	DeregisterInput();
}
