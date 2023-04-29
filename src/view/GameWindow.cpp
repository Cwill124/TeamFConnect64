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
		OKCancelWindow(330, 375, "") {
	begin();
	this->setOKLocation(10, 325);
	this->setCancelLocation(90, 325);
	this->isPaused = false;
	this->resetButton = new Fl_Button(170, 325, 70, 30, "Reset");
	this->saveButton = new Fl_Button(250, 325, 70, 30, "Save");
	this->pauseButton = new Fl_Button(90, 25, 70, 30, "Pause");
	this->hintButton = new Fl_Button(250, 25, 70, 30, "Hint");
	this->pauseButton->callback(cb_pause, this);
	this->resetButton->callback(cb_resetBoard, this);
	this->saveButton->callback(cb_savePuzzle, this);
	this->hintButton->callback(cb_hint, this);
	this->timer = new Fl_Output(10, 25, 70, 30);
	Fl::add_timeout(1.0, cb_timer, this);
	this->puzzle = puzzle;
	this->puzzleNumber = puzzleNumber;
	this->label(this->puzzle.c_str());
	this->createBoxes();
	this->loadGameBoard();
	this->gameOutcomeLabel = new Fl_Box(0, -5, 325, 30);
	this->errorMessageBox = new Fl_Box(0, -5, 325, 30);
	this->errorMessageBox->labelcolor(FL_RED);
	end();
	this->resizable(this);

}

void GameWindow::cb_timer(void *data) {
	GameWindow *gameWindow = static_cast<GameWindow*>(data);
	if (!gameWindow->isPaused) {
		gameWindow->puzzleNodeManager.incrementTime();
		string text = Utils::convertIntegerToTimeString(
				gameWindow->puzzleNodeManager.getTime());
		gameWindow->timer->value(text.c_str());
		Fl::repeat_timeout(1.0, cb_timer, data);
	} else {
		Fl::repeat_timeout(1.0, cb_timer, data);
	}
}

void GameWindow::cb_hint(Fl_Widget *widget, void *data) {
	string hintWindowTitle = "Hints";
	GameWindow *gameWindow = static_cast<GameWindow*>(data);
	int newPuzzleTime = gameWindow->puzzleNodeManager.getTime()
			+ Settings::HintTimeIncrement;
	gameWindow->puzzleNodeManager.setTime(newPuzzleTime);

	vector<string> remainingValues =
			gameWindow->puzzleNodeManager.getRemainingNodeNames();
	string remainingValuesMessage = "Remaining Values: \n";

	for (string value : remainingValues) {
		remainingValuesMessage += "  " + value + "\n";
	}

	ScrollableAlertWindow winningWindow(remainingValuesMessage.c_str(),
			hintWindowTitle.c_str());
	winningWindow.set_modal();
	winningWindow.show();
	while (winningWindow.shown()) {
		Fl::wait();
	}
}

void GameWindow::cb_pause(Fl_Widget *widget, void *data) {
	GameWindow *gameWindow = static_cast<GameWindow*>(data);
	gameWindow->isPaused = !gameWindow->isPaused;

	if (gameWindow->isPaused) {
		for (Fl_Input *input : gameWindow->inputBoxes) {
			input->hide();
		}
	} else {
		for (Fl_Input *input : gameWindow->inputBoxes) {
			input->show();
		}
	}
}

void GameWindow::createBoxes() {
	int xShift = -5;
	int yShift = 10;
	int tileSize = 30;
	for (int i = 1; i <= Settings::SizeOfBoard; i++) {
		int Y = (i * tileSize);
		for (int j = 1; j <= Settings::SizeOfBoard; j++) {
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
	regex patternNumbers("([1-5]?[1-9]|6[0-4])");
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
	window->puzzleNodeManager.setTime(0);
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
	try {
		this->errorMessageBox->label("");
		this->gameOutcomeLabel->label("");
		for (vector<Fl_Input*>::size_type i = 0; i < this->inputBoxes.size(); i++) {
			const char *value = this->inputBoxes[i]->value();
			PuzzleNode *node = this->puzzleNodeManager.getPuzzleNodes()[i];
			if (strlen(value) != 0 || value == nullptr) {
				if (node == nullptr) {
					this->puzzleNodeManager.addPuzzleNode(i, stoi(value),
								false);
				} else {
					node->setValue(stoi(value));
				}
			} else {
				try {
					this->puzzleNodeManager.deletePuzzleNode(i);
					return false;
				} catch (...) {
					#ifdef DIAGNOSTIC_OUTPUT
					cout << "" << endl;
					#endif
				}
			}
		}
		return true;
	} catch (const std::invalid_argument& e) {
		this->gameOutcomeLabel->label("");
		this->errorMessageBox->label(e.what());
	}

	return false;
}

void GameWindow::okHandler() {
	this->setNewNodeValues();
	if (this->puzzleNodeManager.isCompleted()) {

		if (this->puzzleNodeManager.isSolved()) {
			try {
				this->errorMessageBox->label("");
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
				scoreManager.addScore(name, this->puzzleNodeManager.getTime(),
						this->puzzleNumber);
				scoreManager.saveScores();
				this->loadNextPuzzle();
			} catch (std::invalid_argument &e) {
				#ifdef DIAGNOSTIC_OUTPUT
					cout << e << endl;
				#endif
			}
		} else {
			this->errorMessageBox->label("");
			this->gameOutcomeLabel->label(ErrorMessages::IncorrectSolution);
		}
	} else {
		this->errorMessageBox->label("");
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
#ifdef DIAGNOSTIC_OUTPUT
		cout << ErrorMessages::PuzzleCouldNotBeFound << endl;
#endif
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
	Fl::remove_timeout(cb_timer, this);
	this->puzzleNodeManager.resetBoard();

	this->timer = nullptr;
	delete this->timer;

	this->gameOutcomeLabel = nullptr;
	delete this->gameOutcomeLabel;

	this->errorMessageBox = nullptr;
	delete this->errorMessageBox;

	this->resetButton = nullptr;
	delete this->resetButton;

	this->saveButton = nullptr;
	delete this->saveButton;

	this->pauseButton = nullptr;
	delete this->pauseButton;

	this->deleteInputBoxes();
}

} /* namespace view */
