/*
 * MainWindow.cpp
 *
 *  Created on: Apr 12, 2023
 *      Author: cwill124
 */

#include "MainWindow.h"

namespace view {

MainWindow::MainWindow(int width, int height, const char *title) :
		Fl_Window(width, height, title) {
	// TODO Auto-generated constructor stub
	this->begin();
	this->label = new Fl_Box(125, 60, 70, 30, "nothing");
	this->quitButton = new Fl_Button(125, 150, 70, 30, "Quit");
	this->quitButton->callback(cb_quit, this);

	this->showNewWindowButton = new Fl_Button(125, 100, 70, 30, "Show");
	this->showNewWindowButton->callback(cb_show, this);

	this->end();
	this->resizable(this);
	this->show();

}

MainWindow::~MainWindow() {
	// TODO Auto-generated destructor stub
}
void MainWindow::cb_show(Fl_Widget *o, void *data) {
	cout << "button worked" << endl;

}

void MainWindow::cb_quit(Fl_Widget*, void *data) {
	((MainWindow*) data)->cb_quit_i();
}

void MainWindow::cb_data(Fl_Widget*, void *data) {

}

void MainWindow::cb_quit_i() {
	this->hide();
}

} /* namespace view */
