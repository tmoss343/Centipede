#ifndef _FileReader
#define _FileReader

#include <iostream>
#include <fstream>
#include <string>
class TextFileInformation;

class FileReader
{
public:
	static void OpenFile(std::string name, TextFileInformation* interpreter);
	static void OpenFileReadByLine(std::string name, TextFileInformation* interpreter);
};

#endif _FileReader