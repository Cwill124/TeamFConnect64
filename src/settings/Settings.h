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
	static constexpr int NumberOfPuzzleNodes = 64;
	/**
	 * The maximum row amount
	 */
	static constexpr int MaximumRowAmount = 8;
	/**
	 * The maximum high scores
	 */
	static constexpr int MaximumHighScores = 10;
	/**
	 * The current puzzle file name
	 */
	static const string CurrentPuzzleFileName;
	/**
	 * The high scores file name
	 */
	static const string HighScoresFileName;
	/**
	 * The file names for the puzzles
	 */
	static const char* PuzzleFileNames[];

	static int puzzleSelected;
};
}

#endif /* SETTINGS_SETTINGS_H_ */
