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
#include "ErrorMessages.h"
using namespace std;
using namespace errormessages;
namespace fileio {
/**
 * class for handling ColorSettings IO
 */
class ColorSettingsFileIO {
public:
	/**
	 * constructor for ColorSettingsFileIO
	 */
	ColorSettingsFileIO();
	/**
	 * deconstructor for ColorSettingsFileIO
	 */
	virtual ~ColorSettingsFileIO();
	/**
	 * loads a color file and returns the color based on the RGB values stored
	 *
	 * @Param filename the name of the file
	 *
	 * @return a Fl_Color object
	 */
	Fl_Color loadColorSettings(const string &filename);
	/**
	 * saves RGB values to a file
	 * @Param R the red color value
	 * @Param G the green color value
	 * @Param B the blue color value
	 *
	 * @precondition R,G,B must be greater than -1 and less than 256
	 *
	 *
	 */
	void saveColorSettings(const string &filename, int R, int G, int B);

};

} /* namespace fileio */

#endif /* FILEIO_COLORSETTINGSFILEIO_H_ */
