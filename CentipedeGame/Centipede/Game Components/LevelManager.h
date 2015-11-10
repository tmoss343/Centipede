#ifndef _LevelManager
#define _LevelManager

#include "TEAL\CommonElements.h"
class Level;
class MushroomField;
class Blaster;
class HighscoreEntering;

class LevelManager
{
public:
	static void SwtichActiveLevel();
	static void EndDueToDeath();
	static void NextWave();
	static void GameOver();
	static void PostGameOverCheck();

	static void AttractorMode();
	static void OnePlayerMode();
	static void TwoPlayerMode();

	static Level* GetActiveLevel();
	static MushroomField* GetMushroomField();
	static Blaster* GetBlaster();

	static bool Player1Active();
	static bool IsMultiPlayer();
	static bool IsPlayerControlled();

	static bool IsLevelTypeSwitchInProgress();
	static void SetLevelTypeSwtich(bool what);

private:
	static LevelManager* instance;									// set up as a singleton
	LevelManager();									// Private constructor 
	LevelManager( const LevelManager&);				// Prevent copy-construction
	LevelManager& operator=(const LevelManager&);	// Prevent assignment

	static LevelManager& Instance()					// Access reference (all public methods will be static)
	{
		if (! instance) 
			instance = new LevelManager;
		return *instance;
	};

	void SetActiveLevel(Level* toActivate);
	void ConstructMushroomField();
	void DestructMushroomField();

	Level* activeLevel;
	Level* player1Level;
	Level* player2Level;
	Level* attractorMode;
	Blaster* theBlaster;
	MushroomField* theMushroomField;
	HighscoreEntering* enterHighscoreObj;

	bool isMultiPlayer;
	bool player1Active;
	bool isPlayerControlled;
	bool levelTypeSwitchInProgress;
};

#endif _LevelManager