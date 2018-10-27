#pragma once
#include "ptrarray.h"

template<typename T, size_t MAX>
class Stack : public PtrArray<T, MAX> {
private:
public:
	T*& pop() {
		if (this->_size > 0)
			return this->_arr[--this->_size];
		else
			throw -100;
	}

	T*& peek() {
		if (this->_size > 0)
			return this->_arr[this->_size - 1];
		else
			throw -100;
	}
};