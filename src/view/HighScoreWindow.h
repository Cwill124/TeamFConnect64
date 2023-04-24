/*
 * HighScoreWindow.h
 *
 *  Created on: Apr 24, 2023
 *      Author: adecesa1
 */

#ifndef VIEW_HIGHSCOREWINDOW_H_
#define VIEW_HIGHSCOREWINDOW_H_

#include <vector>
#include <Score.h>
#include <FL/Fl.H>
#include <Fl/Fl_Window.H>
#include <Fl/Fl_Button.H>
#include <Fl/Fl_Text_Display.H>
#include <Fl/Fl_Round_Button.H>

using namespace std;
using namespace scores;

class HighScoreWindow : public Fl_Window {
private:
	vector<string> sortMethods = { "Sort by Time", "Sort by Number" };
	std::vector<Score> highScores;
	Fl_Button* resetButton;
	Fl_Button* backButton;
	Fl_Group *sortingRadioGroup;
	Fl_Round_Button *sortByTimeButton;
	Fl_Round_Button *sortByPuzzleNumberButton;
	Fl_Text_Display* highScoresDisplay;
	void cbReset(Fl_Widget* widget, void* data);
	void cbBack(Fl_Widget* widget, void* data);
public:
	HighScoreWindow(int width, int height, const char *title);
	virtual ~HighScoreWindow();
};

#endif /* VIEW_HIGHSCOREWINDOW_H_ */
