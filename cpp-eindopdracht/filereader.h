#pragma once
#include <iostream>
#include <fstream>
#include <sstream>

class FileReader {
private:

public:
	FileReader();
	int count(const char* filename);
	char** read(const char* filename, size_t lc);
	~FileReader();
};