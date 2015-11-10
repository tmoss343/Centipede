#include "GeneralIncludes.h"

Enemy::Enemy(std::string texture, MushroomField* theField, int horizantalDivisions, int verticalDivisions)
{
	field = theField;
	strTexture = texture;
	bitmap = ResourceManager::GetTextureBitmap(texture);
	MainSprite = AnimatedSprite(ResourceManager::GetTexture(texture), horizantalDivisions, verticalDivisions);
	
	MainSprite.setOrigin( MainSprite.getTextureRect().width / 2.0f, MainSprite.getTextureRect().height / 2.0f);
	MainSprite.setScale(1,1);
}

sf::Vector2f Enemy::GetPosition()
{
	return Pos;
}