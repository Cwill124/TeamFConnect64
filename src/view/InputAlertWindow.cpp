/*
 * InputAlertWindow.cpp
 *
 *  Created on: Apr 25, 2023
 *      Author: adecesa1
 */

#include <InputAlertWindow.h>

InputAlertWindow::InputAlertWindow(const char *title)
		: Fl_Window(300, 110, title) {
	this->playerName = "";
	this->begin();
	correctLabel = new Fl_Box(10, 0, 300, 25, "Your solution was correct!");
    input = new Fl_Input(60, 30, 200, 25, "Name:");

    ok_button = new Fl_Button(10, 70, 80, 25, "OK");
    ok_button->callback(cb_ok, this);
    cancel_button = new Fl_Button(210, 70, 80, 25, "Cancel");
    cancel_button->callback(cb_cancel);

    this->end();
}

string InputAlertWindow::getPlayerName() {
	return this->playerName;
}

void InputAlertWindow::setPlayerName(string name) {
	this->playerName = name;
}

void InputAlertWindow::cb_ok(Fl_Widget* widget, void* data) {
	InputAlertWindow* inputAlertWindow = (InputAlertWindow*) data;

    string playerName(inputAlertWindow->input->value());
    inputAlertWindow->setPlayerName(playerName);

    widget->parent()->hide();
}

void InputAlertWindow::cb_cancel(Fl_Widget* widget, void* data) {
    widget->parent()->hide();
}

InputAlertWindow::~InputAlertWindow() {
	this->correctLabel = nullptr;
	delete this->correctLabel;
	this->ok_button = nullptr;
	delete this->ok_button;
	this->cancel_button = nullptr;
	delete this->cancel_button;
	this->input = nullptr;
	delete this->input;
}

