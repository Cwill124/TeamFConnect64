/*
 * HighScoreWindow.cpp
 *
 *  Created on: Apr 24, 2023
 *      Author: adecesa1
 */

#include <HighScoreWindow.h>
#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Round_Button.H>

HighScoreWindow::HighScoreWindow(int width, int height, const char *title) :
	Fl_Window(width, height, title) {
	this->begin();
	this->manager = ScoreManager();
	this->summaryOutputTextBuffer = new Fl_Text_Buffer();
	this->backButton = new Fl_Button(10, 210, 70, 30, "Back");
	this->backButton->callback(cb_back, this);
	this->resetButton = new Fl_Button(240, 210, 70, 30, "Reset");
	this->highScoresDisplay = new Fl_Text_Display(10, 30, 300, 170);
	this->highScoresDisplay->buffer(this->summaryOutputTextBuffer);

	this->sortSelection = SortSelection::TIME;

	this->sortingRadioGroup = new Fl_Group(10, 10, 400, 100);
	this->sortingRadioGroup->begin();

	int xIncrement = 170;
	int buttonX = 10;
	int buttonY = 10;
	int buttonWidth = 200;
	int buttonHeight = 12;

	for (unsigned int i = 0; i < this->sortMethods.size(); i++) {
		this->sortByPuzzleNumberButton[i] = new Fl_Round_Button((buttonX + (xIncrement * i)), buttonY, buttonWidth, buttonHeight, this->sortMethods[i].c_str());
		this->sortByPuzzleNumberButton[i]->type(FL_RADIO_BUTTON);
		this->sortByPuzzleNumberButton[i]->callback(cb_sort_method_changed, this);
	}

	this->sortingRadioGroup->end();
	this->sortByPuzzleNumberButton[0]->set();

	this->end();
	this->resizable(this);
	this->manager.loadScores();
	this->loadScoresSortedByTime(this->manager);
	this->show();
}

void HighScoreWindow::cb_back(Fl_Widget *widget, void *data) {
	((HighScoreWindow*) data)->cb_quit_i();
}

void HighScoreWindow::cb_reset(Fl_Widget *widget, void *data) {
	HighScoreWindow* highScoreWindow = (HighScoreWindow*) data;
	highScoreWindow->getManager().resetScores();
	highScoreWindow->getManager().saveScores();
}

void HighScoreWindow::cb_sort_method_changed(Fl_Widget *widget, void *data) {
	HighScoreWindow* highScoreWindow = (HighScoreWindow*) data;
	if (highScoreWindow->getSortSelection() == SortSelection::TIME) {
		highScoreWindow->loadScoresSortedByNumber(highScoreWindow->getManager());
		highScoreWindow->setSortSelection(SortSelection::NUMBER);
	} else if (highScoreWindow->getSortSelection() == SortSelection::NUMBER) {
		highScoreWindow->loadScoresSortedByTime(highScoreWindow->getManager());
		highScoreWindow->setSortSelection(SortSelection::TIME);
	}
}

ScoreManager HighScoreWindow::getManager() {
	return this->manager;
}

SortSelection::Selection HighScoreWindow::getSortSelection() {
	return this->sortSelection;
}

void HighScoreWindow::setSortSelection(SortSelection::Selection sortSelection) {
	this->sortSelection = sortSelection;
}

void HighScoreWindow::cb_quit_i() {
	this->hide();
}

void HighScoreWindow::loadScoresSortedByTime(ScoreManager manager) {
	this->manager.loadScores();
	vector<Score*> scores = manager.getScoresSortedByTime();
	string scoreString = "High Scores: \n";
	for (Score* score : scores) {
		string time = std::to_string(score->getTime());
		string name = score->getPlayerName();
		string number = std::to_string(score->getPuzzleNumber());
		scoreString += "  " + time + " By: " + name + " On Puzzle: " + number + "\n";
	}

	this->summaryOutputTextBuffer->text(scoreString.c_str());
}

void HighScoreWindow::loadScoresSortedByNumber(ScoreManager manager) {
	this->manager.loadScores();
	vector<Score*> scores = manager.getScoresSortedByPuzzleNumber();
	string scoreString = "High Scores: \n";
	for (Score* score : scores) {
		string time = std::to_string(score->getTime());
		string name = score->getPlayerName();
		string number = std::to_string(score->getPuzzleNumber());
		scoreString += "  " + time + " By: " + name + " On Puzzle: " + number + "\n";
	}

	this->summaryOutputTextBuffer->text(scoreString.c_str());
}

HighScoreWindow::~HighScoreWindow() {
	this->summaryOutputTextBuffer = 0;
	delete this->summaryOutputTextBuffer;

	this->backButton = 0;
	delete this->backButton;
}

