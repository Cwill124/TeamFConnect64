#include <ScoreManagerFileIO.h>
#include <ScoreManager.h>
#include <ErrorMessages.h>
#include <sstream>
#include <fstream>
#include <iostream>
#include <string>

using namespace errormessages;
using namespace fileio;

ScoreManagerFileIO::ScoreManagerFileIO() {

}

void ScoreManagerFileIO::loadScores(const string &filename,
		ScoreManager &manager) {
	std::ifstream puzzleFile(filename);
	string line;

	while (std::getline(puzzleFile, line)) {
		std::stringstream stream(line);
		string playername;
		string time;
		string puzzleNumber;

		if (std::getline(stream, playername, ',')
				&& std::getline(stream, time, ',')
				&& std::getline(stream, puzzleNumber)) {
			manager.addScore(playername, std::stoi(time),
					std::stoi(puzzleNumber));
		}
	}
}

void ScoreManagerFileIO::saveScores(const string &filename,
		ScoreManager &manager) {
	std::ofstream outputFile(filename);

	for (Score *score : manager.getScores()) {
		string &playername = score->getPlayerName();
		int time = score->getTime();
		int puzzleNumber = score->getPuzzleNumber();

		outputFile << playername << "," << time << "," << puzzleNumber << endl;
	}

	outputFile.close();
}

ScoreManagerFileIO::~ScoreManagerFileIO() {

}

