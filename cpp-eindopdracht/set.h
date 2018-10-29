#pragma once
#include "ptrarray.h"

template<typename T, size_t MAX>
class Set : public PtrArray<T, MAX> {
private:
public:
	void remove(size_t i)
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