/*
 * GameWindow.cpp
 *
 *  Created on: Apr 13, 2023
 *      Author: cwill124
 */

#include "GameWindow.h"

namespace view {

GameWindow::GameWindow() :
		OKCancelWindow(350, 350, "Movie to add") {

	begin();
	this->puzzleLevel = new Fl_Box(100, 10, 70, 30, "nothing");
	this->setOKLocation(75, 300);
	this->setCancelLocation(205, 300);
	this->createBoxes();
	end();
	this->resizable(this);

}

void GameWindow::createBoxes() {
	int xShift = -5;
	int yShift = -20;
	for (int i = 1; i < 9; i++) {
		int Y = (i * 30);
		for (int j = 1; j < 9; j++) {
			int X = (j * 30);

			Fl_Input *input = new Fl_Input(xShift + (X + 30), yShift + (Y + 30),
					30, 30);
			input->when(FL_WHEN_CHANGED);
			input->callback(cb_getValue);
			this->inputBoxes.push_back(input);
		}
	}

}
bool GameWindow::checkOtherInputValues(){

}
void GameWindow::cb_getValue(Fl_Widget *widget, void *data) {
	Fl_Input *input = (Fl_Input*) widget;
	const char *value = input->value();
	regex pattern("^[^a-zA-Z]*$");
	if (!regex_match(value, pattern)) {
		input->value("");
		cout << "T" << endl;
	}
	printf("Input value: %s\n", value);
}
void GameWindow::cancelHandler() {
	this->hide();
}
void GameWindow::okHandler() {
	for (size_t i = 0; i < this->inputBoxes.size(); i++) {
		const char *value = this->inputBoxes[i]->value();
		printf("Input %lu value: %s\n", i, value);
	}

}
GameWindow::~GameWindow() {

}

} /* namespace view */
