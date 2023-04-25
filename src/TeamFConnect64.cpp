//============================================================================
// Name        : TeamFConnect64.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include "view/MainWindow.h"
#include "view/HighScoreWindow.h"
#include <PuzzleNodeManager.h>
#include <ScoreManager.h>
#include <Utils.h>

using namespace view;
using namespace model;
using namespace scores;
using namespace utils;

int main() {
	MainWindow window(325, 250, "Connect 64");

	return (Fl::run());
}
