#ifndef OKCANCELWINDOW_H
#define OKCANCELWINDOW_H

#include <Fl/Fl_Window.H>
#include <Fl/Fl_Button.H>

namespace view {
/**
 * Abstract class that can be used for any window that needs Ok and Cancel buttons on it.
 */
class OKCancelWindow: public Fl_Window {
public:
	/**
	 * The window result
	 */
	enum WindowResult {
		OK, CANCEL, NONE
	};

private:
	Fl_Button *okButton;
	Fl_Button *cancelButton;

	WindowResult buttonInvoked;

	static void cbOk(Fl_Widget *widget, void *data);
	virtual void okHandler() = 0;

	static void cbCancel(Fl_Widget *widget, void *data);
	virtual void cancelHandler() = 0;

	void setWindowResult(OKCancelWindow::WindowResult result);
	OKCancelWindow::WindowResult getWindowResult();

public:
	/**
	 * The constructor for the ok cancel window
	 *
	 * Precondition: None
	 * Postcondition: None
	 *
	 * Param: width the window width
	 * Param: height the window height
	 * Param: title the window title
	 */
	OKCancelWindow(int width, int height, const char *title);
	/**
	 * The destructor for the ok cancel window
	 *
	 * Precondition: None
	 * Postcondition: None
	 */
	virtual ~OKCancelWindow();
	/**
	 * Sets the ok location
	 *
	 * Precondition: None
	 * Postcondition: The location is set to the specified x,y
	 *
	 * Param: x the x location
	 * Param: y the y location
	 */
	void setOKLocation(int x, int y);
	/**
	 * Sets the cancel location
	 *
	 * Precondition: None
	 * Postcondition: The location is set to the specified x,y
	 *
	 * Param: x the x location
	 * Param: y the y location
	 */
	void setCancelLocation(int x, int y);
};

}

#endif // OKCANCELWINDOW_H
