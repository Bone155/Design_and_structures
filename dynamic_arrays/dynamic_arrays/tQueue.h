#pragma once
#include "tVector.h"

template <typename T>
class tQueue
{
	tVector<T> vec; // front = 0

public:
	tQueue() {
		vec.data();
		vec.size() = vec.capacity();
		vec[vec.size() - 1] = -1;
	}
	tQueue(size_t count, const T& value) {
		vec.resize(count);
		for (int i = 0; i < count; i++) {
			vec[i] = value;
		}
	}

	void push(const T& value) {
		vec[vec.size() - 1]++;
		if (front() == vec.size() - 1) {
			vec.resize(vec.size() + 1)
		}
		vec[front()] = value;
	}
	void pop() {
		if (front() >= 0) {
			vec[front()] = nullptr;
		}
	}

	T& front() {
		if (vec[vec.size() - 1] < 0) {
			return nullptr;
		}
		else {
			return vec[vec[vec.size() - 1]];
		}
	}

	size_t size() const {
		return front() + 1;
	}

	const T& front() const {
		if (vec[vec.size() - 1] < 0) {
			return nullptr;
		}
		else {
			return vec[vec[vec.size() - 1]];
		}
	}

	bool empty() const {
		if (front() == -1)
			return true;
		else
			return false;
	}
};