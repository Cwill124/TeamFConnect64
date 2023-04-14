/*
 * The settings
 */

#ifndef SETTINGS_SETTINGS_H_
#define SETTINGS_SETTINGS_H_

#include <string>

using namespace std;

namespace settings {
class Settings final {
public:
	/**
	 * The number of puzzle nodes
	 */
	static constexpr int NumberOfPuzzleNodes = 9;
	/**
	 * The maximum row amount
	 */
	static constexpr int MaximumRowAmount = 3;
	/**
	 * The current puzzle file name
	 */
	static const string CurrentPuzzleFileName;
	/**
	 * The file names for the puzzles
	 */
	static const char* PuzzleFileNames[];
};
}

#endif /* SETTINGS_SETTINGS_H_ */
