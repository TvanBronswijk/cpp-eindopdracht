#pragma once
#include <random>
#include <ctime>

class Random {
private:
	std::default_random_engine generator;
public:
	Random();
	int get();
	int get(int max);
	int get(int min, int max);
	~Random();
};