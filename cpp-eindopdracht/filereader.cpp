#include "filereader.h"

FileReader::FileReader()
{
}

int FileReader::count(const char * filename)
{
	int result = 0;

	std::ifstream file(filename);
	if (file.is_open())
	{
		char* line = new char[100];
		while (file.getline(line, 100))
		{
			result++;
		}
		delete line;
	}
	file.close();

	return result;
}

char** FileReader::read(const char* filename, size_t lc)
{
	char** result = new char*[lc];

	std::ifstream file(filename);
	if (file.is_open())
	{
		char* line = new char[100];
		for(int i = 0; i < lc; i++)
		{
			result[i] = new char[100];
			file.getline(line, 100);
			strcpy_s(result[i], 100, line);
		}
		delete line;
	}
	file.close();

	return result;
}

FileReader::~FileReader()
{
}
