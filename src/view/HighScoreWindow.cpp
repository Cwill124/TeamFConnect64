/*
 * HighScoreWindow.cpp
 *
 *  Created on: Apr 24, 2023
 *      Author: adecesa1
 */

#include <HighScoreWindow.h>
#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Round_Button.H>

HighScoreWindow::HighScoreWindow(int width, int height, const char *title) :
	Fl_Window(width, height, title) {
	this->begin();
	this->backButton = new Fl_Button(60, 160, 70, 30, "Back");
	this->resetButton = new Fl_Button(240, 160, 70, 30, "Reset");
	this->highScoresDisplay = new Fl_Text_Display(10, 60, 300, 30);

	this->sortingRadioGroup = new Fl_Group(10, 10, 400, 100);
	this->sortingRadioGroup->begin();

	int xIncrement = 170;
	int buttonX = 10;
	int buttonY = 10;
	int buttonWidth = 200;
	int buttonHeight = 12;

	for (unsigned int i = 0; i < this->sortMethods.size(); i++) {
		this->sortByPuzzleNumberButton = new Fl_Round_Button((buttonX + (xIncrement * i)), buttonY, buttonWidth, buttonHeight, this->sortMethods[i].c_str());
	}

	this->sortByPuzzleNumberButton[1].set();
	this->sortingRadioGroup->end();

	this->end();
	this->resizable(this);
	this->show();


}

HighScoreWindow::~HighScoreWindow() {
	// TODO Auto-generated destructor stub
}

