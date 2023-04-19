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
class Utils final {
public:
	Utils();
	virtual ~Utils();
	static string convertIntegerToTimeString(int seconds);
};
}

#endif /* UTILS_UTILS_H_ */
