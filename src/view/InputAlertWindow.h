/*
 * InputAlertWindow.h
 *
 *  Created on: Apr 25, 2023
 *      Author: adecesa1
 */

#ifndef VIEW_INPUTALERTWINDOW_H_
#define VIEW_INPUTALERTWINDOW_H_

#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Box.H>
#include <string>

using namespace std;

class InputAlertWindow : public Fl_Window {
private:
	string playerName;
	Fl_Window* window;
	Fl_Box* correctLabel;
	Fl_Input* input;
	Fl_Button* ok_button;
	Fl_Button* cancel_button;
public:
	InputAlertWindow(const char *title);
	virtual ~InputAlertWindow();

	string getPlayerName();
	void setPlayerName(string name);

	static void cb_ok(Fl_Widget* widget, void* data);
	static void cb_cancel(Fl_Widget* widget, void* data);
};

#endif /* VIEW_INPUTALERTWINDOW_H_ */
