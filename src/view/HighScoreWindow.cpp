/*
 * HighScoreWindow.cpp
 *
 *  Created on: Apr 24, 2023
 *      Author: adecesa1
 */

#include <HighScoreWindow.h>
#include <FL/Fl.H>
#include <FL/Fl_Window.H>

HighScoreWindow::HighScoreWindow(int width, int height, const char *title) :
	Fl_Window(width, height, title) {
	this->begin();
	this->backButton = new Fl_Button(60, 160, 70, 30, "Back");
	this->resetButton = new Fl_Button(240, 160, 70, 30, "Reset");
	this->highScoresDisplay = new Fl_Text_Display(10, 10, 70, 30);

	this->sortingRadioGroup = new Fl_Group(35, 45, 400, 100);
	this->sortingRadioGroup->begin();

	this->sortingRadioGroup->end();

	this->sortingRadioGroup->end();
	this->end();
	this->resizable(this);
	this->show();


}

HighScoreWindow::~HighScoreWindow() {
	// TODO Auto-generated destructor stub
}

