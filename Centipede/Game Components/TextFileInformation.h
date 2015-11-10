#ifndef _TextFileInformation
#define _TextFileInformation

#include <string>

struct TextFileInformation
{
public:
	virtual void ReadInformation(std::string newContent, std::string newData) = 0;
};

#endif _TextFileInformation