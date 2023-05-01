#ifndef VIEW_INPUTALERTWINDOW_H_
#define VIEW_INPUTALERTWINDOW_H_

#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Box.H>
#include <string>

using namespace std;
/**
 * The input alert window
 */
class InputAlertWindow: public Fl_Window {
private:
	string playerName;
	Fl_Window *window;
	Fl_Box *correctLabel;
	Fl_Input *input;
	Fl_Button *ok_button;
	Fl_Button *cancel_button;

	void setPlayerName(string name);

	static void cb_ok(Fl_Widget *widget, void *data);
	static void cb_cancel(Fl_Widget *widget, void *data);
public:
	/**
	 * The constructor for the input alert window
	 *
	 * Precondition: None
	 * Postcondition: None
	 *
	 * Param: title the title
	 */
	InputAlertWindow(const char *title);
	/**
	 * The destructor for the input alert window
	 *
	 * Precondition: None
	 * Postcondition: None
	 */
	virtual ~InputAlertWindow();
	/**
	 * Gets the player name
	 *
	 * Precondition: None
	 * Postcondition: None
	 *
	 * Return: The player name
	 */
	string getPlayerName();
};

#endif /* VIEW_INPUTALERTWINDOW_H_ */
