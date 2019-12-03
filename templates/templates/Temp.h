#pragma once

template<int T>
class Temp
{
public:
	T Min(T a, T b) {
		if (a > b)
			return b;
		else
			return a;
	}
	T Max(T a, T b) {
		if (a > b)
			return a;
		else
			return b;
	}

	T Clamp(T min, T max, T val) {
		if (val < min)
			val = min;
		if (val > max)
			val = max;
	}

	char Min(char a, char b) {
		if (a > b)
			return b;
		else
			return a;
	}
	char Max(char a, char b) {
		if (a > b)
			return a;
		else
			return b;
	}

	Temp();
	~Temp();
};

