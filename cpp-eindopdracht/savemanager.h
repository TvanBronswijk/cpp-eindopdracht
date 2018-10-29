#pragma once
#include <iostream>
#include <fstream>
#include "player.h"
#include "filereader.h"
#include "stringutil.h"

class SaveManager {
private:
public:
	SaveManager();
	void print();
	Player* load_save(int index);
	void save(Player* p);
	~SaveManager();
};