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
#include "ErrorMessages.h"
#include <vector>
#include <iostream>
#include <regex>
#include "AlertWindow.h"
using namespace std;
namespace view {
/**
 * creates a gamewindow with a 8x8 grid
 */
class GameWindow: public OKCancelWindow {
private:
	vector<Fl_Input*> inputBoxes;
	Fl_Box *gameOutcomeLabel;
	Fl_Box *errorMessageBox;
	Fl_Button *resetButton;
	Fl_Button *saveButton;
	string puzzle;
	PuzzleNodeManager puzzleNodeManager;
	static void cb_getValue(Fl_Widget*, void *data);
	void createBoxes();
	static void cb_resetBoard(Fl_Widget *widget, void *data);
	static void cb_savePuzzle(Fl_Widget *widget, void *data);
	void loadGameBoard();
	void setNewNodeValues();
	void deleteInputBoxes();

public:
	/**
	 * GameWindow that is a 8x8 grid that loads in a puzzle
	 *
	 * @param puzzle the filename of the puzzle to be loaded
	 *
	 *@precondition the puzzle != null
	 *

	 */
	GameWindow(const string puzzle);
	/**
	 * handles the check button inherited from OKCancelWindow
	 */
	void okHandler();
	/**
	 * handles the quit button inherited from OKCancelWindow
	 */
	void cancelHandler();
	/**
	 * deconstructor for gamewindow deletes all nodes and labels
	 */
	virtual ~GameWindow();
};

} /* namespace view */

#endif /* VIEW_GAMEWINDOW_H_ */
