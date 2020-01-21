#pragma once
#include "HighScoreEntry.h"
#include <vector>
#include <fstream>

using std::string;
using std::vector;
using std::cout;
using std::cin;
using std::endl;

class HighScoreTable
{
public:
	vector<HighScoreEntry> hsVector;
	vector<HighScoreEntry> topNNScores(int topRows);
	bool pruneBottomNNScores(int bottomRows);
	vector<HighScoreEntry> bubbleSort(vector<HighScoreEntry> array);
	vector<HighScoreEntry> insertSort(vector<HighScoreEntry> array);
	void merge(vector<HighScoreEntry> & array, size_t p, size_t q, size_t r);
	void mergeSort(vector<HighScoreEntry> &array, size_t p, size_t r);

	HighScoreTable();
	HighScoreTable(string filename);
	~HighScoreTable();
};

