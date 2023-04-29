/*
 * GameWindow.cpp
 *
 *  Created on: Apr 13, 2023
 *      Author: cwill124
 */

#include "GameWindow.h"
#include "ScoreManager.h"
using namespace errormessages;
using namespace scores;
namespace view {

GameWindow::GameWindow(const string puzzle, int puzzleNumber) :
		OKCancelWindow(350, 350, "") {
	begin();
	this->setOKLocation(10, 300);
	this->setCancelLocation(90, 300);
	this->resetButton = new Fl_Button(170, 300, 70, 30, "Reset");
	this->saveButton = new Fl_Button(250, 300, 70, 30, "Save");
	this->resetButton->callback(cb_resetBoard, this);
	this->saveButton->callback(cb_savePuzzle, this);
	this->puzzle = puzzle;
	this->puzzleNumber = puzzleNumber;
	this->label(this->puzzle.c_str());
	this->createBoxes();
	this->loadGameBoard();
	this->gameOutcomeLabel = new Fl_Box(70, 10, 200, 30);
	this->errorMessageBox = new Fl_Box(70, -5, 200, 30);
	this->errorMessageBox->labelcolor(FL_RED);
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
			input->callback(cb_getValue, this);
			input->textfont(FL_BOLD);
			this->inputBoxes.push_back(input);
		}
	}

}

void GameWindow::cb_getValue(Fl_Widget *widget, void *data) {
	Fl_Input *input = (Fl_Input*) widget;
	GameWindow *window = (GameWindow*) data;
	const char *value = input->value();
	regex pattern("^[^a-zA-Z]*$");
	regex patternNumbers("([1-5]?[0-9]|6[0-4])");
	if (strlen(value) == 0) {
		if (!window->setNewNodeValues()) {
			return;
		}
	}
	if (!regex_match(value, pattern) || !regex_match(value, patternNumbers)) {
		input->value("");
		window->errorMessageBox->label(ErrorMessages::InvalidInputValue);
		return;
	}
	if (!window->setNewNodeValues()) {
		input->value("");
		return;
	}
	window->errorMessageBox->label("");
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

bool GameWindow::setNewNodeValues() {
	for (vector<Fl_Input*>::size_type i = 0; i < this->inputBoxes.size(); i++) {
		const char *value = this->inputBoxes[i]->value();
		PuzzleNode *node = this->puzzleNodeManager.getPuzzleNodes()[i];
		if (strlen(value) != 0 || value == nullptr) {
			cout << "VALUE:" << endl;
			cout << value << endl;
			if (node == nullptr) {
				cout << "null" << endl;
				if (this->puzzleNodeManager.containsValue(stoi(value), node)) {
					this->errorMessageBox->label(ErrorMessages::DuplicateInput);
					return false;
				} else {
					this->puzzleNodeManager.addPuzzleNode(i, stoi(value),
							false);
				}
			} else {
				cout << "setting value" << endl;
				if (this->puzzleNodeManager.containsValue(stoi(value), node)) {
					this->errorMessageBox->label(ErrorMessages::DuplicateInput);
					this->puzzleNodeManager.deletePuzzleNode(i);
					return false;
				} else {
					node->setValue(stoi(value));
				}

			}
		} else {
			try {
				this->puzzleNodeManager.deletePuzzleNode(i);
				return false;
			} catch (...) {
				cout << "" << endl;
			}

		}

	}
	return true;
}

void GameWindow::okHandler() {
	this->setNewNodeValues();
	if (this->puzzleNodeManager.isCompleted()) {

		if (this->puzzleNodeManager.isSolved()) {
			try {
				this->gameOutcomeLabel->label("");

				InputAlertWindow winningWindow("Solution Correct");
				winningWindow.set_modal();
				winningWindow.show();
				while (winningWindow.shown()) {
					Fl::wait();
				}

				string name = winningWindow.getPlayerName();
				winningWindow.hide();
				this->show();

				ScoreManager scoreManager = ScoreManager();
				scoreManager.loadScores();
				scoreManager.addScore(name, 1, this->puzzleNumber);
				scoreManager.saveScores();
				this->loadNextPuzzle();
			} catch (std::invalid_argument &e) {
#ifdef DIAGNOSTIC_OUTPUT
					cout << e << endl;
				#endif
			}
		} else {
			this->gameOutcomeLabel->label(ErrorMessages::IncorrectSolution);
		}
	} else {
		this->gameOutcomeLabel->label(ErrorMessages::BoardIncomplete);
	}

}

void GameWindow::loadGameBoard() {
	this->puzzleNodeManager.loadNodes(this->puzzle);
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
	if (this->puzzle.find(Settings::CurrentPuzzleFileName) != string::npos) {
		this->puzzleNumber = this->puzzleNodeManager.getCurrentPuzzleIndex();
		cout << "IN LOADGAMEBOARD RESUME " + to_string(this->puzzleNumber)
				<< endl;
	}

}

void GameWindow::deleteInputBoxes() {
	for (vector<Fl_Input*>::size_type i = 0; i < this->inputBoxes.size(); i++) {
		this->inputBoxes[i] = nullptr;
		delete this->inputBoxes[i];
	}
}

void GameWindow::cb_savePuzzle(Fl_Widget *widget, void *data) {
	GameWindow *window = (GameWindow*) data;
	window->setNewNodeValues();
	window->puzzleNodeManager.setCurrentPuzzleIndex(window->puzzleNumber);
	window->puzzleNodeManager.saveNodes(Settings::CurrentPuzzleFileName);

}

void GameWindow::loadNextPuzzle() {
	try {
		if (this->puzzleNumber < Settings::NumberOfPuzzles - 1) {
			this->puzzleNumber += 1;
			this->puzzle = Settings::PuzzleFileNames[this->puzzleNumber];
			this->label(this->puzzle.c_str());
			this->puzzleNodeManager.resetBoard();
			this->resetInputBoxes();
			this->loadGameBoard();
		} else {
			this->hide();
		}
	} catch (...) {
		cout << ErrorMessages::PuzzleCouldNotBeFound << endl;
	}

}

void GameWindow::resetInputBoxes() {
	for (vector<Fl_Input*>::size_type i = 0; i < this->inputBoxes.size(); i++) {
		this->inputBoxes[i]->value("");
		this->inputBoxes[i]->readonly(false);
		this->inputBoxes[i]->activate();
	}
}

GameWindow::~GameWindow() {
	this->puzzleNodeManager.resetBoard();
	this->deleteInputBoxes();
}

} /* namespace view */
