#pragma once

template<typename T, size_t MAX>
class Collection {
private:
	T* _arr;
	size_t _size;
public:
	Collection() {
		_arr = new T[MAX];
		_size = 0;
	}
	void push(T t) {
		if (_size < MAX) {
			_arr[_size++] = t;
		}
		else {
			throw -1;
		}
	}
	~Collection() {
		for (int i = 0; i < _size; i++)
			delete _arr[i];
		delete[] _arr;
	}
};
