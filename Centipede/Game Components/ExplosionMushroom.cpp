#include "GeneralIncludes.h"

ExplosionMushroom::ExplosionMushroom()
{
}

void ExplosionMushroom::Initialize( sf::Vector2f pos, std::string texture, int i, int j, int size )
{
	Pos = pos;
	MainSprite = AnimatedSprite(  ResourceManager::GetTexture(texture), 3, 2); 
	MainSprite.SetAnimation(0, 5); 
	MainSprite.scale(1,1);
	MainSprite.setColor(  sf::Color::Color(255,180,180) );
	MainSprite.setOrigin(MainSprite.getTextureRect().width / 2.0f, MainSprite.getTextureRect().height / 2.0f);
	MainSprite.setPosition(Pos);

	nextCol = i;
	nextRow = j; 
	boardSize = size;
}

void ExplosionMushroom::Update()
{
	if ( MainSprite.IsLastAnimationFrame() )
		MarkForDestroy();

	MainSprite.setPosition(Pos);
	MainSprite.Update();
}

void ExplosionMushroom::Draw()
{
	WindowManager::MainWindow.draw(MainSprite);
}

void ExplosionMushroom::Destroy()
{
	if(nextRow < boardSize)
		nextRow++;
	else
	{
		nextCol++;//reset the array/column that you will be iterating through
		nextRow = 0;
	}
	
	if(nextCol < boardSize)
	{
		LevelManager::GetMushroomField()->RepairMushrooms(nextCol, nextRow);//call next mushroom
	}
}