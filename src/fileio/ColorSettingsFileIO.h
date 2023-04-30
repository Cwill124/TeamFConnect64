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
#include "Settings.h"
using namespace std;
using namespace settings;
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
	 * Precondition: None
	 * Postcondition: None
	 *
	 * Param: filename the name of the file
	 *
	 * Returns: a vector of Fl_Color objects
	 */
	vector<Fl_Color> loadColorSettings(const string &filename);
	/**
	 * saves RGB values to a file
	 *
	 * Precondition: RGBArray != nullptr
	 * Postcondition: None
	 *
	 * Param: filename the file to save the values to
	 * Param: RGBArray the array that contains the RGB values
	 * Param: RGBArraySize the size of the array that contains the values
	 *
	 */
	void saveColorSettings(const string &filename, int *RGBArray,int RGBArraySize);

};

} /* namespace fileio */

#endif /* FILEIO_COLORSETTINGSFILEIO_H_ */
