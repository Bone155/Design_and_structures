#include "HighScoreTable.h"

vector<HighScoreEntry> HighScoreTable::topNNScores(int topRows)
{
	vector<HighScoreEntry> temp;
	for (int i = 1; i < topRows; i++) {
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
		hsVector.resize(hsVector.size() - bottomRows);
		return true;
	}
}

vector<HighScoreEntry> HighScoreTable::bubbleSort(vector<HighScoreEntry> array)
{
	for (int i = 0; i < array.size() - 1; i++) {
		for (int j = array.size() - 1; j > i + 1; j--) {
			if (array[j].score < array[j - i].score) {
				vector<HighScoreEntry> temp;
				temp[0] = array[j];
				array[j] = array[j - i];
				array[j] = temp[0];
			}
		}
	}
	return array;
}

vector<HighScoreEntry> HighScoreTable::insertSort(vector<HighScoreEntry> array)
{
	for (int i = 0; i < array.size(); i++) {
		vector<HighScoreEntry> key;
		key[0] = array[i];
		int j = i - 1;
		while (j >= 0 && array[j].score > key[0].score) {
			array[j + 1] = array[j];
			j = j - 1;
			array[j + 1] = key[0];
		}

	}
	return vector<HighScoreEntry>();
}

HighScoreTable::HighScoreTable()
{
}

HighScoreTable::HighScoreTable(string filename)
{
	std::fstream file;
	file.open(filename, std::ios::in);
	if (!file.is_open())
	{
		std::cerr << "File not found." << endl;
	}
	string text;
	int j = 0;
	while (std::getline(file, text)) {
		cout << text << endl;
		for (int i = 0; i < text.length(); i++) {
			if (text[i] == ',') {
				hsVector[j].name = text.substr(0, text[i - 1]);
			}
		}
		for (int i = strlen(hsVector[j].name.c_str()) + 1; i < text.length(); i++) {
			if (text[i] == ',') {
				text = text.substr(strlen(hsVector[j].name.c_str()) + 1, text.length() - i);
				hsVector[j].score = std::stoi(text);
			}
		}
		for (int i = text.length(); i > 0; i--) {
			if (text[i] == ',') {
				text = text.substr(text.length(), text[i - 1]);
				hsVector[j].level = std::stoi(text);
			}
		}
		
		j++;
	}
	cout << endl;
	file.close();
}

HighScoreTable::~HighScoreTable()
{
}
