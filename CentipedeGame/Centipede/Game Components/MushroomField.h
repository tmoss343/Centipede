#ifndef _MushroomField
#define _MushroomField

#include "TEAL\CommonElements.h"
#include "Array.h"

class Mushroom;
class BoolField;

class MushroomField
{
public:
	MushroomField();
	void Initialize(BoolField* boolField);
	void Destruct();

	void RepairMushrooms(int i, int j);
	void SpawnShroom(int column, int row);
	void SetElement(int column, int row, Mushroom*);
	void AddToMushroomInPlayerArea(int amount);
	void DestructionOfAMushroom(int X, int Y);
	bool isInstance(int column, int row);
	int GetMushroomInPlayerArea();
	Mushroom* getElement(int column, int row);

	Mushroom*** mushroomField;

private:
	int MAX, boardSize, mushroomSpawn, initializeSize, mushroomInPlayerArea;
	BoolField* whatIsMyField;
	sf::Vector2f topBottomOffset;
	float mushroomWidth, mushroomHeight;
};

#endif _MushroomField