#ifndef _WaveInformation
#define _WaveInformation

#include "TextFileInformation.h"
#include <string>

struct WaveInformation : public TextFileInformation
{
public:

	void ReadInformation(std::string newContent, std::string newData);
	int totalWaves;
	int waveNum;
	int* spiderSpeed;
	int* spiderScorpionSpawnTimer;
	int* minMushroomInPlayer;
	int** centipedeSpawnSpeed;
	int** centipedeSpawnLength;
	int* numberOfCentipedes;
private:
	int tmpCentipedeNum;
};

#endif _WaveInformation