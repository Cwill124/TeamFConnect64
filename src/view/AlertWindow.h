/*
 * AlertWindow.h
 *
 *  Created on: Apr 19, 2023
 *      Author: cwill124
 */

#ifndef VIEW_ALERTWINDOW_H_
#define VIEW_ALERTWINDOW_H_
#include <Fl/Fl_Input.H>
#include <Fl/Fl_Box.H>
#include <Fl/Fl_Button.H>
#include "OKCancelWindow.h"
#include "MainWindow.h"
#include "PuzzleNodeManager.h"
#include "Settings.h"
#include "PuzzleNode.h"
#include "ErrorMessages.h"
#include <vector>
#include <iostream>
#include <regex>
namespace view {

class AlertWindow: public Fl_Window {
private:
	Fl_Box *messege;
	Fl_Button* closeAlertButton;
	static void cb_close(Fl_Widget *widget, void *data);
	void closeWindow();
public:
	AlertWindow(const char *message);
	virtual ~AlertWindow();
};

} /* namespace view */

#endif /* VIEW_ALERTWINDOW_H_ */
