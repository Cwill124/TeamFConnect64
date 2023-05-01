#include "Utils.h"
#include <string>
#include <iomanip>

using namespace utils;

Utils::Utils() {

}

Utils::~Utils() {

}

std::string Utils::convertIntegerToTimeString(int seconds) {
	const int secondsInHour = 3600;
	const int secondsInMinute = 60;

	int hours = seconds / secondsInHour;
	int minutes = (seconds % secondsInHour) / secondsInMinute;
	int remainingSeconds = seconds % secondsInMinute;

	std::ostringstream timeStream;
	timeStream << std::setfill('0') << std::setw(2) << hours << ":"
			<< std::setw(2) << minutes << ":" << std::setw(2)
			<< remainingSeconds;

	return timeStream.str();
}

