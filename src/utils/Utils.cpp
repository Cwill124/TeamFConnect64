/*
 * Utils.cpp
 *
 *  Created on: Apr 18, 2023
 *      Author: adecesa1
 */

#include "Utils.h"

using namespace utils;

Utils::Utils() {
	// TODO Auto-generated constructor stub

}

Utils::~Utils() {
	// TODO Auto-generated destructor stub
}

static string convertIntegerToTimeString(int seconds) {
	int secondsInHour = 3600;
	int secondsInMinute = 60;

    int hours = seconds / secondsInHour;
    int minutes = (seconds % secondsInHour) / secondsInMinute;
    int remainingSeconds = seconds % secondsInMinute;
    string timeString = std::to_string(hours) + ":" + std::to_string(minutes) + ":" + std::to_string(remainingSeconds);
    return timeString;
}



