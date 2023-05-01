#include <ColorSettingsFileIO.h>

namespace fileio {

ColorSettingsFileIO::ColorSettingsFileIO() {

}

ColorSettingsFileIO::~ColorSettingsFileIO() {

}

vector<Fl_Color> ColorSettingsFileIO::loadColorSettings(
		const string &filename) {
	std::ifstream colorFile(filename);
	string line;
	vector<int> RGBValues;
	vector<Fl_Color> colors;
	Fl_Color textColor = fl_rgb_color(Settings::RGBMinValue,
			Settings::RGBMinValue, Settings::RGBMinValue);
	Fl_Color cellColor = fl_rgb_color(Settings::RGBMaxValue,
			Settings::RGBMaxValue, Settings::RGBMaxValue);
	while (std::getline(colorFile, line)) {
		std::stringstream stream(line);
		string R;
		string G;
		string B;
		string value;
		while (std::getline(stream, value, ',')) {
			RGBValues.push_back(stoi(value));
		}
	}
	cellColor = fl_rgb_color(RGBValues[0], RGBValues[1], RGBValues[2]);
	colors.push_back(cellColor);
	textColor = fl_rgb_color(RGBValues[3], RGBValues[4], RGBValues[5]);
	colors.push_back(textColor);
	colorFile.close();
	return colors;
}

void ColorSettingsFileIO::saveColorSettings(const string &filename,
		int *RGBArray, int RGBArraySize) {
	if (RGBArray == nullptr) {
		throw new invalid_argument(ErrorMessages::RGBArrayNull);
	}

	std::ofstream outputFile(filename);
	for (int i = 0; i < RGBArraySize; i++) {
		if (i == RGBArraySize - 1) {
			outputFile << to_string(RGBArray[i]);
		} else {
			outputFile << to_string(RGBArray[i]) + ",";
		}

	}

	outputFile.close();
}

} /* namespace fileio */
