#ifndef VIEW_GAMEWINDOW_H_
#define VIEW_GAMEWINDOW_H_
#include <Fl/Fl_Input.H>
#include <Fl/Fl_Box.H>
#include <Fl/Fl_Button.H>
#include <Fl/Fl_Timer.H>
#include <Fl/Fl_Output.H>
#include <FL/Fl_Scroll.H>
#include <FL/fl_draw.H>
#include <PuzzleManager.h>
#include "OKCancelWindow.h"
#include "MainWindow.h"
#include "Settings.h"
#include "PuzzleNode.h"
#include "ErrorMessages.h"
#include "Utils.h"
#include <vector>
#include <iostream>
#include <regex>
#include "InputAlertWindow.h"
#include "ScrollableAlertWindow.h"
#include "ColorSettingsFileIO.h"

using namespace std;
using namespace utils;
using namespace puzzle;

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
	Fl_Button *pauseButton;
	Fl_Button *hintButton;
	Fl_Output *timer;
	bool isPaused;
	string puzzle;
	int puzzleNumber;
	PuzzleManager puzzleNodeManager;
	static void cb_getValue(Fl_Widget*, void *data);
	void createBoxes();
	static void cb_resetBoard(Fl_Widget *widget, void *data);
	static void cb_savePuzzle(Fl_Widget *widget, void *data);
	static void cb_pause(Fl_Widget *widget, void *data);
	static void cb_hint(Fl_Widget *widget, void *data);
	static void cb_timer(void *data);
	void loadGameBoard();
	bool setNewNodeValues();
	void deleteInputBoxes();
	void resetInputBoxes();
	void loadNextPuzzle();

public:
	/**
	 * GameWindow that is a 8x8 grid that loads in a puzzle
	 *
	 * Precondition: None
	 * Postcondition: None
	 *
	 * Param: puzzle the filename of the puzzle to be loaded
	 * Param: puzzleNumber the number of the puzzle to be loaded
	 */
	GameWindow(const string puzzle, int puzzleNumber);
	/**
	 * handles the check button inherited from OKCancelWindow
	 *
	 * Precondition: None
	 * Postcondition: None
	 */
	void okHandler();
	/**
	 * handles the quit button inherited from OKCancelWindow
	 *
	 * Precondition: None
	 * Postcondition: None
	 */
	void cancelHandler();
	/**
	 * destructor for gamewindow deletes all nodes and labels
	 *
	 * Precondition: None
	 * Postcondition: None
	 */
	virtual ~GameWindow();
};

} /* namespace view */

#endif /* VIEW_GAMEWINDOW_H_ */
