#include "WaveInformation.h"
#include "TEAL\CommonElements.h"
#include <sstream>

void WaveInformation::ReadInformation(std::string newContent, std::string newData)
{
	if(newContent == "TotalWaves")
	{
		totalWaves = atoi(newData.c_str());

		spiderSpeed = new int[totalWaves];
		spiderScorpionSpawnTimer = new int[totalWaves];
		minMushroomInPlayer = new int[totalWaves];
		numberOfCentipedes = new int[totalWaves];

		centipedeSpawnSpeed = new int*[totalWaves];
		centipedeSpawnLength = new int*[totalWaves];

		for(int i = 0; i < totalWaves; i++)
		{
			spiderSpeed[i] = NULL;
			spiderScorpionSpawnTimer[i] = NULL;
			minMushroomInPlayer[i] = NULL;
			numberOfCentipedes[i] = NULL;
			centipedeSpawnSpeed[i] = NULL;
			centipedeSpawnLength[i] = NULL;
		}
	}
	else if(newContent == "WaveNumber")
	{
		waveNum = atoi(newData.c_str());
	}
	else if(newContent == "SpiderSpeed")
	{
		spiderSpeed[waveNum] = atoi(newData.c_str());
	}
	else if(newContent == "NumberOfCentipedes")
	{
		numberOfCentipedes[waveNum] = atoi(newData.c_str());

		centipedeSpawnSpeed[waveNum] = new int[numberOfCentipedes[waveNum]];
		centipedeSpawnLength[waveNum] = new int[numberOfCentipedes[waveNum]];

		tmpCentipedeNum = numberOfCentipedes[waveNum] - 1;
	}
	else if(newContent == "CentipedeSpeed")
	{
		centipedeSpawnSpeed[waveNum][tmpCentipedeNum] = atoi(newData.c_str());
	}
	else if(newContent == "CentipedeLength")
	{
		centipedeSpawnLength[waveNum][tmpCentipedeNum] = atoi(newData.c_str());
		tmpCentipedeNum--;
	}
	else if(newContent == "SpawnTimer")
	{
		spiderScorpionSpawnTimer[waveNum] = atoi(newData.c_str());
	}
	else if(newContent == "MinMushroomsInPlayerArea")
	{
		minMushroomInPlayer[waveNum] = atoi(newData.c_str());
	}

}