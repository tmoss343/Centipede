#include "ExplosionSpider.h"

ExplosionSpider::ExplosionSpider()
{
}

void ExplosionSpider::Initialize( sf::Vector2f pos, std::string texture )
{
	Pos = pos;
	MainSprite = AnimatedSprite(  ResourceManager::GetTexture(texture), 1, 1); 
	MainSprite.scale(2,2);
	MainSprite.setColor(  sf::Color::Color(255,180,180) );
	MainSprite.setOrigin(MainSprite.getTextureRect().width / 2.0f, MainSprite.getTextureRect().height / 2.0f);
	MainSprite.setPosition(Pos);
	SetAlarm(0, 2);
}

void ExplosionSpider::Update()
{
	MainSprite.setPosition(Pos);
	MainSprite.Update();
}

void ExplosionSpider::Draw()
{
	WindowManager::MainWindow.draw(MainSprite);
}

void ExplosionSpider::Alarm0()
{
	MarkForDestroy();
}