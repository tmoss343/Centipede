#include "GeneralIncludes.h"

NonMutedSoundSystem::NonMutedSoundSystem(SoundManager* theCreator)
	: SoundSystem(theCreator)
{
}

void NonMutedSoundSystem::StartSpiderLoop()
{
	creator->spiderSnd.play();
	creator->spiderSnd.setLoop(true);
}

void NonMutedSoundSystem::StopSpiderLoop()
{
	creator->spiderSnd.stop();
	creator->spiderSnd.setLoop(false);
}

void NonMutedSoundSystem::StartScorpionLoop()
{
	creator->scorpionSnd.play();
	creator->scorpionSnd.setLoop(true);
}

void NonMutedSoundSystem::StopScorpionLoop()
{
	creator->scorpionSnd.stop();
	creator->scorpionSnd.setLoop(false);
}

void NonMutedSoundSystem::StartCentipedeLoop()
{
	creator->centipedeSnd.play();
	creator->centipedeSnd.setLoop(true);

}

void NonMutedSoundSystem::StopCentipedeLoop()
{
	creator->centipedeSnd.stop();
	creator->centipedeSnd.setLoop(false);
}

void NonMutedSoundSystem::PlayBulletSound()
{
	creator->bulletSnd.play();
}

void NonMutedSoundSystem::PlayDeathSound()
{
	creator->deathSnd.play();
}

void NonMutedSoundSystem::PlayKillSound()
{
	creator->killSnd.play();
}