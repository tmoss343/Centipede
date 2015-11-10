#ifndef _SoundSystem
#define _SoundSystem

class SoundManager;

class SoundSystem
{
public:
	SoundSystem(SoundManager* theCreator);
	virtual void StartSpiderLoop() = 0;
	virtual void StopSpiderLoop() = 0;

	virtual void StartScorpionLoop() = 0;
	virtual void StopScorpionLoop() = 0;

	virtual void StartCentipedeLoop() = 0;
	virtual void StopCentipedeLoop() = 0;

	virtual void PlayBulletSound() = 0;
	virtual void PlayDeathSound() = 0;
	virtual void PlayKillSound() = 0;
protected:
	SoundManager* creator;
};

#endif _SoundSystem
