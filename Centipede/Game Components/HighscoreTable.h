#ifndef _HighscoreTable
#define _HighscoreTable

#include "TextFileInformation.h"
#include <string>

struct HighscoreTable : public TextFileInformation
{
public:
	HighscoreTable();
	void ReadInformation(std::string newContent, std::string newData);
	int* highscores;
	std::string* names; 
private:
	int pointInHighscores;
};

#endif _WaveInformation