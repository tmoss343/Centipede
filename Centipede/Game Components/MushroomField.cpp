#include "GeneralIncludes.h"

MushroomField::MushroomField()
{
	boardSize = 30;
	mushroomInPlayerArea = 0;
	//Take into account the scale if needed
	mushroomWidth = SpriteSize;
	mushroomHeight = SpriteSize;
	topBottomOffset = sf:: Vector2f(HalfSpriteSize, 24.0f);
	mushroomField = new Mushroom**[30];
	for(int i = 0; i < boardSize; i++)
	{
		mushroomField[i] = new Mushroom*[30];
		for(int j = 0; j < boardSize; j++)
		{
				mushroomField[i][j] = NULL;
		}
	}
}

void MushroomField::Initialize(BoolField* boolField)
{
	whatIsMyField = boolField;
	for(int i = 0; i < boardSize; i++)
	{
		for(int j = 0; j < boardSize; j++)
		{
			if(boolField->GetInfoAtField(i, j))
			{
				SpawnShroom(i, j);
			}
		}
	}
}

void MushroomField::Destruct()
{
	for(int i = 0; i < boardSize; i++)
	{
		for(int j = 0; j < boardSize; j++)
		{
			if(mushroomField[i][j])
			{
				mushroomField[i][j]->MarkForDestroy();
			}
		}
	}
	mushroomInPlayerArea = 0;
}

void MushroomField::RepairMushrooms(int i, int j)
{
	//Looks may be decieving this is going to repair the entire field in a flow from mushroom to mushroom
	if(LevelManager::GetMushroomField()->isInstance(i, j))
	{
		LevelManager::GetMushroomField()->getElement(i, j)->regenMushroomHealth(i, j, boardSize); 
	}
	else if(i < boardSize - 1)//So it never over steps the bounds in the check above
	{
		if(j < boardSize)
			j++;
		else
		{
			i++;//reset the array/column that you will be iterating through
			j = 0;
		}
		LevelManager::GetMushroomField()->RepairMushrooms(i, j);
	}
	else
	{
		LevelManager::SwtichActiveLevel();
	}
}


void MushroomField::SpawnShroom(int column, int row)
{
	mushroomField[column][row] = MushroomFactory::CreateMushroom( topBottomOffset + sf::Vector2f( ((float) (column) * mushroomWidth), (float) (row) * mushroomHeight), this);
	whatIsMyField->AddInstance(column, row);
	if(row > 23)
		mushroomInPlayerArea++;
}

void MushroomField::SetElement(int column, int row, Mushroom* mushroom)
{
	mushroomField[column][row] = &(*mushroom);
}

void MushroomField::AddToMushroomInPlayerArea(int amount)
{
	mushroomInPlayerArea += amount;
}

void MushroomField::DestructionOfAMushroom(int X, int Y)
{
	whatIsMyField->SetInstance(X, Y, false);
}

bool MushroomField::isInstance(int column, int row)
{
	if(column < 0 || column > 29 || row < 0)
		return true;
	else if(row > 29)
		return false;
	else if(mushroomField[column][row])
		return true;
	else
		return false;
}

Mushroom* MushroomField::getElement(int column, int row)
{
	if(mushroomField[column][row])
		return mushroomField[column][row];
	else
		return NULL;
}

int MushroomField::GetMushroomInPlayerArea()
{
	return mushroomInPlayerArea;
}
