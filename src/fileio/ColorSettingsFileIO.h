/*
 * ColorSettingsFileIO.h
 *
 *  Created on: Apr 29, 2023
 *      Author: cwill124
 */

#ifndef FILEIO_COLORSETTINGSFILEIO_H_
#define FILEIO_COLORSETTINGSFILEIO_H_
#include <sstream>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <FL/fl_draw.H>
using namespace std;
namespace fileio {

class ColorSettingsFileIO {
public:
	ColorSettingsFileIO();
	virtual ~ColorSettingsFileIO();
	Fl_Color loadColorSettings(const string &filename);
	void saveColorSettings(const string &filename, int R, int G, int B);

};

} /* namespace fileio */

#endif /* FILEIO_COLORSETTINGSFILEIO_H_ */
