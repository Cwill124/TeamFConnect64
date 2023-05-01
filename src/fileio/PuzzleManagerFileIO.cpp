#include <PuzzleManagerFileIO.h>
#include <sstream>
#include <fstream>
#include <iostream>
#include <string>

using namespace std;
using namespace fileio;

PuzzleManagerFileIO::PuzzleManagerFileIO() {

}

PuzzleManagerFileIO::~PuzzleManagerFileIO() {

}

void PuzzleManagerFileIO::loadPuzzleNodes(const string &filename,
		PuzzleManager &manager, vector<PuzzleNode*> nodes) {
	std::ifstream puzzleFile(filename);
	string line;

	int lineIndex = 0;
	while (std::getline(puzzleFile, line)) {
		std::stringstream stream(line);
		string index;
		string value;
		string isStarting;
		string puzzleIndex;
		string time;

		if (lineIndex == 0 && std::getline(stream, puzzleIndex, ',')
				&& std::getline(stream, time)) {
			manager.setCurrentPuzzleIndex(std::stoi(puzzleIndex));
			manager.setTime(std::stoi(time));
		} else if (std::getline(stream, index, ',')
				&& std::getline(stream, value, ',')
				&& std::getline(stream, isStarting)) {
			manager.addPuzzleNode(std::stoi(index), std::stoi(value),
					std::stoi(isStarting));
		}

		lineIndex++;
	}
}

void PuzzleManagerFileIO::savePuzzleNodes(const string &filename,
		PuzzleManager &manager, vector<PuzzleNode*> nodes) {
	std::ofstream outputFile(filename);
	outputFile << manager.getCurrentPuzzleIndex() << "," << manager.getTime()
			<< endl;

	for (int i = 0; i < Settings::NumberOfPuzzleNodes; i++) {
		if (nodes[i] != nullptr) {
			int index = nodes[i]->getIndex();
			int value = nodes[i]->getValue();
			int isStarting = nodes[i]->getIsStarting();
			outputFile << index << "," << value << "," << isStarting << endl;
		}
	}

	outputFile.close();
}
