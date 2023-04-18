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
#include <FL/Fl_Box.H>
#include <iostream>
using namespace std;
namespace view {

class MainWindow: public Fl_Window {
private:
	Fl_Button *quitButton;
	Fl_Button *showNewWindowButton;
	Fl_Box *label;
	static void cb_show(Fl_Widget*, void*);

	static void cb_data(Fl_Widget*, void*);
	static void cb_quit(Fl_Widget*, void*);
	inline void cb_quit_i();
public:
	MainWindow(int width, int height, const char *title);
	virtual ~MainWindow();
};

} /* namespace view */

#endif /* VIEW_MAINWINDOW_H_ */
