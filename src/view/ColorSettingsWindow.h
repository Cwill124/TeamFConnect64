/*
 * ColorSettingsWindow.h
 *
 *  Created on: Apr 29, 2023
 *      Author: cwill124
 */

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
#include "Settings.h"
#include "ErrorMessages.h"
#include "ColorSettingsFileIO.h"
using namespace settings;
using namespace fileio;
namespace view {

class ColorSettingsWindow: public Fl_Window {
private:
	Fl_Color_Chooser *colorChooser;
	Fl_Button *setTextColorButton;
	Fl_Button *setCellColorButton;
	Fl_Button *returnToMenuButton;
	static void cb_return(Fl_Widget*, void*);
	static void cb_setCellColor(Fl_Widget*, void*);
	static void cb_setTextColor(Fl_Widget*, void*);
public:
	ColorSettingsWindow(int width, int height, const char *title);
	virtual ~ColorSettingsWindow();
};

} /* namespace view */

#endif /* VIEW_COLORSETTINGSWINDOW_H_ */
