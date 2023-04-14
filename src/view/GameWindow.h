/*
 * GameWindow.h
 *
 *  Created on: Apr 13, 2023
 *      Author: cwill124
 */

#ifndef VIEW_GAMEWINDOW_H_
#define VIEW_GAMEWINDOW_H_
#include <Fl/Fl_Input.H>
#include <Fl/Fl_Box.H>
#include "OKCancelWindow.h"
#include <vector>
#include <iostream>
#include <regex>
using namespace std;
namespace view {

class GameWindow: public OKCancelWindow {
private:
	vector<Fl_Input*> inputBoxes;
	Fl_Box* puzzleLevel;
	static void cb_getValue(Fl_Widget*, void*);
	void createBoxes();
	bool checkOtherInputValues();

public:
	GameWindow();
	GameWindow(void*);
	void okHandler();
	void cancelHandler();
	virtual ~GameWindow();
};

} /* namespace view */

#endif /* VIEW_GAMEWINDOW_H_ */
