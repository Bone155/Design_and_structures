#include "HighScoreTable.h"

vector<HighScoreEntry> HighScoreTable::topNNScores(int topRows)
{
	vector<HighScoreEntry> temp;
	for (int i = 0; i < topRows; i++) {
		if (i > hsVector.size() - 1) {
			break;
		}
		temp.push_back(hsVector[i]);
	}
	return temp;
}

bool HighScoreTable::pruneBottomNNScores(int bottomRows)
{
	if (bottomRows >= hsVector.size()) {
		return false;
	}
	else {
		for (int i = 0; i < bottomRows; i++) {
			hsVector.pop_back();
		}
		return true;
	}
}

vector<HighScoreEntry> HighScoreTable::bubbleSort(vector<HighScoreEntry> array)
{
	vector<HighScoreEntry> temp;
	temp.resize(1);
	for (int i = 0; i < array.size() - 1; i++) {
		for (int j = array.size() - 1; j > i; j--) {
			if (array[j].score < array[j - 1].score) {
				temp[0] = array[j];
				array[j] = array[j - 1];
				array[j - 1] = temp[0];
			}
		}
	}
	return array;
}

vector<HighScoreEntry> HighScoreTable::insertSort(vector<HighScoreEntry> array)
{
	vector<HighScoreEntry> key;
	key.resize(1);
	for (int i = 1; i < array.size(); i++) {
		key[0] = array[i];
		int j = i - 1;
		while (j >= 0 && array[j].score > key[0].score) {
			array[j + 1] = array[j];
			j = j - 1;
			array[j + 1] = key[0];
		}

	}
	return array;
}

void HighScoreTable::merge(vector<HighScoreEntry> &array, size_t p, size_t q, size_t r)
{
	size_t leftEnd = q - p + 1;
	size_t rightEnd = r - q;

	vector<HighScoreEntry> left;	left.resize(leftEnd);
	vector<HighScoreEntry> right;	right.resize(rightEnd);

	for (int i = 0; i < leftEnd; i++) {
		left[i] = array[p + i];
	}
	for (int j = 0; j < rightEnd; j++) {
		right[j] = array[q + j + 1];
	}

	size_t i = 0;
	size_t j = 0;

	for (int k = p; k < r; k++) {
		if ((j >= rightEnd) || (i < leftEnd && left[i].score <= right[j].score)) {
			array[k] = left[i];
			i++;
		}
		else {
			array[k] = right[j];
			j++;
		}
	}

}

void HighScoreTable::mergeSort(vector<HighScoreEntry> &array, size_t startIdx, size_t endIdx)
{
	if (startIdx < endIdx) {
		size_t midIdx = (startIdx + endIdx) / 2;
		mergeSort(array, startIdx, midIdx);
		mergeSort(array, midIdx + 1, endIdx);
		merge(array, startIdx, midIdx, endIdx);
	}
}

HighScoreTable::HighScoreTable()
{
}

HighScoreTable::HighScoreTable(string filename)
{
	vector<HighScoreEntry> temp;
	string tempScore;
	string tempLevel;
	temp.resize(1);
	std::fstream file;
	file.open(filename, std::ios::in);
	if (!file.is_open())
	{
		std::cerr << "File not found." << endl;
	}
	string text;
	while (std::getline(file, text)) {
		for (int i = 0; i < text.length(); i++) {
			if (text[i] == ',') {
				temp[0].name = text.substr(0, i);
				break;
			}
		}
		for (int i = temp[0].name.length() + 1; i < text.length(); i++) {
			if (text[i] == ',') {
				tempScore = text.substr(strlen(temp[0].name.c_str()) + 1, text.length() - i);
				temp[0].score = std::stoi(tempScore);
				break;
			}
		}
		for (int i = text.length(); i > 0; i--) {
			if (text[i] == ',') {
				tempLevel = text.substr(i + 1, text.length() - i);
				temp[0].level = std::stoi(tempLevel);
				break;
			}
		}
		hsVector.push_back(temp[0]);
	}
	file.close();
	cout << endl;
}

HighScoreTable::~HighScoreTable()
{
}
