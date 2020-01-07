#include <iostream>
#include <string>
#include "tVector.h"

using std::string;
using std::cout;
using std::cin;
using std::endl;

int main() {

	tVector<int> vec;
	
	int * n = vec.data();
	*n = 10;


	system("pause");
	return 0;
}