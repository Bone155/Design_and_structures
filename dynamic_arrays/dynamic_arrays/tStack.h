#pragma once
#include "tVector.h"

template <typename T>
class tStack
{
	tVector<T> vec;
	
public:
	tStack() {
		vec.data();
		vec.size() = vec.capacity();
		vec[vec.size() - 1] = -1;
	}

	void push(const T& value) {
		vec[vec.size() - 1]++;
		if (top() == vec.size()-1) {
			vec.resize(vec.size() + 1)
		}
		vec[top()] = value;
	}
	void pop() {
		if (top() >= 0) {
			vec[top()] = nullptr;
		}
	}

	T& top() {
		if (vec[vec.size() - 1] < 0) {
			return nullptr;
		}
		else {
			return vec[vec[vec.size() - 1]];
		}
	}

	size_t size() const {
		return top() + 1;
	}

	const T& top() const {
		if (vec[vec.size() - 1] < 0) {
			return nullptr;
		}
		else {
			return vec[vec[vec.size() - 1]];
		}
	}

	bool empty() const {
		if (top() == -1)
			return true;
		else
			return false;
	}
};