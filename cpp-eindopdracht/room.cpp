#include "room.h"

Room::Room(SIZE room_size, STATE state, OBJECTS objects) {	
	description = new char[512];

	strcpy_s(description, 512, "You stand in a ");
	switch (state) {
	case CLEAN:
		strcat_s(description, 512, "clean, ");
		break;
	case MESSY:
		strcat_s(description, 512, "messy, ");
		break;
	}
	switch (room_size) {
	case SMALL:
		strcat_s(description, 512, "small ");
		break;
	case MEDIUM:
		strcat_s(description, 512, "medium ");
		break;
	case LARGE:
		strcat_s(description, 512, "large ");
		break;
	}
	strcat_s(description, 512, "room. In the center of the room is ");
	switch (objects) {
	case TABLE:
		strcat_s(description, 512, "a large table with four chairs.");
		break;
	case BED:
		strcat_s(description, 512, "a small bed.");
		break;
	case NOTHING:
		strcat_s(description, 512, "nothing.");
		break;
	}
}

const char* Room::to_string()
{
	return this->description;
}

Room::~Room()
{
	delete[] description;
}
