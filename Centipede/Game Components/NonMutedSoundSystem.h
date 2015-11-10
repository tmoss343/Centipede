#ifndef _NonMutedSoundSystem
#define _NonMutedSoundSystem

#include "SoundSystem.h"

class NonMutedSoundSystem : public SoundSystem
{
public:
	NonMutedSoundSystem(SoundManager* theCreator);

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

#endif _NonMutedSoundSystem