#include <scores/Score.h>
#include <stdexcept>
#include <ErrorMessages.h>

using namespace std;
using namespace errormessages;

namespace scores {
Score::Score(int id, const string& playerName, int time, int puzzleNumber) {
	if (id < 0) {
		throw invalid_argument(ErrorMessages::IdCannotBeNegative);
	}
	if (playerName == "") {
		throw invalid_argument(ErrorMessages::PlayerNameCannotBeEmpty);
	}
	if (time < 0) {
		throw invalid_argument(ErrorMessages::TimeCannotBeNegative);
	}
	if (puzzleNumber < 0) {
		throw invalid_argument(ErrorMessages::PuzzleNumberCannotBeNegative);
	}

	this->id = id;
	this->playerName = playerName;
	this->time = time;
	this->puzzleNumber = puzzleNumber;
}

int Score::getId() {
	return this->id;
}

string& Score::getPlayerName() {
	return this->playerName;
}

int Score::getTime() {
	return this->time;
}

int Score::getPuzzleNumber() {
	return this->puzzleNumber;
}

Score::~Score() {

}
}

