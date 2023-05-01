#ifndef VIEW_HIGHSCOREWINDOW_H_
#define VIEW_HIGHSCOREWINDOW_H_

#include <vector>
#include <Score.h>
#include <FL/Fl.H>
#include <Fl/Fl_Window.H>
#include <Fl/Fl_Button.H>
#include <Fl/Fl_Text_Display.H>
#include <Fl/Fl_Round_Button.H>
#include <ScoreManager.h>
#include <SortSelection.h>
#include <Utils.h>

using namespace utils;
using namespace enums;
using namespace std;
using namespace scores;

class HighScoreWindow: public Fl_Window {
private:
	static const int numberOfSortMethods = 2;
	SortSelection::Selection sortSelection;
	Fl_Text_Buffer *summaryOutputTextBuffer;
	vector<string> sortMethods = { "Sort by Time", "Sort by Number" };
	ScoreManager *manager;
	std::vector<Score> highScores;
	Fl_Button *resetButton;
	Fl_Button *backButton;
	Fl_Group *sortingRadioGroup;
	Fl_Round_Button *sortByButtons[numberOfSortMethods - 1];
	Fl_Text_Display *highScoresDisplay;
	static void cb_reset(Fl_Widget *widget, void *data);
	static void cb_back(Fl_Widget *widget, void *data);
	static void cb_sort_method_changed(Fl_Widget *widget, void *data);
	void cb_quit_i();

	void loadScoresSortedByTime(ScoreManager *manager);
	void loadScoresSortedByNumber(ScoreManager *manager);

	SortSelection::Selection getSortSelection();
	void setSortSelection(SortSelection::Selection sortSelection);
	ScoreManager* getManager();
public:
	/**
	 * The constructor for the high score window
	 *
	 * Precondition: None
	 * Postcondition: None
	 *
	 * Param: width the width
	 * Param: height the height
	 * Param: title the title
	 */
	HighScoreWindow(int width, int height, const char *title);
	/**
	 * The destructor for the high score window
	 *
	 * Precondition: None
	 * Postcondition: None
	 */
	virtual ~HighScoreWindow();
};

#endif /* VIEW_HIGHSCOREWINDOW_H_ */
