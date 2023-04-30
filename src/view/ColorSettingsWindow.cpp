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
	this->resetColors = new Fl_Button(200, 5, 70, 30, "Reset");
	this->resetColors->callback(cb_resetColors, this);
	this->end();

}

void ColorSettingsWindow::cb_return(Fl_Widget*, void *data) {
	ColorSettingsWindow *window = (ColorSettingsWindow*) data;
	window->hide();
}

void ColorSettingsWindow::cb_setCellColor(Fl_Widget*, void *data) {
	ColorSettingsWindow *window = (ColorSettingsWindow*) data;
	ColorSettingsFileIO colorFileIO;
	int *RGBValues = window->getRGBValues();
	colorFileIO.saveColorSettings(Settings::ColorSettingsFileNames[0],
			RGBValues[0], RGBValues[1], RGBValues[2]);
	delete[] RGBValues;
}

void ColorSettingsWindow::cb_setTextColor(Fl_Widget*, void *data) {
	ColorSettingsWindow *window = (ColorSettingsWindow*) data;
	ColorSettingsFileIO colorFileIO;

	int *RGBValues = window->getRGBValues();
	colorFileIO.saveColorSettings(Settings::ColorSettingsFileNames[1],
			RGBValues[0], RGBValues[1], RGBValues[2]);
	delete[] RGBValues;
}

int* ColorSettingsWindow::getRGBValues() {
	int *colorValues = new int[3];
	float floatR = this->colorChooser->r();
	float floatG = this->colorChooser->g();
	float floatB = this->colorChooser->b();
	int R = floatR * Settings::RGBMaxValue;
	int G = floatG * Settings::RGBMaxValue;
	int B = floatB * Settings::RGBMaxValue;
	colorValues[0] = R;
	colorValues[1] = G;
	colorValues[2] = B;
	return colorValues;
}

void ColorSettingsWindow::cb_resetColors(Fl_Widget*, void *data) {
	ColorSettingsFileIO colorFileIO;
	colorFileIO.saveColorSettings(Settings::ColorSettingsFileNames[1],Settings::RGBMinValue, Settings::RGBMinValue,Settings::RGBMinValue);
	colorFileIO.saveColorSettings(Settings::ColorSettingsFileNames[0], Settings::RGBMaxValue,Settings::RGBMaxValue,
			Settings::RGBMaxValue);
}

ColorSettingsWindow::~ColorSettingsWindow() {
	this->colorChooser = nullptr;
	delete this->colorChooser;

	this->resetColors = nullptr;
	delete this->resetColors;

	this->returnToMenuButton = nullptr;
	delete this->returnToMenuButton;

	this->setCellColorButton = nullptr;
	delete this->setCellColorButton;

	this->setTextColorButton = nullptr;
	delete this->setTextColorButton;
}

} /* namespace view */
