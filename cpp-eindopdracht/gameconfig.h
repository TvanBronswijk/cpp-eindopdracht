#pragma once

struct GameConfig {
private:
	size_t _h;
	size_t _w;
	size_t _d;
public:
	GameConfig(size_t h, size_t w, size_t d);
	size_t height();
	size_t width();
	size_t depth();
	~GameConfig();
};