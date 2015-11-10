#include "BoolField.h"
#include "HUD.h"
#include <stdlib.h>  

BoolField::BoolField()
{
	field = new bool*[30];
	for(int i = 0; i < 30; i++)
	{
		field[i] = new bool[30];
		for(int j = 0; j < 30; j++)
		{
			spawnChance = (rand() % 1000);
			if(spawnChance < 50 && !HUD::IsInstanceOfGlyph(i, j))
			{
				field[i][j] = true;
			}
			else
				field[i][j] = false;
		}
	}
}

bool BoolField::GetInfoAtField(int i, int j)
{
	return field[i][j];
}

void BoolField::AddInstance(int i, int j)
{
	field[i][j] = true;
}

void BoolField::SetInstance(int i, int j, bool what)
{
	field[i][j] = what;
}