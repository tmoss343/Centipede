#include "HighscoreInformation.h"
#include <sstream>

HighscoreInformation::HighscoreInformation()
{
	pointInFileRead = 0;
	highscoresInformationByLine = new std::string[13];

	for (int i = 0; i < 13; i++)
	{
		highscoresInformationByLine[i] = "";
	}
}
void HighscoreInformation::ReadInformation(std::string newContent, std::string newData)
{
	highscoresInformationByLine[pointInFileRead] = newContent;
	pointInFileRead++;
}