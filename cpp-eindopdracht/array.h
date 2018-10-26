#pragma once

template<typename T, size_t MAX>
class Array {
protected:
	T* _arr;
	size_t _size;
public:
	Array() {
		_arr = new T[MAX];
		_size = 0;
	}

	virtual void push(T t) {
		if (_size < MAX) 
			_arr[_size++] = t;
		else
			throw -1;
	}

	virtual T& get(size_t i) 
	{ 
		if(i < _size)
			return _arr[i]; 
		else
			throw -1;
	}

	virtual T* all() {
		return _arr;
	}

	virtual size_t size() {
		return _size;
	}

	virtual ~Array() {
		delete[] _arr;
	}
};
