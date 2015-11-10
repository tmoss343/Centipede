#ifndef _ScoreManager
#define _ScoreManager

#include "TEAL\CommonElements.h"

class HighscoreTable;

class ScoreManager
{
public:
	static void ResetScore();
	static void AddScore(int v);
	static void ReReadScore();
	static int setHighscore();
	static int GetScore();
	static int GetHighestScore();

	static bool PlayerGetsGameOver();//This will be a check to see if a highscore is overwritten
	static int PlayerHighscoreUpdatePos();
	static int GetHighscoreToUpdate();

private:
	static ScoreManager* instance;									// set up as a singleton
	ScoreManager();									// Private constructor 
	ScoreManager( const ScoreManager&);				// Prevent copy-construction
	ScoreManager& operator=(const ScoreManager&);	// Prevent assignment

	static ScoreManager& Instance()					// Access reference (all public methods will be static)
	{
		if (! instance) 
			instance = new ScoreManager;
		return *instance;
	};

	bool GameOver();

	int player1Score, player2Score, highscoreUpdatePos, highscoreToUpdate;
	HighscoreTable* highscoreInfo;
	bool player1;
};

#endif _GameController