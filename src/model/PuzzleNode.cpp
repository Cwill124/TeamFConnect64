#include <stdexcept>
#include <ErrorMessages.h>
#include <PuzzleNode.h>
#include <Settings.h>

using namespace std;
using namespace errormessages;
using namespace settings;

namespace model {


PuzzleNode::PuzzleNode(int index, int value, bool isStarting) {
	if (index < 0) {
		throw invalid_argument(ErrorMessages::IndexCannotBeNegative);
	}
	if (value < 1) {
		throw invalid_argument(ErrorMessages::ValueCannotBeNegativeOrZero);
	}
	if (value > Settings::NumberOfPuzzleNodes) {
		throw invalid_argument(ErrorMessages::ValueCannotBeAboveMaximum);
	}
	this->index = index;
 	this->value = value;
	this->isStarting = isStarting;
}

int PuzzleNode::getValue() {
	return this->value;
}

int PuzzleNode::getIndex() {
	return this->index;
}

bool PuzzleNode::getIsStarting() {
	return this->isStarting;
}

void PuzzleNode::setValue(int value) {
	if (value < 1) {
		throw invalid_argument(ErrorMessages::ValueCannotBeNegativeOrZero);
	}
	this->value = value;
}

PuzzleNode::~PuzzleNode() {

}
}

