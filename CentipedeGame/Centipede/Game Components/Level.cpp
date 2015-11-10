#include "GeneralIncludes.h"

Level::Level()
{
	field = new BoolField;
	thePlayer = new Player(this);
}

void Level::Intialize()
{
}

BoolField* Level::GetField()
{
	return field;
}

Player* Level::GetPlayer()
{
	return thePlayer;
}

void Level::ActivateLevel()
{
	GetPlayer()->ActivatePlayer();
	
	WaveManager::NextWave(this, GetPlayer()->GetWaveNum());
}

void Level::DeactivateLevel()
{
	WaveManager::DestoryCentipede();
	WaveManager::DestoryFlea();
	WaveManager::DestorySpider();
	WaveManager::DestoryScorpion();
}