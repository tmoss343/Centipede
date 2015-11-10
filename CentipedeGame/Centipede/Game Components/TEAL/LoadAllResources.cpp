// LoadAllResources.cpp
// Andre Berthiaume, June 2012
//
// The user fills the method with all resources that need loading

#include "ResourceManager.h"
#include "../World.h"

void ResourceManager::LoadAllResources()
{
	SetStartScene( new World );
	
	AddTexture("Blaster", "blaster.png");
	AddTexture("Mushroom", "mushroom.png");
	AddTexture("Bullets", "bullet.png");
	AddTexture("Centipede Head","centipede_head.png");
	AddTexture("Centipede Body","centipede_body.png");
	AddTexture("Scorpion", "scorpion.png");
	AddTexture("Flea", "flea.png");
	AddTexture("Spider", "spider.png");
	AddTexture("Death", "spawn.png");
	AddTexture("PlayerExplosion", "death.png");
	AddTexture("300", "three.png");
	AddTexture("600", "six.png");
	AddTexture("900", "nine.png");

	AddTexture("CentipedeFont", "FONT.bmp");
	
	AddSound("BulletSnd", "fire2.wav");
	AddSound("DeathSnd", "death.wav");
	AddSound("KillSnd", "kill.wav");
	AddSound("SpiderSnd", "spider_new.wav");
	AddSound("ScorpionSnd", "scorpion_new.wav");
	AddSound("CentipedeSnd", "beat.wav");
}

