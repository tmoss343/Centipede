#ifndef _HUD
#define _HUD

#include "TEAL\CommonElements.h"
#include "CentipedeFont.h"
#include "BlasterGlyph.h"
#include "Glyph.h"
class HighscoreInformation;

class HUD : public GameObject
{
public:
	HUD();

	static void SetScore(int score, bool who);
	static void SetHighscore(int score);
	static void SetLives(int amount, bool who);
	static void SetUpHighscoresAttractorMode();
	static void DestructHighscoreAttractorMode();

	static void UpdateTheHighscoreFile(int score, std::string name);
	static bool IsInstanceOfGlyph(int i, int j);

private:
	static HUD* instance;									// set up as a singleton
	HUD( const HUD&);				// Prevent copy-construction
	HUD& operator=(const HUD&);	// Prevent assignment

	static HUD& Instance()					// Access reference (all public methods will be static)
	{
		if (! instance) 
			instance = new HUD;
		return *instance;
	};

	virtual void Update();
	virtual void Draw();

	BlasterGlyph BlasterFont;
  	CentipedeFont ScoreFont;
	std::list<Glyph> player1Symbols, player2Symbols, highscoreSymbols, playerLivesSymbols, attractorHighscoreInfoSymbols;
	std::string strScore;
	sf::Vector2f nextPos;
	HighscoreInformation* attractorHighscoreInfo;
	int player1ScoreLength, player2ScoreLength, highscoreLength, attractorHighscoreInfoLength;

	void DisplayScore(bool who);
	void DisplayHighscore();
	void DisplayHighscoresAttractorMode();

	void UpdateHighscoreFile(int score, std::string name);

	bool CheckIfAtGlyph(int col, int row);
};

#endif _HUD