#ifndef _SoundManager
#define _SoundManager

class SoundSystem;

class SoundManager
{
public:
		
	static void StartSpiderLoop();
	static void StopSpiderLoop();

	static void StartScorpionLoop();
	static void StopScorpionLoop();

	static void StartCentipedeLoop();
	static void StopCentipedeLoop();

	static void PlayBulletSound();
	static void PlayDeathSound();
	static void PlayKillSound();

	static void ToggleMute();
	static void Mute();

	sf::Sound spiderSnd, scorpionSnd, centipedeSnd, bulletSnd, deathSnd, killSnd;
private:
	static SoundManager* instance;									// set up as a singleton
	SoundManager();									// Private constructor 
	SoundManager( const SoundManager&);				// Prevent copy-construction
	SoundManager& operator=(const SoundManager&);	// Prevent assignment

	static SoundManager& Instance()					// Access reference (all public methods will be static)
	{
		if (! instance) 
			instance = new SoundManager;
		return *instance;
	};

	SoundSystem* mySounds;
	SoundSystem* mutedSounds;
	SoundSystem* unMutedSounds;
};

#endif _SoundManager