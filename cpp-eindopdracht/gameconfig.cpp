#include "gameconfig.h"

GameConfig::GameConfig(size_t h, size_t w, size_t d)
{
	this->_h = h;
	this->_w = w;
	this->_d = d;
}


size_t GameConfig::height()
{
	return _h;
}

size_t GameConfig::width()
{
	return _w;
}

size_t GameConfig::depth()
{
	return _d;
}

GameConfig::~GameConfig()
{
}


