#pragma once
#include "ptrarray.h"

template<typename T, size_t MAX>
class Stack : public PtrArray<T, MAX> {
private:
public:
	T*& pop() {
		if (this->_size > 0)
		{
			return this->_arr[--this->_size];
		}
		else
		{
			throw -1;
		}
	}

	T*& peek() {
		return this->_arr[this->_size - 1];
	}
};