//============================================================================
// Name        : TeamFConnect64.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include "view/MainWindow.h"
#include <PuzzleNodeManager.h>

using namespace view;
using namespace model;

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

	MainWindow window(325, 200, "Connect 64");

	return (Fl::run());
}
