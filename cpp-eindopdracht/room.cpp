#include "room.h"

Room::Room(SIZE room_size, STATE state, OBJECTS objects) {	
	this->_room_size = room_size;
	this->_state = state;
	this->_objects = objects;
}

char* Room::to_string()
{
	char* result = new char[512];

	strcpy_s(result, 512, "You stand in a ");

	switch (_state) {
	case CLEAN:
		strcat_s(result, 512, "clean, ");
		break;
	case MESSY:
		strcat_s(result, 512, "messy, ");
		break;
	}
	
	switch (_room_size) {
	case SMALL:
		strcat_s(result, 512, "small ");
		break;
	case MEDIUM:
		strcat_s(result, 512, "medium ");
		break;
	case LARGE:
		strcat_s(result, 512, "large ");
		break;
	}
	strcat_s(result, 512, "room. In the center of the room is ");

	switch (_objects) {
	case TABLE:
		strcat_s(result, 512, "a large table with four chairs.");
		break;
	case BED:
		strcat_s(result, 512, "a small bed.");
		break;
	case NOTHING:
		strcat_s(result, 512, "nothing.");
		break;
	}

	return result;
}

Room::~Room()
{
}
