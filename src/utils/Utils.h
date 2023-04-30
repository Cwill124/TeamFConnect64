/*
 * Utils.h
 *
 *  Created on: Apr 18, 2023
 *      Author: adecesa1
 */

#ifndef UTILS_UTILS_H_
#define UTILS_UTILS_H_

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

namespace utils {
/**
 * utility class
 */
class Utils final {
public:
	/**
	 * constructor for the utility class
	 */
	Utils();
	/**
	 * deconstructor for the utility class
	 */
	virtual ~Utils();
	/**
	 * Converts integer to a formatted time string
	 *
	 * Precondition: None
	 * Postcondition: None
	 *
	 * Param: seconds the time to be converted to a string
	 *
	 * Returns: A formatted time string from the seconds Param
	 */
	static string convertIntegerToTimeString(int seconds);
};
}

#endif /* UTILS_UTILS_H_ */
