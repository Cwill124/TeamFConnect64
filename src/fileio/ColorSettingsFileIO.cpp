/*
 * ColorSettingsFileIO.cpp
 *
 *  Created on: Apr 29, 2023
 *      Author: cwill124
 */

#include <ColorSettingsFileIO.h>

namespace fileio {

ColorSettingsFileIO::ColorSettingsFileIO() {

}

ColorSettingsFileIO::~ColorSettingsFileIO() {

}

Fl_Color ColorSettingsFileIO::loadColorSettings(const string &filename) {
	std::ifstream colorFile(filename);
	string line;
	vector<int> RGBValues;
	Fl_Color color = fl_rgb_color(0, 0, 0);
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
	color = fl_rgb_color(RGBValues[0], RGBValues[1], RGBValues[2]);
	colorFile.close();
	return color;
}

void ColorSettingsFileIO::saveColorSettings(const string &filename, int R,
		int G, int B) {
	if (R < 0 || R > 255) {
		throw new invalid_argument(ErrorMessages::RGBValueInvalid);
	}
	if (G < 0 || G > 255) {
		throw new invalid_argument(ErrorMessages::RGBValueInvalid);
	}
	if (B < 0 || B > 255) {
		throw new invalid_argument(ErrorMessages::RGBValueInvalid);
	}
	std::ofstream outputFile(filename);
	outputFile << to_string(R) + "," + to_string(G) + "," + to_string(B)
			<< endl;
	outputFile.close();
}

} /* namespace fileio */
