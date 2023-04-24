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
	MainWindow window(325, 200, "Connect 64");

	return (Fl::run());
}
