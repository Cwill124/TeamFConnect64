/*
 * GameWindow.cpp
 *
 *  Created on: Apr 13, 2023
 *      Author: cwill124
 */

#include "GameWindow.h"
using namespace errormessages;
namespace view {

GameWindow::GameWindow() :
		OKCancelWindow(350, 350, "") {
	begin();
	this->setOKLocation(45, 300);
	this->setCancelLocation(145, 300);
	this->resetButton = new Fl_Button(245, 300, 70, 30, "Reset");
	this->resetButton->callback(cb_resetBoard, this);
	this->createBoxes();
	this->loadGameBoard();
	this->gameOutputText = new Fl_Box(70, 10, 200, 30);
	end();
	this->resizable(this);

}

void GameWindow::createBoxes() {
	int xShift = -5;
	int yShift = -20;
	int tileSize = 30;
	for (int i = 1; i < 9; i++) {
		int Y = (i * tileSize);
		for (int j = 1; j < 9; j++) {
			int X = (j * tileSize);

			Fl_Input *input = new Fl_Input(xShift + (X + tileSize),
					yShift + (Y + tileSize), tileSize, tileSize);
			input->when(FL_WHEN_CHANGED);
			input->callback(cb_getValue, this);
			this->inputBoxes.push_back(input);
		}
	}

}
bool GameWindow::checkOtherInputValues(Fl_Widget *widget) {
	Fl_Input *input = (Fl_Input*) widget;
	const char *iValue = input->value();
	for (vector<Fl_Input*>::size_type i = 0; i < this->inputBoxes.size(); i++) {
		Fl_Input *currentInput = this->inputBoxes[i];
		const char *value = currentInput->value();
		if (currentInput != input) {
			if (strcmp(iValue, value) == 0) {
				return true;
			}
		}
	}
	return false;
}
void GameWindow::cb_getValue(Fl_Widget *widget, void *data) {
	Fl_Input *input = (Fl_Input*) widget;
	GameWindow *window = (GameWindow*) data;
	const char *value = input->value();
	regex pattern("^[^a-zA-Z]*$");
	regex patternNumbers("([1-5]?[0-9]|6[0-4])");
	if (!regex_match(value, pattern) || !regex_match(value, patternNumbers)) {
		input->value("");

		window->gameOutputText->label(ErrorMessages::InvalidInputValue);
		return;
	}else if(window->checkOtherInputValues(input)){
		input->value("");
		window->gameOutputText->label(ErrorMessages::DuplicateInput);
		return;
	}
	window->gameOutputText->label("");
	printf("Input value: %s\n", value);
}
void GameWindow::cb_resetBoard(Fl_Widget *widget, void *data) {
	GameWindow *window = (GameWindow*) data;
	for (vector<Fl_Input*>::size_type i = 0; i < window->inputBoxes.size();
			i++) {
		PuzzleNode *node = window->puzzleNodeManager.getPuzzleNodes()[i];
		if (!window->inputBoxes[i]->readonly()) {
			window->inputBoxes[i]->value("");
			if (node != nullptr) {
				window->puzzleNodeManager.deletePuzzleNode(i);
			}
		}
	}
}
void GameWindow::cancelHandler() {
	this->hide();
}

void GameWindow::setNewNodeValues() {
	for (vector<Fl_Input*>::size_type i = 0; i < this->inputBoxes.size(); i++) {
		const char *value = this->inputBoxes[i]->value();
		PuzzleNode *node = this->puzzleNodeManager.getPuzzleNodes()[i];
		if (strlen(value) != 0 || value == nullptr) {
			if (node == nullptr) {
				cout << "null" << endl;
				this->puzzleNodeManager.addPuzzleNode(i, stoi(value), false);
			} else {
				cout << "setting value" << endl;
				node->setValue(stoi(value));
			}
		}
	}
}

void GameWindow::okHandler() {
	setNewNodeValues();
	cout << this->puzzleNodeManager.toString() << endl;
	if (this->puzzleNodeManager.isSolved()) {
		this->gameOutputText->label("");
		AlertWindow winningWindow("Solution Correct");
		winningWindow.set_modal();
		winningWindow.show();
		while (winningWindow.shown()) {
			Fl::wait();
		}
	} else {
		this->gameOutputText->label(ErrorMessages::IncorrectSolution);
	}
}
void GameWindow::loadGameBoard() {
	this->puzzleNodeManager.loadNodes(Settings::CurrentPuzzleFileName);
	for (vector<PuzzleNode*>::size_type i = 0;
			i < this->puzzleNodeManager.getPuzzleNodes().size(); i++) {
		PuzzleNode *currentPuzzleNode =
				this->puzzleNodeManager.getPuzzleNodes()[i];

		if (currentPuzzleNode != nullptr) {
			int value = currentPuzzleNode->getValue();
			const char *newInputValue = to_string(value).c_str();
			this->inputBoxes[i]->value(newInputValue);
			if (currentPuzzleNode->getIsStarting()) {
				this->inputBoxes[i]->readonly(true);
				this->inputBoxes[i]->deactivate();
			}
		}

	}
}

int GameWindow::getInputBoxIndex(Fl_Input *inputBox) {
	for (vector<Fl_Input*>::size_type i = 0; i < this->inputBoxes.size(); i++) {
		if (inputBox == this->inputBoxes[i]) {
			cout << i << endl;
			return i;
		}
	}
	return -1;
}

void GameWindow::deleteInputBoxes() {
	for (vector<Fl_Input*>::size_type i = 0; i < this->inputBoxes.size(); i++) {
		this->inputBoxes[i] = nullptr;
		delete this->inputBoxes[i];
	}
}

GameWindow::~GameWindow() {
	this->puzzleNodeManager.resetBoard();
	this->deleteInputBoxes();
}

} /* namespace view */
