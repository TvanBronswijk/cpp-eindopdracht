#pragma once
#include "array.h"

template<typename T, size_t MAX>
class Set : public PtrArray<T, MAX> {
private:
public:
	void remove(int i)
	{
		if (i < this->_size) {
			delete this->_arr[i];
			this->_arr[i] = this->_arr[--this->_size];
			this->_arr[this->_size] = nullptr;
		}
		else {
			throw -90;
		}
	}
};