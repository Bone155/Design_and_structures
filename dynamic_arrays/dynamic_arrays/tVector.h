#pragma once

template <typename T>
class tVector
{
	const static size_t GROWTH_FACTOR = 2;

	T* arr;
	size_t arrSize;
	size_t arrCapacity;
public:
	tVector() {
		arrSize = 0;
		arrCapacity = 10;
	}
	~tVector() {
		delete arr;
	}

	T* data() {
		return arr[0];
	}

	void reserve(size_t newCapacity) {
		if (newCapacity > arrCapacity) {
			arrCapacity = newCapacity;
		}
	}

	void push_back(const T &value) {
		arrSize++;
		arr[size() - 1] = value;
	}
	void pop_back() {
		arrSize = size() - 1;
	}

	T & at(size_t index) {
		T element;
		for (int i = 0; i < arrSize; i++) {
			if (arr[i] == index) {
				element = index;
			}
		}
		return element;
	}

	size_t size() const {
		return arrSize;
	}
	size_t capacity() const {
		return arrCapacity;
	}

	tVector(const tVector &vec) {
		arrSize = vec.arrSize;
		arrCapacity = vec.arrCapacity;
		arr.data() = new tVector[arrSize];
	}
	tVector& operator=(const tVector &vec) {
		arr = new tVector<T>;
		arrSize = vec.arrSize;
		arrCapacity = vec.arrCapacity;
		return arr;
	}

	T& operator[] (size_t index) {
		return arr[index];
	}

	bool empty() const {

		if (size() == 0) {
			return true;
		}
		else {
			return false;
		}
		
	}
	void resize(size_t n) {
		arrSize = n;
	}
	void shrink_to_fit() {
		arrCapacity = arrSize;
	}
	void clear() {
		arrSize = 0;
	}
};

