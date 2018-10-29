#include "random.h"

Random::Random()
{
	generator.seed(time(0));
}

int Random::get()
{
	return get(0, 10);
}

int Random::get(int max)
{
	return get(0, max);
}

int Random::get(int min, int max)
{
	std::uniform_int_distribution<int> d(min, max);
	return d(generator);
}

Random::~Random()
{
}
