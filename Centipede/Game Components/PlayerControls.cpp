#include "GeneralIncludes.h"

PlayerControls::PlayerControls(Blaster* blaster)
	: BlasterControls(blaster)
{
}

void PlayerControls::Update()
{
	if ( sf::Keyboard::isKeyPressed( sf::Keyboard::W)) myBlaster->UP();
	if ( sf::Keyboard::isKeyPressed( sf::Keyboard::S)) myBlaster->DOWN();
	if ( sf::Keyboard::isKeyPressed( sf::Keyboard::A)) myBlaster->LEFT();
	if ( sf::Keyboard::isKeyPressed( sf::Keyboard::D)) myBlaster->RIGHT();
	if ( sf::Keyboard::isKeyPressed( sf::Keyboard::Space) && myBlaster->CanFire()) myBlaster->ShootBullet();

	if( sf::Keyboard::isKeyPressed( sf::Keyboard::M)) SoundManager::ToggleMute();
}