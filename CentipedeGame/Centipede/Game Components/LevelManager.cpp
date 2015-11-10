#include "GeneralIncludes.h"

LevelManager* LevelManager::instance;	

LevelManager::LevelManager()
{
	theMushroomField = new MushroomField;
}

void LevelManager::SwtichActiveLevel()
{
	if(Instance().isMultiPlayer)
	{
		if(Instance().activeLevel == Instance().player1Level)
		{
			Instance().player1Active = false;
			Instance().SetActiveLevel(Instance().player2Level);
		}
		else
		{
			Instance().player1Active = true;
			Instance().SetActiveLevel(Instance().player1Level);
		}
	}
	else 
	{
		Instance().SetActiveLevel(Instance().activeLevel);
	}
	BlasterFactory::CreateBlaster(LevelManager::IsPlayerControlled());
}

void LevelManager::EndDueToDeath()
{
	Instance().activeLevel->DeactivateLevel();
	Instance().GetMushroomField()->RepairMushrooms(0, 0);
}

void LevelManager::NextWave()
{
	Instance().activeLevel->GetPlayer()->NextWave();
	Instance().activeLevel->DeactivateLevel();
	Instance().activeLevel->ActivateLevel();
	//Instance().SetActiveLevel(Instance().activeLevel);
}

void LevelManager::GameOver()
{
	Instance().activeLevel->DeactivateLevel();
	Instance().DestructMushroomField();
	if(ScoreManager::PlayerGetsGameOver())
	{
		Instance().enterHighscoreObj = new HighscoreEntering();
	}
	else
	{
		LevelManager::PostGameOverCheck();
	}
}

void LevelManager::PostGameOverCheck()
{
	Instance().theBlaster->MarkForDestroy();
	if(Instance().isMultiPlayer && (Instance().player1Level->GetPlayer()->GetLives() > 0 || Instance().player2Level->GetPlayer()->GetLives() > 0))
	{
		Instance().SwtichActiveLevel();
	}
	else
		Instance().AttractorMode();
}

Level* LevelManager::GetActiveLevel()
{
	return Instance().activeLevel;
}

MushroomField* LevelManager::GetMushroomField()
{
	return Instance().theMushroomField;
}

Blaster* LevelManager::GetBlaster()
{
	return Instance().theBlaster;
}

void LevelManager::AttractorMode()
{
	SoundManager::Mute();
	HUD::SetHighscore(ScoreManager::GetHighestScore());
	HUD::SetUpHighscoresAttractorMode();
	ScoreManager::ResetScore();

	Instance().attractorMode = new Level();
	Instance().isMultiPlayer = false;
	Instance().player1Active = true;

	Instance().SetActiveLevel(Instance().attractorMode);
	Instance().isPlayerControlled = false;
	Instance().theBlaster = BlasterFactory::CreateBlaster(Instance().isPlayerControlled);
}

void LevelManager::TwoPlayerMode()
{
	//SoundManager::ToggleMute();
	ScoreManager::ResetScore();

	HUD::DestructHighscoreAttractorMode();

	Instance().player1Level = new Level();

	Instance().player2Level = new Level();
	Instance().player2Level->DeactivateLevel();

	Instance().isMultiPlayer = true;
	Instance().player1Active = true;

	Instance().SetActiveLevel(Instance().player1Level);
	Instance().isPlayerControlled = true;
	Instance().theBlaster->Initialize(true);
}

void LevelManager::OnePlayerMode()
{
	//SoundManager::ToggleMute();
	ScoreManager::ResetScore();

	HUD::DestructHighscoreAttractorMode();

	Instance().player1Level = new Level();
	Instance().isMultiPlayer = false;
	Instance().player1Active = true;

	Instance().SetActiveLevel(Instance().player1Level);
	Instance().isPlayerControlled = true;
	Instance().theBlaster->Initialize(true);
}

void LevelManager::SetActiveLevel(Level* toActivate)
{
	Instance().activeLevel->DeactivateLevel();
	Instance().DestructMushroomField();
	Instance().activeLevel = toActivate;
	Instance().ConstructMushroomField();
	Instance().activeLevel->ActivateLevel();
}

void LevelManager::ConstructMushroomField()
{
	theMushroomField->Initialize(activeLevel->GetField());
}

void LevelManager::DestructMushroomField()
{
	theMushroomField->Destruct();
}

bool LevelManager::Player1Active()
{
	return Instance().player1Active;
}

bool LevelManager::IsMultiPlayer()
{
	return Instance().isMultiPlayer;
}

bool LevelManager::IsPlayerControlled()
{
	return Instance().isPlayerControlled;
}

bool LevelManager::IsLevelTypeSwitchInProgress()
{
	return Instance().levelTypeSwitchInProgress;
}

void LevelManager::SetLevelTypeSwtich(bool what)
{
	Instance().levelTypeSwitchInProgress = what;
}