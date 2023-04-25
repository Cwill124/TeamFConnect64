/*
 * MainWindow.cpp
 *
 *  Created on: Apr 12, 2023
 *      Author: cwill124
 */

#include "MainWindow.h"
#include "HighScoreWindow.h"

using namespace std;

namespace view {

MainWindow::MainWindow(int width, int height, const char *title) :
		Fl_Window(width, height, title) {
	this->begin();

	this->showNewWindowButton = new Fl_Button(125, 110, 100, 30, "Start");
	this->showNewWindowButton->callback(cb_show, this);
	this->resumePuzzleButton = new Fl_Button(125, 70, 100, 30, "Resume");
	this->resumePuzzleButton->callback(cb_resumePuzzle, this);
	this->highScoresButton = new Fl_Button(125, 150, 100, 30, "High Scores");
	this->highScoresButton->callback(cb_high_scores, this);
	this->quitButton = new Fl_Button(125, 190, 100, 30, "Quit");
	this->quitButton->callback(cb_quit, this);
	this->puzzleSelector = new Fl_Choice(150, 20, 50, 20, "Select Puzzle");
	this->errorMessage = new Fl_Box(50, 40, 200, 30);
	this->errorMessage->labelcolor(FL_RED);
	this->addLevelOptions();
	this->end();
	this->resizable(this);
	this->show();

}

MainWindow::~MainWindow() {

}
void MainWindow::addLevelOptions() {
	//TODO This needs to be cleaned up
	for (int i = 1; i <= 4; i++) {
		string level = to_string(i);
		const char *level_cstr = level.c_str();
		this->puzzleSelector->add(level_cstr);
	}
	this->puzzleSelector->value(0);

}
void MainWindow::cb_show(Fl_Widget *o, void *data) {
	MainWindow *window = (MainWindow*) data;

	cout << window->puzzleSelector->value() << endl;
	cout << Settings::PuzzleFileNames[window->puzzleSelector->value()] << endl;
	string puzzle = Settings::PuzzleFileNames[window->puzzleSelector->value()];
	GameWindow gameWindow(puzzle, window->puzzleSelector->value());
	gameWindow.set_modal();
	gameWindow.show();
	while (gameWindow.shown()) {
		Fl::wait();
	}

}

void MainWindow::cb_resumePuzzle(Fl_Widget*, void *data) {
	MainWindow *window = (MainWindow*) data;

	cout << window->puzzleSelector->value() << endl;
	cout << Settings::PuzzleFileNames[window->puzzleSelector->value()] << endl;
	string puzzle = Settings::PuzzleFileNames[window->puzzleSelector->value()];
	puzzle = "current" + puzzle;
	ifstream file(puzzle);
	if (file.good()) {
		GameWindow gameWindow(puzzle, window->puzzleSelector->value());
		gameWindow.set_modal();
		gameWindow.show();
		while (gameWindow.shown()) {
			Fl::wait();
		}
	} else {
		window->errorMessage->label(ErrorMessages::PuzzleCouldNotBeFound);
	}

}

void MainWindow::cb_quit(Fl_Widget*, void *data) {
	((MainWindow*) data)->cb_quit_i();
}

void MainWindow::cb_high_scores(Fl_Widget*, void *data) {
	MainWindow *window = (MainWindow*) data;
	HighScoreWindow highScoreWindow(325, 250, "High Scores");
	highScoreWindow.set_modal();
	highScoreWindow.show();
	while (highScoreWindow.shown()) {
		window->hide();
		Fl::wait();
	}
	window->show();
}

void MainWindow::cb_data(Fl_Widget*, void *data) {

}

void MainWindow::cb_quit_i() {
	this->hide();
}

} /* namespace view */
