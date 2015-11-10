#include "GeneralIncludes.h"

SoundManager* SoundManager::instance;

SoundManager::SoundManager()
{
	spiderSnd.setBuffer(ResourceManager::GetSound("SpiderSnd"));
	scorpionSnd.setBuffer(ResourceManager::GetSound("ScorpionSnd"));
	centipedeSnd.setBuffer(ResourceManager::GetSound("CentipedeSnd"));
	bulletSnd.setBuffer(ResourceManager::GetSound("BulletSnd"));
	deathSnd.setBuffer(ResourceManager::GetSound("DeathSnd"));
	unMutedSounds = new NonMutedSoundSystem(this);
	mutedSounds = new MutedSoundSystem(this);
	mySounds = mutedSounds;
}

void SoundManager::StartSpiderLoop()
{
	Instance().mySounds->StartSpiderLoop();
}

void SoundManager::StopSpiderLoop()
{
	Instance().mySounds->StopSpiderLoop();
}

void SoundManager::StartScorpionLoop()
{
	Instance().mySounds->StartScorpionLoop();
}

void SoundManager::StopScorpionLoop()
{
	Instance().mySounds->StopScorpionLoop();
}

void SoundManager::StartCentipedeLoop()
{
	Instance().mySounds->StartCentipedeLoop();\
}

void SoundManager::StopCentipedeLoop()
{
	Instance().mySounds->StopCentipedeLoop();
}

void SoundManager::PlayBulletSound()
{
	Instance().mySounds->PlayBulletSound();
}

void SoundManager::PlayDeathSound()
{
	Instance().mySounds->PlayDeathSound();
}

void SoundManager::PlayKillSound()
{
	Instance().mySounds->PlayKillSound();
}

void SoundManager::ToggleMute()
{
	if(Instance().mySounds == Instance().mutedSounds)
	{
		Instance().mySounds = Instance().unMutedSounds;
	}
	else
	{
		Instance().mySounds = Instance().mutedSounds;
	}
}

void SoundManager::Mute()
{
	Instance().mySounds = Instance().mutedSounds;
}