#include <PuzzleNodeManager.h>
#include <ErrorMessages.h>
#include <stdexcept>
#include <algorithm>
#include <PuzzleNodeManagerFileIO.h>

using namespace std;
using namespace errormessages;
using namespace fileio;

PuzzleNodeManager::PuzzleNodeManager() {
	this->currentPuzzleIndex = 0;
	for (int i = 0; i < Settings::NumberOfPuzzleNodes; i++) {
		nodes.push_back(nullptr);
	}
}

PuzzleNodeManager::~PuzzleNodeManager() {
	this->resetBoard();
}

vector<PuzzleNode*> PuzzleNodeManager::getPuzzleNodes() {
	return this->nodes;
}

bool PuzzleNodeManager::isValidNextPath(int neighborNodeValueToCheck,
		int currentNodeValueToCheck) {
	return neighborNodeValueToCheck == (currentNodeValueToCheck - 1)
			|| neighborNodeValueToCheck == (currentNodeValueToCheck + 1);
}

void PuzzleNodeManager::addPuzzleNode(int index, int value, bool isStarting) {
	if (this->containsValue(value)) {
		throw invalid_argument(ErrorMessages::CannotAddNodeIfAlreadyPresent);
	}

	nodes[index] = new PuzzleNode(index, value, isStarting);
}

bool PuzzleNodeManager::containsValue(int value) {
	for (PuzzleNode *node : this->nodes) {
		if (node != nullptr && node->getValue() == value) {
			return true;
		}
	}

	return false;
}

PuzzleNode& PuzzleNodeManager::getPuzzleNode(int index) {
	if (index < 0) {
		throw invalid_argument(ErrorMessages::IndexCannotBeNegative);
	}
	return *nodes[index];
}

int PuzzleNodeManager::getCurrentPuzzleIndex() {
	return this->currentPuzzleIndex;
}

void PuzzleNodeManager::setCurrentPuzzleIndex(int index) {
	if (index < 0) {
		throw invalid_argument(ErrorMessages::IndexCannotBeNegative);
	}
	this->currentPuzzleIndex = index;
}

void PuzzleNodeManager::replacePuzzleNode(int index, int value) {
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

void PuzzleNodeManager::deletePuzzleNode(int index) {
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

void PuzzleNodeManager::resetBoard() {
	for (int i = 0; i < Settings::NumberOfPuzzleNodes; i++) {
		nodes[i] = nullptr;
		delete nodes[i];
	}
}

bool PuzzleNodeManager::isSolved() {
	vector<PuzzleNode*> visitedNodes;
	for (PuzzleNode *node : this->nodes) {
		if (node != nullptr && node->getValue() == 1) {
			return this->isSolved(*node, visitedNodes);
		}
	}

	return false;
}

bool PuzzleNodeManager::isSolved(PuzzleNode &node,
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

bool PuzzleNodeManager::isCompleted() {
	for (PuzzleNode *node : this->nodes) {
		if (node == nullptr) {
			return false;
		}
	}

	return true;
}

PuzzleNode* PuzzleNodeManager::getBottomPuzzleNode(int index) {
	int lastRowIndex = Settings::NumberOfPuzzleNodes
			- Settings::MaximumRowAmount;
	if (index >= lastRowIndex) {
		return nullptr;
	}
	PuzzleNode *node = nodes[index + Settings::MaximumRowAmount];
	return node;
}

PuzzleNode* PuzzleNodeManager::getTopPuzzleNode(int index) {
	int topRowIndex = Settings::MaximumRowAmount;
	if (index < topRowIndex) {
		return nullptr;
	}

	return nodes[index - Settings::MaximumRowAmount];
}

PuzzleNode* PuzzleNodeManager::getLeftPuzzleNode(int index) {
	if (((index + 1) % Settings::MaximumRowAmount) - 1 == 0) {
		return nullptr;
	}
	return nodes[index - 1];
}

PuzzleNode* PuzzleNodeManager::getRightPuzzleNode(int index) {
	if (((index + 1) % Settings::MaximumRowAmount) == 0) {
		return nullptr;
	}
	return nodes[index + 1];
}

void PuzzleNodeManager::saveNodes(const string &fileToSaveTo) {
	PuzzleNodeManagerFileIO fileIo = PuzzleNodeManagerFileIO();
	fileIo.savePuzzleNodes(fileToSaveTo, *this, nodes);
}

void PuzzleNodeManager::loadNodes(const string &fileToLoadFrom) {
	for (int i = 0; i < Settings::NumberOfPuzzleNodes; i++) {
		nodes[i] = nullptr;
		delete nodes[i];
	}
	PuzzleNodeManagerFileIO fileIo = PuzzleNodeManagerFileIO();
	fileIo.loadPuzzleNodes(fileToLoadFrom, *this, nodes);
}

void PuzzleNodeManager::loadNewPuzzle() {
	for (int i = 0; i < Settings::NumberOfPuzzleNodes; i++) {
		nodes[i] = nullptr;
	}
	PuzzleNodeManagerFileIO fileIo = PuzzleNodeManagerFileIO();
	string currentFile = Settings::PuzzleFileNames[this->currentPuzzleIndex];
	fileIo.loadPuzzleNodes(currentFile, *this, nodes);
	this->currentPuzzleIndex++;
}

//TODO This is temporary and for testing
string PuzzleNodeManager::toString() {
	string managerString = "A puzzle with completed being: "
			+ std::to_string(this->isCompleted()) + " And solved being: "
			+ std::to_string(this->isSolved()) + "\n";

	for (PuzzleNode *node : nodes) {
		if (node != nullptr) {
			managerString += "A node with value: "
					+ std::to_string(node->getValue()) + " Is Starting: "
					+ std::to_string(node->getIsStarting()) + " Index: "
					+ std::to_string(node->getIndex());
			if (this->getTopPuzzleNode(node->getIndex()) != nullptr) {
				managerString +=
						" Top Node: "
								+ std::to_string(
										this->getTopPuzzleNode(node->getIndex())->getValue());
			} else {
				managerString += " Top Node: NULL";
			}
			if (this->getRightPuzzleNode(node->getIndex()) != nullptr) {
				managerString +=
						" Right Node: "
								+ std::to_string(
										this->getRightPuzzleNode(
												node->getIndex())->getValue());
			} else {
				managerString += " Right Node: NULL";
			}
			if (this->getBottomPuzzleNode(node->getIndex()) != nullptr) {
				managerString +=
						" Bottom Node: "
								+ std::to_string(
										this->getBottomPuzzleNode(
												node->getIndex())->getValue());
			} else {
				managerString += " Bottom Node: NULL";
			}
			if (this->getLeftPuzzleNode(node->getIndex()) != nullptr) {
				managerString +=
						" Left Node: "
								+ std::to_string(
										this->getLeftPuzzleNode(
												node->getIndex())->getValue());
			} else {
				managerString += " Left Node: NULL";
			}
		} else {
			managerString += "A null node ";
		}

		managerString += "\n";
	}

	return managerString;
}

