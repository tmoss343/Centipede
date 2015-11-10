#include "GeneralIncludes.h"

Explosion::Explosion()
{
}

void Explosion::Initialize( sf::Vector2f pos, std::string texture )
{
	Pos = pos;
	MainSprite = AnimatedSprite(  ResourceManager::GetTexture(texture), 3, 2); 
	MainSprite.SetAnimation(0, 5); 
	MainSprite.scale(1,1);
	MainSprite.setColor(  sf::Color::Color(255,180,180) );
	MainSprite.setOrigin(MainSprite.getTextureRect().width / 2.0f, MainSprite.getTextureRect().height / 2.0f);
	MainSprite.setPosition(Pos);
}

void Explosion::Update()
{
	if ( MainSprite.IsLastAnimationFrame() )
		MarkForDestroy();

	MainSprite.setPosition(Pos);
	MainSprite.Update();
}

void Explosion::Draw()
{
	WindowManager::MainWindow.draw(MainSprite);
}