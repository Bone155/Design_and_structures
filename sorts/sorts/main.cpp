#include "HighScoreTable.h"

int main() {

	HighScoreTable hst("highscores.txt");

	vector<HighScoreEntry> topScores = hst.topNNScores(10);

	hst.pruneBottomNNScores(3);

	vector<HighScoreEntry> topScores2 = topScores;

	system("pause");
	return 0;
}