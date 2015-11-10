#ifndef _MutedSoundSystem
#define _MutedSoundSystem

#include "SoundSystem.h"

class MutedSoundSystem : public SoundSystem
{
public:
	MutedSoundSystem(SoundManager* theCreator);

	void StartSpiderLoop();
	void StopSpiderLoop();

	void StartScorpionLoop();
	void StopScorpionLoop();

	void StartCentipedeLoop();
	void StopCentipedeLoop();

	void PlayBulletSound();
	void PlayDeathSound();
	void PlayKillSound();
};

#endif _MutedSoundSystem