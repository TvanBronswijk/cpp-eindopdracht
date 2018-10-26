#pragma once
#include "array.h"

template<typename T, size_t MAX>
class PtrArray : public Array<T*, MAX> {
private:
public:
	virtual ~PtrArray() override {
		for (int i = 0; i < this->_size; i++)
			delete this->_arr[i];
	}
};