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
/**
 * Alert window for win the user finds the correct solution
 */
class AlertWindow: public Fl_Window {
private:
	Fl_Box *message;
	Fl_Button *closeAlertButton;
	static void cb_close(Fl_Widget *widget, void *data);
	void closeWindow();
public:
	/**
	 * Creates a alert window with custom message
	 *
	 * @param message the message that will be displayed
	 *
	 * @postcondition message will be set to the inputed messaged
	 */
	AlertWindow(const char *message);
	virtual ~AlertWindow();
};

} /* namespace view */

#endif /* VIEW_ALERTWINDOW_H_ */
