#include "Utils.h"

using namespace utils;

Utils::Utils() {
	// TODO Auto-generated constructor stub

}

Utils::~Utils() {
	// TODO Auto-generated destructor stub
}

#include <string>
#include <iomanip>

std::string Utils::convertIntegerToTimeString(int seconds) {
    const int secondsInHour = 3600;
    const int secondsInMinute = 60;

    int hours = seconds / secondsInHour;
    int minutes = (seconds % secondsInHour) / secondsInMinute;
    int remainingSeconds = seconds % secondsInMinute;

    std::ostringstream timeStream;
    timeStream << std::setfill('0') << std::setw(2) << hours << ":"
               << std::setw(2) << minutes << ":"
               << std::setw(2) << remainingSeconds;

    return timeStream.str();
}



