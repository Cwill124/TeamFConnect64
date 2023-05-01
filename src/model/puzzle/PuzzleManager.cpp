#include <ErrorMessages.h>
#include <PuzzleManager.h>
#include <PuzzleManagerFileIO.h>
#include <stdexcept>
#include <algorithm>

using namespace std;
using namespace errormessages;
using namespace fileio;

namespace puzzle {
PuzzleManager::PuzzleManager() {
	this->time = 0;
	this->currentPuzzleIndex = 0;
	for (int i = 0; i < Settings::NumberOfPuzzleNodes; i++) {
		nodes.push_back(nullptr);
	}
}

PuzzleManager::~PuzzleManager() {
	this->resetBoard();
}

vector<PuzzleNode*> PuzzleManager::getPuzzleNodes() {
	return this->nodes;
}

void PuzzleManager::incrementTime() {
	this->time++;
}

void PuzzleManager::setTime(int time) {
	if (time < 0) {
		throw new invalid_argument(ErrorMessages::TimeCannotBeNegative);
	}

	this->time = time;
}

int PuzzleManager::getTime() {
	return this->time;
}

bool PuzzleManager::isValidNextPath(int neighborNodeValueToCheck,
		int currentNodeValueToCheck) {
	return neighborNodeValueToCheck == (currentNodeValueToCheck - 1)
			|| neighborNodeValueToCheck == (currentNodeValueToCheck + 1);
}

void PuzzleManager::addPuzzleNode(int index, int value, bool isStarting) {
	if (this->containsValue(value)) {
		throw invalid_argument(ErrorMessages::CannotAddNodeIfAlreadyPresent);
	}

	nodes[index] = new PuzzleNode(index, value, isStarting);
}

bool PuzzleManager::containsValue(int value) {
	for (PuzzleNode *node : this->nodes) {
		if (node != nullptr && node->getValue() == value) {
			return true;
		}
	}

	return false;
}

PuzzleNode& PuzzleManager::getPuzzleNode(int index) {
	if (index < 0) {
		throw invalid_argument(ErrorMessages::IndexCannotBeNegative);
	}
	return *nodes[index];
}

int PuzzleManager::getCurrentPuzzleIndex() {
	return this->currentPuzzleIndex;
}

void PuzzleManager::setCurrentPuzzleIndex(int index) {
	if (index < 0) {
		throw invalid_argument(ErrorMessages::IndexCannotBeNegative);
	}
	this->currentPuzzleIndex = index;
}

vector<string> PuzzleManager::getRemainingNodeNames() {
	vector<string> remainingNodes;
	for (int i = 1; i <= Settings::NumberOfPuzzleNodes; i++) {
		if (!this->containsValue(i)) {
			remainingNodes.push_back(std::to_string(i));
		}
	}

	return remainingNodes;
}

void PuzzleManager::replacePuzzleNode(int index, int value) {
	if (nodes[index] == nullptr) {
		throw invalid_argument(ErrorMessages::CannotReplaceNullNode);
	}
	if (nodes[index]->getIsStarting() == true) {
		throw invalid_argument(ErrorMessages::CannotReplaceStartingNode);
	}
	if (index < 0) {
		throw invalid_argument(ErrorMessages::IndexCannotBeNegative);
	}

	nodes[index] = nullptr;
	delete nodes[index];
	nodes[index] = new PuzzleNode(index, value, false);
}

void PuzzleManager::deletePuzzleNode(int index) {
	if (nodes[index] == nullptr) {
		throw invalid_argument(ErrorMessages::CannotDeleteNullNode);
	}
	if (nodes[index]->getIsStarting() == true) {
		throw invalid_argument(ErrorMessages::CannotDeleteStartingNode);
	}
	if (index < 0) {
		throw invalid_argument(ErrorMessages::IndexCannotBeNegative);
	}

	nodes[index] = nullptr;
	delete nodes[index];
}

void PuzzleManager::resetBoard() {
	this->time = 0;
	for (int i = 0; i < Settings::NumberOfPuzzleNodes; i++) {
		nodes[i] = nullptr;
		delete nodes[i];
	}
}

bool PuzzleManager::isSolved() {
	vector<PuzzleNode*> visitedNodes;
	for (PuzzleNode *node : this->nodes) {
		if (node != nullptr && node->getValue() == 1) {
			return this->isSolved(*node, visitedNodes);
		}
	}

	return false;
}

bool PuzzleManager::isSolved(PuzzleNode &node,
		vector<PuzzleNode*> &visitedNodes) {
	if (node.getValue() == Settings::NumberOfPuzzleNodes) {
		return true;
	}
	PuzzleNode *bottomNode = this->getBottomPuzzleNode(node.getIndex());
	PuzzleNode *topNode = this->getTopPuzzleNode(node.getIndex());
	PuzzleNode *leftNode = this->getLeftPuzzleNode(node.getIndex());
	PuzzleNode *rightNode = this->getRightPuzzleNode(node.getIndex());
	visitedNodes.push_back(&node);

	if (bottomNode != nullptr
			&& this->isValidNextPath(bottomNode->getValue(), node.getValue())
			&& std::find(visitedNodes.begin(), visitedNodes.end(), bottomNode)
					== visitedNodes.end()) {
		return this->isSolved(*bottomNode, visitedNodes);
	} else if (topNode != nullptr
			&& this->isValidNextPath(topNode->getValue(), node.getValue())
			&& std::find(visitedNodes.begin(), visitedNodes.end(), topNode)
					== visitedNodes.end()) {
		return this->isSolved(*topNode, visitedNodes);
	} else if (leftNode != nullptr
			&& this->isValidNextPath(leftNode->getValue(), node.getValue())
			&& std::find(visitedNodes.begin(), visitedNodes.end(), leftNode)
					== visitedNodes.end()) {
		return this->isSolved(*leftNode, visitedNodes);
	} else if (rightNode != nullptr
			&& this->isValidNextPath(rightNode->getValue(), node.getValue())
			&& std::find(visitedNodes.begin(), visitedNodes.end(), rightNode)
					== visitedNodes.end()) {
		return this->isSolved(*rightNode, visitedNodes);
	}

	return false;
}

bool PuzzleManager::isCompleted() {
	for (PuzzleNode *node : this->nodes) {
		if (node == nullptr) {
			return false;
		}
	}

	return true;
}

PuzzleNode* PuzzleManager::getBottomPuzzleNode(int index) {
	int lastRowIndex = Settings::NumberOfPuzzleNodes
			- Settings::MaximumRowAmount;
	if (index >= lastRowIndex) {
		return nullptr;
	}
	PuzzleNode *node = nodes[index + Settings::MaximumRowAmount];
	return node;
}

PuzzleNode* PuzzleManager::getTopPuzzleNode(int index) {
	int topRowIndex = Settings::MaximumRowAmount;
	if (index < topRowIndex) {
		return nullptr;
	}

	return nodes[index - Settings::MaximumRowAmount];
}

PuzzleNode* PuzzleManager::getLeftPuzzleNode(int index) {
	if (((index + 1) % Settings::MaximumRowAmount) - 1 == 0) {
		return nullptr;
	}
	return nodes[index - 1];
}

PuzzleNode* PuzzleManager::getRightPuzzleNode(int index) {
	if (((index + 1) % Settings::MaximumRowAmount) == 0) {
		return nullptr;
	}
	return nodes[index + 1];
}

void PuzzleManager::saveNodes(const string &fileToSaveTo) {
	PuzzleManagerFileIO fileIo = PuzzleManagerFileIO();
	fileIo.savePuzzleNodes(fileToSaveTo, *this, nodes);
}

void PuzzleManager::loadNodes(const string &fileToLoadFrom) {
	for (int i = 0; i < Settings::NumberOfPuzzleNodes; i++) {
		nodes[i] = nullptr;
		delete nodes[i];
	}
	PuzzleManagerFileIO fileIo = PuzzleManagerFileIO();
	fileIo.loadPuzzleNodes(fileToLoadFrom, *this, nodes);
}

void PuzzleManager::loadNewPuzzle() {
	for (int i = 0; i < Settings::NumberOfPuzzleNodes; i++) {
		nodes[i] = nullptr;
	}
	PuzzleManagerFileIO fileIo = PuzzleManagerFileIO();
	string currentFile = Settings::PuzzleFileNames[this->currentPuzzleIndex];
	fileIo.loadPuzzleNodes(currentFile, *this, nodes);
	this->currentPuzzleIndex++;
}

bool PuzzleManager::containsValue(int value, PuzzleNode *puzzleNode) {
	for (PuzzleNode *node : this->nodes) {
		if ((node != nullptr && node->getValue() == value)
				&& puzzleNode != node) {
			return true;
		}
	}

	return false;
}
}

