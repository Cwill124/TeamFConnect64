/*
 * AlertWindow.cpp
 *
 *  Created on: Apr 19, 2023
 *      Author: cwill124
 */

#include <AlertWindow.h>

namespace view {

AlertWindow::AlertWindow(const char *message) :
		Fl_Window(150, 150, message) {
	begin();
	this->messege = new Fl_Box(55, 30, 30, 50, message);
	this->closeAlertButton = new Fl_Button(45, 105, 70, 30, "Close");
	this->closeAlertButton->callback(cb_close, this);
	end();
}
void AlertWindow::cb_close(Fl_Widget *widget, void *data) {
	AlertWindow *window = (AlertWindow*) data;
	window->closeWindow();
}
void AlertWindow::closeWindow() {
	this->hide();
}
AlertWindow::~AlertWindow() {
	// TODO Auto-generated destructor stub
}

} /* namespace view */
