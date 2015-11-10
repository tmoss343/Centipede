#ifndef _HighscoreInformation
#define _HighscoreInformation

#include "TextFileInformation.h"
#include <string>

struct HighscoreInformation : public TextFileInformation
{
public:
	HighscoreInformation();
	void ReadInformation(std::string newContent, std::string newData);

	std::string* highscoresInformationByLine;
	int pointInFileRead;
};

#endif _HighscoreInformation