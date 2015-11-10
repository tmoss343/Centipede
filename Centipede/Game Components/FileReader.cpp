#include "FileReader.h"
#include "TextFileInformation.h"
#include <iostream>
#include <fstream>

void FileReader::OpenFile(std::string name, TextFileInformation* interpreter)
{
	std::string info, data;

	std::ifstream text(name);
	if (text.is_open())
	{
		while (text)
		{
			if(text >> info >> data)
				interpreter->ReadInformation(info, data);
		}
		text.close();
	}
}

void FileReader::OpenFileReadByLine(std::string name, TextFileInformation* interpreter)
{
	std::string info;

	std::ifstream text(name);
	if (text.is_open())
	{
		while (getline(text, info))
		{		
			interpreter->ReadInformation(info, "");
		}
		text.close();
	}
}