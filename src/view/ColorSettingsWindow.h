#ifndef VIEW_COLORSETTINGSWINDOW_H_
#define VIEW_COLORSETTINGSWINDOW_H_
#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Choice.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Color_Chooser.H>
#include <FL/fl_draw.H>
#include <iostream>
#include <fstream>
#include <iterator>
#include <algorithm>

#include <vector>
#include "Settings.h"
#include "ErrorMessages.h"
#include "ColorSettingsFileIO.h"
using namespace settings;
using namespace fileio;
using namespace std;
namespace view {
/**
 * Class that is a window for the user to select color's for text and cells
 */
class ColorSettingsWindow: public Fl_Window {
private:
	Fl_Color_Chooser *colorChooser;
	Fl_Button *setTextColorButton;
	Fl_Button *setCellColorButton;
	Fl_Button *returnToMenuButton;
	Fl_Button *resetColors;
	int *cellRGBValues;
	int *textRGBValues;
	static void cb_return(Fl_Widget*, void*);
	static void cb_setCellColor(Fl_Widget*, void*);
	static void cb_setTextColor(Fl_Widget*, void*);
	static void cb_resetColors(Fl_Widget*, void*);
	vector<int> combineRGBValues();
	int* getRGBValues();
public:
	/**
	 * constructor for ColorSettingsWindow
	 *
	 *
	 * Precondition: None
	 * Postcondition: None
	 *
	 * Param: width the width of the window
	 * Param: height the height of the window
	 * Param: title the title of the window
	 *
	 */
	ColorSettingsWindow(int width, int height, const char *title);
	/**
	 * the destructor for the ColorSettingsWindow
	 *
	 * Precondition: None
	 * Postcondition: None
	 */
	virtual ~ColorSettingsWindow();
};

} /* namespace view */

#endif /* VIEW_COLORSETTINGSWINDOW_H_ */
