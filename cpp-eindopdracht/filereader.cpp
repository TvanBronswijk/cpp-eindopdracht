#include "filereader.h"

FileReader::FileReader()
{
}

int FileReader::count(const char* filename)
{
	int result = 0;

	std::ifstream file(filename);
	if (file.is_open())
	{
		char* line = new char[128];
		while (file.getline(line, 128))
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
		char* line = new char[128];
		for(int i = 0; i < lc; i++)
		{
			result[i] = new char[128];
			file.getline(line, 128);
			strcpy_s(result[i], 128, line);
		}
		delete line;
	}
	file.close();

	return result;
}

FileReader::~FileReader()
{
}
