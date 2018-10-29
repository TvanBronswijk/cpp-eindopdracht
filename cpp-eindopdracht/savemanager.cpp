#include "savemanager.h"

SaveManager::SaveManager()
{
}

void SaveManager::print()
{
	FileReader fr;
	int save_count = fr.count("saves.txt");
	char** rows = fr.read("saves.txt", save_count);

	for (int i = 0; i < save_count; i++)
	{
		char** clms = StringUtil::split(rows[i], "[;]");

		std::cout << i << ": " << clms[0] << std::endl;
		delete clms[0];
		delete clms[1];
		delete[] clms;
		
		delete rows[i];
	}
	delete[] rows;
}

Player * SaveManager::load_save(int index)
{
	FileReader fr;
	int save_count = fr.count("saves.txt");
	if (index >= save_count)
		throw -1;
	char** rows = fr.read("saves.txt", save_count);
	char** clms = StringUtil::split(rows[index], "[;]");
	Player* result = new Player(clms[0]);
	result->level = atoi(clms[1]);
	
	delete clms[1];
	delete[] clms;
	for (int i = 0; i < save_count; i++)
		delete rows[i];
	delete[] rows;
	return result;
}

void SaveManager::save(Player * p)
{
	std::ofstream myfile;
	myfile.open("saves.txt", std::ios::app);
	myfile 
		<< "[" << p->name << ";" << p->level << "]"
		<< std::endl;
	myfile.close();
}

SaveManager::~SaveManager()
{
}
