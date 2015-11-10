#include "HighscoreTable.h"
#include <sstream>

HighscoreTable::HighscoreTable()
{
	highscores = new int[7];
	names = new std::string[7];

	for(int i = 0; i < 6; i++)
	{
		highscores[i] = NULL;
		names[i] = "";
	}
	pointInHighscores = 0;
}

void HighscoreTable::ReadInformation(std::string newContent, std::string newData)
{
	if(newData != "SCORES" && newData != "2" && newData != "EVERY" && newData != "")
	{
		highscores[pointInHighscores] = atoi(newContent.c_str());
		names[pointInHighscores] = newData;
		pointInHighscores++;
	}
}