#include <iostream>
#include "tObjectPool.h"

int main() {
	int size = 7;
	int * nums;
	for (int i = 0; i < size; i++) {
		nums[i] = rand() % 100;
	}

	tObjectPool<int> test;



	system("pause");
	return 0;
}