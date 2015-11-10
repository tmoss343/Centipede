#include "GeneralIncludes.h"

AIControls::AIControls(Blaster* blaster)
	: BlasterControls(blaster)
{
}

void AIControls::Update()
{
	if(distnaceToNextLookAhead < 0)
	{
		myBlaster->CheckIfAtBounds();
		distnaceToNextLookAhead = SpriteSize;
	}
	distnaceToNextLookAhead -= myBlaster->GetSpeed();
	myBlaster->Move();
	myBlaster->ShootBullet();

	if ( sf::Keyboard::isKeyPressed( sf::Keyboard::Num1 ) ) 
	{
		LevelManager::OnePlayerMode();
	}
	if ( sf::Keyboard::isKeyPressed( sf::Keyboard::Num2 ) ) 
	{
		LevelManager::TwoPlayerMode();
	}
}