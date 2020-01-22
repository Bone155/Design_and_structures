#pragma once
template<typename T>
class tObjectPool
{
	T* pool;
	bool* free;
	size_t poolCapacity;

public:
	tObjectPool() {
		poolCapacity = 10;
		for (int i = 0; i < poolCapacity; i++) {
			pool[i] = new T();
			free[i] = false;
		}
	}
	tObjectPool(size_t initialCapacity) {
		poolCapacity = initialCapacity;
			for (int i = 0; i < initialCapacity; i++) {
				pool[i] = new T();
				free[i] = false;
			}
	}
	~tObjectPool() { delete pool; delete free; }

	T* retrieve() {

		for (int i = 0; i < capacity(); i++) {
			
			if (free[i] == false) {
				free[i] = true;
				return pool[i];
			}
		}
		return nullptr;
	}
	void recycle(T* obj) {

		for (int i = 0; i < capacity(); i++) {

			if (pool[i] == obj) {
				free[i] = false;
				
			}
		}

	}

	size_t capacity() { return poolCapacity; }
};

