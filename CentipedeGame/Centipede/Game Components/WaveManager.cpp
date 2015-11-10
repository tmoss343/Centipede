#include "GeneralIncludes.h"

WaveManager* WaveManager::instance;

WaveManager::WaveManager()
{
	waveSpider = NULL;
	waveScorpion = NULL;
	waveFlea = NULL;
	centipedeTotalSize;
	waveInfo = new WaveInformation;
	FileReader::OpenFile("resources/WaveInfo.txt", waveInfo);
}

WaveInformation* WaveManager::GetWaveInformatioin()
{
	return Instance().waveInfo;
}

int WaveManager::GetTotalWaves()
{
	return Instance().waveInfo->totalWaves;
}

int WaveManager::GetCurrentWave()
{
	return Instance().currentWave;
}

void WaveManager::NextWave(Level* level, int waveNumber)
{
	Instance().centipedeTotalSize = 0;
	Instance().currentWave = waveNumber;

	ResetAlarmForFlea();
	ResetAlarmForScorpion();
	ResetAlarmForSpider();
	
	int tmpCentipedeNum = Instance().waveInfo->numberOfCentipedes[Instance().currentWave];//Gives the total to a tmp variable so you can spawn the centipedes with the WaveInfo counter since it has the scope of wave manager

	while(Instance().waveInfo->numberOfCentipedes[Instance().currentWave] > 0)
	{
		SpawnCentipede(level);
		Instance().waveInfo->numberOfCentipedes[Instance().currentWave]--;
	}

	Instance().waveInfo->numberOfCentipedes[Instance().currentWave] = tmpCentipedeNum;//Reseting the number of cetipedes back to the full value incase you die and have to restart the wave
}

/*
For all info on how the scorpion is spawned on the field look here:
When a scorpion dies a timer starts between X and Y seconds for another scorpion to spawn.
*/
Scorpion* WaveManager::SpawnScorpion( std::string texture )
{ 
	int frameWidth = 4;
	int frameHeight = 1;
	int spawnSide = rand() % 2;
	int yPos = rand() % 24 + 1;
	
	sf::Vector2f pos;
	int moveDirection;

	if(spawnSide == 1)
	{
		pos = sf::Vector2f(-HalfSpriteSize, ((yPos) * 16) + 8.0f);//Posision the y position in a grid coodiante outside player area and the x off the screen moving right
		moveDirection = 1;
	}
	else
	{
		pos = sf::Vector2f(WindowManager::MainWindow.getView().getSize().x + HalfSpriteSize, ((yPos) * 16) + HalfSpriteSize);//Posision the y position in a grid coodiante outside player area and the x off the screen moving left
		moveDirection = -1;
	}
	return ScorpionFactory::CreateScorpion(texture, LevelManager::GetMushroomField(), pos, frameWidth, frameHeight, moveDirection);
}
/*
For all info on how the flea is spawned on the field look here:
The flea will spawn only when there is no other flea on the field no matter the case. 
if a mushroom is destroyed and there are less than X mushrooms in the player area then a flea will spawn.
if  there are less than 3 mushroom in the field and the timer on the alarm event has gone off.
*/
Flea* WaveManager::SpawnFlea( std::string texture )
{
	int frameWidth = 2;
	int frameHeight = 2;
	int xPos = rand() % 29 + 1;
	sf::Vector2f pos = sf::Vector2f(((xPos) * 16), -HalfSpriteSize);//Posision the y position in a grid coodiante outside player area and the x off the screen moving right
	return FleaFactory::CreateFlea(texture, LevelManager::GetMushroomField(), pos, frameWidth, frameHeight);
}

/*
For all info on how the spider is spawned on the field look here:
When a spider dies a timer is started with a random time between X second and Y seconds to spawn another spider.
*/
Spider* WaveManager::SpawnSpider(std::string texture)
{
	int frameWidth = 4;
	int frameHeight = 2;
	int spawnSide = rand() % 2;
	int yPos = rand() % 4 + 25;

	sf::Vector2f pos;
	int moveDirection;

	if(spawnSide == 1)
	{
		pos = sf::Vector2f(-HalfSpriteSize, ((yPos) * 16) + HalfSpriteSize);//Posision the y position in a grid coodiante outside player area and the x off the screen moving right
		moveDirection = 1;
	}
	else
	{
		pos = sf::Vector2f(WindowManager::MainWindow.getView().getSize().x + HalfSpriteSize, ((yPos) * 16) + HalfSpriteSize);//Posision the y position in a grid coodiante outside player area and the x off the screen moving left
		moveDirection = -1;
	}
	return SpiderFactory::CreateSpider(texture, LevelManager::GetMushroomField(), pos, frameWidth, frameHeight, moveDirection);
}

void WaveManager::SpawnCentipede(Level* level)
{
	//Calculation to get position relative to offset of sprites and grid positioning of the drop point of the centipede.
	float xPos = HalfSpriteSize + (16 * (rand() % 31));
	Instance().waveCentipede.push_front( new Centipede(
		LevelManager::GetMushroomField(), 
		Instance().waveInfo->centipedeSpawnLength[Instance().currentWave][Instance().waveInfo->numberOfCentipedes[Instance().currentWave]-1], 
		Instance().waveInfo->centipedeSpawnSpeed[Instance().currentWave][Instance().waveInfo->numberOfCentipedes[Instance().currentWave]-1], 
		xPos)
	);
	Instance().centipedeTotalSize += Instance().waveInfo->centipedeSpawnLength[Instance().currentWave][Instance().waveInfo->numberOfCentipedes[Instance().currentWave]-1];
}

void WaveManager::DestoryCentipede()
{
	while(!Instance().waveCentipede.empty())
	{
		Instance().waveCentipede.front()->EmptyCentipede();
		Instance().waveCentipede.pop_front();
	}
}

void WaveManager::DestorySpider()
{
	if(Instance().waveSpider != NULL)
		Instance().waveSpider->MarkForDestroy();
}

void WaveManager::DestoryScorpion()
{
	if(Instance().waveScorpion != NULL)
		Instance().waveScorpion->MarkForDestroy();
}

void WaveManager::DestoryFlea()
{
	if(Instance().waveFlea != NULL)
		Instance().waveFlea->MarkForDestroy();
}

void WaveManager::CentipedeBodyPartDeath()
{
  	Instance().centipedeTotalSize--;
 	if(Instance().centipedeTotalSize < 1)
	{
		LevelManager::NextWave();
	}
}

void WaveManager::ResetAlarmForSpider()
{
	Instance().SetAlarm(2, rand() % Instance().waveInfo->spiderScorpionSpawnTimer[Instance().currentWave] + 1);
	Instance().waveSpider = NULL;
}

void WaveManager::ResetAlarmForScorpion()
{
	Instance().SetAlarm(1, rand() % Instance().waveInfo->spiderScorpionSpawnTimer[Instance().currentWave] + 1);
	Instance().waveScorpion = NULL;
}

void WaveManager::ResetAlarmForFlea()
{
	Instance().SetAlarm(0, rand() % Instance().waveInfo->spiderScorpionSpawnTimer[Instance().currentWave] + 1);
	Instance().waveFlea = NULL;
}

//Alarm events to spawn more enemies
void WaveManager::Alarm0()
{
	waveFlea = Instance().SpawnFlea("Flea");
}

void WaveManager::Alarm1()
{
	waveScorpion = Instance().SpawnScorpion("Scorpion");
}

void WaveManager::Alarm2()
{
	waveSpider = Instance().SpawnSpider("Spider");
}