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
}

void ColorSettingsFileIO::saveColorSettings(const string &filename, int R,
		int G, int B) {
	std::ofstream outputFile(filename);
	outputFile << to_string(R) + "," + to_string(G) + "," + to_string(B) << endl;
	outputFile.close();
}

} /* namespace fileio */
