#include "stringutil.h"

char** StringUtil::split(char* str, const char* regex)
{
	char** result = new char*[64];
	char** context = new char*[16];

	char* line = strtok_s(str, regex, context);
	for (int i = 0; line != NULL; i++)
	{
		result[i] = new char[255];
		strcpy_s(result[i], 255, line);
		line = strtok_s(NULL, regex, context);
	}
	delete[] context;

	return result;
}
