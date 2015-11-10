#include "GeneralIncludes.h"

void World::Initialize()
{
	WindowManager::SetBackgroundColor( sf::Color(0,0,0,0) );
	

	LevelManager::AttractorMode();

	CollisionTestPair<Blaster, Mushroom>();
	CollisionTestPair<Blaster, CentipedeBodyPart>();
	CollisionTestPair<Blaster, Flea>();
	CollisionTestPair<Blaster, Spider>();

	//CollisionTestPair<Bullet, Mushroom>();
	CollisionTestPair<Bullet, Flea>();
	CollisionTestPair<Bullet, Scorpion>();
	CollisionTestPair<Spider, Bullet>();

	CollisionTestPair<CentipedeBodyPart, Mushroom>();
	CollisionTestPair<CentipedeBodyPart, Bullet>();
}