//============================================================================
// Name        : TeamFConnect64.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include <PuzzleManager.h>
#include "view/MainWindow.h"
#include "view/HighScoreWindow.h"
#include <ScoreManager.h>
#include <Utils.h>

using namespace view;
using namespace scores;
using namespace utils;

int main() {
	MainWindow window(325, 250, "Connect 64 by DeCesare, Williams");

	return (Fl::run());
}
