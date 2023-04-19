/*
 * GameWindow.h
 *
 *  Created on: Apr 13, 2023
 *      Author: cwill124
 */

#ifndef VIEW_GAMEWINDOW_H_
#define VIEW_GAMEWINDOW_H_
#include <Fl/Fl_Input.H>
#include <Fl/Fl_Box.H>
#include <Fl/Fl_Button.H>
#include "OKCancelWindow.h"
#include "MainWindow.h"
#include "PuzzleNodeManager.h"
#include "Settings.h"
#include "PuzzleNode.h"
#include <vector>
#include <iostream>
#include <regex>
using namespace std;
namespace view {

class GameWindow: public OKCancelWindow {
private:
	vector<Fl_Input*> inputBoxes;
	Fl_Box* puzzleLevel;
	Fl_Button* resetButton;
	PuzzleNodeManager puzzleNodeManager;
	static void cb_getValue(Fl_Widget*, void* data);
	void createBoxes();
	bool checkOtherInputValues(Fl_Widget* widget );
	static void cb_resetBoard(Fl_Widget* widget, void* data);
	void loadGameBoard();
	int getInputBoxIndex(Fl_Input* inputBox);

public:
	GameWindow();
	void okHandler();
	void cancelHandler();
	virtual ~GameWindow();
};

} /* namespace view */

#endif /* VIEW_GAMEWINDOW_H_ */
