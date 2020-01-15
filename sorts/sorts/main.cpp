#include "HighScoreTable.h"

void bubble(HighScoreTable hst, vector<HighScoreEntry> topScores) {
	topScores = hst.bubbleSort(topScores);
	for (int i = 0; i < topScores.size(); i++) {
		cout << topScores[i].name << "," << topScores[i].score << "," << topScores[i].level << endl;
	}
}

void insert(HighScoreTable hst, vector<HighScoreEntry> topScores) {
	topScores = hst.insertSort(topScores);
	for (int i = 0; i < topScores.size(); i++) {
		cout << topScores[i].name << "," << topScores[i].score << "," << topScores[i].level << endl;
	}
}

void merge(HighScoreTable hst, vector<HighScoreEntry> topScores) {
	topScores = hst.mergeSort(topScores, 0, topScores.size()-1);
	for (int i = 0; i < topScores.size(); i++) {
		cout << topScores[i].name << "," << topScores[i].score << "," << topScores[i].level << endl;
	}
}

int main() {

	HighScoreTable hst("highscores.txt");

	vector<HighScoreEntry> topScores = hst.topNNScores(10);
	for (int i = 0; i < topScores.size(); i++) {
		cout << topScores[i].name << "," << topScores[i].score << "," << topScores[i].level << endl;
	}
	cout << endl;
	hst.pruneBottomNNScores(3);

	vector<HighScoreEntry> topScores2 = hst.topNNScores(10);
	for (int i = 0; i < topScores2.size(); i++) {
		cout << topScores2[i].name << "," << topScores2[i].score << "," << topScores2[i].level << endl;
	}
	cout << endl;
	//bubble(hst, topScores);
	//insert(hst, topScores);
	merge(hst, topScores);

	system("pause");
	return 0;
}