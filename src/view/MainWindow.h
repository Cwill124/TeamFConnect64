/*
 * MainWindow.h
 *
 *  Created on: Apr 12, 2023
 *      Author: cwill124
 */

#ifndef VIEW_MAINWINDOW_H_
#define VIEW_MAINWINDOW_H_
#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Choice.H>
#include <FL/Fl_Box.H>
#include <iostream>
#include <fstream>
#include "ErrorMessages.h"
#include "ColorSettingsWindow.h"
#include "HighScoreWindow.h"
#include "GameWindow.h"
#include "ColorSettingsFileIO.h"
using namespace errormessages;
using namespace std;
namespace view {
/**
 * creates a MainWindow
 */
class MainWindow: public Fl_Window {
private:
	Fl_Button *quitButton;
	Fl_Button *highScoresButton;
	Fl_Button *showNewWindowButton;
	Fl_Button *resumePuzzleButton;
	Fl_Button *colorSettingsButton;
	Fl_Choice *puzzleSelector;
	Fl_Box *errorMessage;
	static void cb_show(Fl_Widget*, void*);
	static void cb_resumePuzzle(Fl_Widget*, void*);
	static void cb_data(Fl_Widget*, void*);
	static void cb_quit(Fl_Widget*, void*);
	static void cb_high_scores(Fl_Widget*, void*);
	static void cb_color_settings(Fl_Widget*, void*);
	inline void cb_quit_i();
	void addLevelOptions();
public:
	/**
	 * A mainwindow that allows user to select a puzzle and resume or play
	 *
	 * Precondition: None
	 * Postcondition: None
	 *
	 * Param: width the width of the window
	 * Param: height the height of the window
	 * Param: title the title of the window
	 */
	MainWindow(int width, int height, const char *title);
	virtual ~MainWindow();
};

} /* namespace view */

#endif /* VIEW_MAINWINDOW_H_ */
