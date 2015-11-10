#include "GeneralIncludes.h"

ExplosionPlayer::ExplosionPlayer()
{
}

void ExplosionPlayer::Initialize( sf::Vector2f pos, std::string texture, Blaster* theBlaster )
{
	Pos = pos;
	MainSprite = AnimatedSprite(  ResourceManager::GetTexture(texture), 3, 2); 
	MainSprite.SetAnimation(0, 5); 
	MainSprite.scale(1,1);
	MainSprite.setColor(  sf::Color::Color(255,180,180) );
	MainSprite.setOrigin(MainSprite.getTextureRect().width / 2.0f, MainSprite.getTextureRect().height / 2.0f);
	MainSprite.setPosition(Pos);
	blaster = theBlaster;
	SetAlarm(0, 0.3);
}

void ExplosionPlayer::Update()
{
	MainSprite.setPosition(Pos);
	MainSprite.Update();
}

void ExplosionPlayer::Draw()
{
	if ( !MainSprite.IsLastAnimationFrame() )
	{
		WindowManager::MainWindow.draw(MainSprite);
	}
}

void ExplosionPlayer::Destroy()
{
}

void ExplosionPlayer::Alarm0()
{
	LevelManager::GetActiveLevel()->GetPlayer()->PlayerDeath();
	MarkForDestroy();
}