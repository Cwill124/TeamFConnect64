/*
 * The settings
 */

#ifndef SETTINGS_SETTINGS_H_
#define SETTINGS_SETTINGS_H_
#include <FL/fl_draw.H>
#include <string>
#include <FL/Fl.H>

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
	 * The time increment if a hint is viewed
	 */
	static constexpr int HintTimeIncrement = 15;
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
	static const char *PuzzleFileNames[];
	/**
	 * The number of Puzzles
	 */
	static constexpr int NumberOfPuzzles = 12;
	/**
	 * The size of the board
	 */
	static constexpr int SizeOfBoard = 8;
	/**
	 * The cell color filename
	 */
	static const char *ColorSettingsFileNames[];
	/**
	 * The Max value for RGB
	 */
	static constexpr int RGBMaxValue = 255;
	/**
	 * The Min value for RGB
	 */
	static constexpr int RGBMinValue = 0;

};
}

#endif /* SETTINGS_SETTINGS_H_ */
