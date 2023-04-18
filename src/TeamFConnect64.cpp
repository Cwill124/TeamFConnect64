//============================================================================
// Name        : TeamFConnect64.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include "view/MainWindow.h"
#include <PuzzleNodeManager.h>
#include <ScoreManager.h>

using namespace view;
using namespace model;
using namespace scores;

int main() {
	PuzzleNodeManager manager = PuzzleNodeManager();
	manager.loadNewPuzzle();
	manager.saveNodes(Settings::CurrentPuzzleFileName);
	cout << manager.toString() + "\n\n";

	manager.loadNewPuzzle();
	cout << manager.toString();

	manager.loadNodes(Settings::CurrentPuzzleFileName);

	//TODO Only here for demonstration purposes. Feel free to edit and play around to test
	manager.addPuzzleNode(2, 3, false);
	manager.addPuzzleNode(5, 4, false);
	manager.addPuzzleNode(4, 5, false);
	manager.addPuzzleNode(3, 6, false);
	manager.addPuzzleNode(6, 7, false);
	manager.addPuzzleNode(7, 8, false);

	manager.saveNodes(Settings::CurrentPuzzleFileName);

	cout << manager.toString();

	//TODO Only here for demo purposes for the high score.
	ScoreManager scoreManager = ScoreManager();

	string name1 = "Timmy";
	string name2 = "Tommy";
	string name3 = "Alex";
	string name4 = "Sally";
	string name5 = "John";

	scoreManager.addScore(name1, 90, 1);
	scoreManager.addScore(name2, 60, 1);
	scoreManager.addScore(name3, 12000, 2);
	scoreManager.addScore(name4, 100, 3);
	scoreManager.addScore(name5, 90, 1);

	vector<Score*> scores1 = scoreManager.getScores();
	vector<Score*> sorted1 = scoreManager.getScoresSortedByPuzzleNumber();
	vector<Score*> sorted2 = scoreManager.getScoresSortedByTime();

	scoreManager.saveScores();

	scoreManager.removeScore(2);

	vector<Score*> scores2 = scoreManager.getScores();
	vector<Score*> sorted3 = scoreManager.getScoresSortedByPuzzleNumber();
	vector<Score*> sorted4 = scoreManager.getScoresSortedByTime();

	scoreManager.removeScore(3);

	vector<Score*> scores3 = scoreManager.getScores();
	vector<Score*> sorted5 = scoreManager.getScoresSortedByPuzzleNumber();
	vector<Score*> sorted6 = scoreManager.getScoresSortedByTime();

	scoreManager.resetScores();

	vector<Score*> scores4 = scoreManager.getScores();
	vector<Score*> sorted7 = scoreManager.getScoresSortedByPuzzleNumber();
	vector<Score*> sorted8 = scoreManager.getScoresSortedByTime();

	for (Score* score : scores4) {
		cout << score->getPlayerName() << " " << score->getPuzzleNumber() << " " << score->getTime() << endl;
	}

	cout << endl;

	for (Score* score : sorted7) {
		cout << score->getPlayerName() << " " << score->getPuzzleNumber() << " " << score->getTime() << endl;
	}

	cout << endl;

	for (Score* score : sorted8) {
		cout << score->getPlayerName() << " " << score->getPuzzleNumber() << " " << score->getTime() << endl;
	}

	MainWindow window(325, 200, "Connect 64");

	return (Fl::run());
}
