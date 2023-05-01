#include <ColorSettingsWindow.h>

namespace view {

ColorSettingsWindow::ColorSettingsWindow(int width, int height,
		const char *title) :
		Fl_Window(width, height, title) {
	this->begin();
	this->cellRGBValues = new int[Settings::RGBValueSize];
	this->textRGBValues = new int[Settings::RGBValueSize];
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
	ColorSettingsFileIO colorFileIO;
	int combinedRGBValues[Settings::RGBCombinedSize - 1];
	for (int i = 0; i < Settings::RGBValueSize; i++) {
		combinedRGBValues[i] = window->cellRGBValues[i];
	}
	for (int i = 0; i < Settings::RGBValueSize; i++) {
		combinedRGBValues[Settings::RGBValueSize + i] =
				window->textRGBValues[i];
	}
	colorFileIO.saveColorSettings(Settings::ColorSettingsFileName,
			combinedRGBValues, Settings::RGBCombinedSize);
	window->hide();
}

void ColorSettingsWindow::cb_setCellColor(Fl_Widget*, void *data) {
	ColorSettingsWindow *window = (ColorSettingsWindow*) data;
	ColorSettingsFileIO colorFileIO;
	int *RGBValues = window->getRGBValues();
	for (int i = 0; i < Settings::RGBValueSize; i++) {
		window->cellRGBValues[i] = RGBValues[i];
	}
	delete[] RGBValues;
}

void ColorSettingsWindow::cb_setTextColor(Fl_Widget*, void *data) {
	ColorSettingsWindow *window = (ColorSettingsWindow*) data;
	ColorSettingsFileIO colorFileIO;
	int *RGBValues = window->getRGBValues();
	for (int i = 0; i < Settings::RGBValueSize; i++) {
		window->textRGBValues[i] = RGBValues[i];
	}
	delete[] RGBValues;
}

int* ColorSettingsWindow::getRGBValues() {
	int *colorValues = new int[Settings::RGBValueSize];
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
	ColorSettingsWindow *window = (ColorSettingsWindow*) data;
	for (int i = 0; i < Settings::RGBValueSize; i++) {
		window->cellRGBValues[i] = Settings::RGBMaxValue;
		window->textRGBValues[i] = Settings::RGBMinValue;
	}
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

	delete[] this->cellRGBValues;

	delete[] this->textRGBValues;
}

} /* namespace view */
