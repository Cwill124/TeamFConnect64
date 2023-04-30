/*
 * ColorSettingsWindow.cpp
 *
 *  Created on: Apr 29, 2023
 *      Author: cwill124
 */

#include <ColorSettingsWindow.h>

namespace view {

ColorSettingsWindow::ColorSettingsWindow(int width, int height,
		const char *title) :
		Fl_Window(width, height, title) {
	this->begin();
	this->colorChooser = new Fl_Color_Chooser(50, 50, 200, 200);
	this->setCellColorButton = new Fl_Button(30, 260, 110, 30,
			"Set Cell Color");
	this->setCellColorButton->callback(cb_setCellColor, this);
	this->setTextColorButton = new Fl_Button(150, 260, 110, 30,
			"Set Text Color");
	this->setTextColorButton->callback(cb_setTextColor, this);
	this->returnToMenuButton = new Fl_Button(30, 5, 70, 30, "Return");
	this->returnToMenuButton->callback(cb_return, this);
	this->end();

}

void ColorSettingsWindow::cb_return(Fl_Widget*, void *data) {
	ColorSettingsWindow *window = (ColorSettingsWindow*) data;
	window->hide();
}

void ColorSettingsWindow::cb_setCellColor(Fl_Widget*, void *data) {
	ColorSettingsWindow *window = (ColorSettingsWindow*) data;
	ColorSettingsFileIO colorFileIO;
	float floatR = window->colorChooser->r();
	float floatG = window->colorChooser->g();
	float floatB = window->colorChooser->b();
	int R = floatR * 255;
	int G = floatG * 255;
	int B = floatB * 255;
	cout << R << endl;
	cout << G << endl;
	cout << B << endl;
	colorFileIO.saveColorSettings(Settings::ColorSettingsFileNames[0], R, G, B);
}

void ColorSettingsWindow::cb_setTextColor(Fl_Widget*, void *data) {
	ColorSettingsWindow *window = (ColorSettingsWindow*) data;
	ColorSettingsFileIO colorFileIO;
	float floatR = window->colorChooser->r();
	float floatG = window->colorChooser->g();
	float floatB = window->colorChooser->b();
	int R = floatR * 255;
	int G = floatG * 255;
	int B = floatB * 255;
	cout << R << endl;
	cout << G << endl;
	cout << B << endl;
	colorFileIO.saveColorSettings(Settings::ColorSettingsFileNames[1], R, G, B);
}

ColorSettingsWindow::~ColorSettingsWindow() {
	this->colorChooser = nullptr;
	delete this->colorChooser;
}

} /* namespace view */
