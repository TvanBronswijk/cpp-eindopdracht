#pragma once

template<typename T, size_t MAX>
class Collection {
protected:
	T* _arr;
	size_t _size;
public:
	Collection() {
		this->_arr = new T[MAX];
		this->_size = 0;
	}
	virtual void push(T t) {
		if (this->_size < MAX) {
			this->_arr[this->_size++] = t;
		}
		else {
			throw -1;
		}
	}
	virtual T get(size_t index) {
		if (index < this->_size)
			return this->_arr[index];
	}
	virtual T* all() {
		return _arr;
	}
	virtual size_t size() {
		return this->_size;
	}
	virtual ~Collection() {
		for (int i = 0; i < this->_size; i++)
			delete this->_arr[i];
		delete[] this->_arr;
	}
};
