#ifndef _WaveManager
#define _WaveManager

#include "TEAL\CommonElements.h"
#include "list"
class MushroomField;
class Centipede;
class Spider;
class Scorpion;
class Flea;
class Level;
class WaveInformation;

class WaveManager : public GameObject 
{
public:
	static void SpawnCentipede(Level* level);
	static void DestoryCentipede();
	static void ResetAlarmForSpider();
	static void ResetAlarmForScorpion();
	static void ResetAlarmForFlea();
	static void DestorySpider();
	static void DestoryScorpion();
	static void DestoryFlea();
	static void CentipedeBodyPartDeath();
	static void NextWave(Level* level, int waveNumber);
	static WaveInformation* GetWaveInformatioin();
	static int GetTotalWaves();
	static int GetCurrentWave();

private:
	static WaveManager* instance;									// set up as a singleton
	WaveManager();									// Private constructor 
	WaveManager( const WaveManager&);				// Prevent copy-construction
	WaveManager& operator=(const WaveManager&);	// Prevent assignment

	static WaveManager& Instance()					// Access reference (all public methods will be static)
	{
		if (! instance) 
			instance = new WaveManager;
		return *instance;
	};

	Scorpion* SpawnScorpion(std::string texture);
	Flea* SpawnFlea(std::string texture);
	Spider* SpawnSpider(std::string texture);

	virtual void Alarm0();
	virtual void Alarm1();
	virtual void Alarm2();

	int currentWave, centipedeTotalSize;
	std::list<Centipede*> waveCentipede;
	Spider* waveSpider;
	Scorpion* waveScorpion;
	Flea* waveFlea;
	WaveInformation* waveInfo;
};

#endif _WaveManager