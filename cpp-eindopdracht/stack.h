#pragma once
#include "collection.h"

template<typename T, size_t MAX>
class Stack : public Collection<T, MAX> {
private:
	int _current;
public:
	Stack() {
		this->_current = -1;
	}
	void push(T* t) override {
		if (this->_size < MAX) {
			if (this->_arr[this->_current + 1] != nullptr)
				delete this->_arr[this->_current + 1];
			this->_current++;
			this->_arr[this->_current] = t;
			if (this->_current >= this->_size)
				this->_size = this->_current + 1;
		}
		else {
			throw -1;
		}
	}

	T*& pop() {
		if (this->_current >= 0)
		{
			return this->_arr[this->_current--];
		}
		else
		{
			throw -1;
		}
	}

	int current() {
		return this->_current;
	}

	T*& peek() {
		return this->_arr[this->_current];
	}
};