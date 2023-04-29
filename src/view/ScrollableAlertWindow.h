#ifndef VIEW_SCROLLABLEALERTWINDOW_H_
#define VIEW_SCROLLABLEALERTWINDOW_H_
#include <FL/Fl.H>
#include <Fl/Fl_Input.H>
#include <Fl/Fl_Box.H>
#include <Fl/Fl_Button.H>
#include <Fl/Fl_Text_Display.H>
#include <FL/Fl_Scroll.H>
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
class ScrollableAlertWindow: public Fl_Window {
private:
	Fl_Text_Display *message;
	Fl_Scroll *scroll;
	Fl_Button *closeAlertButton;
	Fl_Text_Buffer* buffer;
	static void cb_close(Fl_Widget *widget, void *data);
	void closeWindow();
public:
	/**
	 * Creates a scrollable alert window with custom message
	 *
	 * Precondition: None
	 * Postcondition: message will be set to the inputed messaged
	 *
	 * Param: message the message that will be displayed
	 * Param: title the title that will be displayed
	 */
	ScrollableAlertWindow(const char *message, const char *title);
	/**
	 * The destructor for the scrollable alert window
	 *
	 * Precondition: None
	 * Postcondition: None
	 */
	virtual ~ScrollableAlertWindow();
};

}

#endif /* VIEW_SCROLLABLEALERTWINDOW_H_ */
