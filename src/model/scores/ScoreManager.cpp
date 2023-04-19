/*
 * ScoreManager.cpp
 *
 *  Created on: Apr 17, 2023
 *      Author: adecesa1
 */

#include <string>
#include <algorithm>
#include <vector>
#include <scores/ScoreManager.h>
#include <ScoreManagerFileIO.h>
#include <Settings.h>

using namespace std;
using namespace fileio;
using namespace settings;

namespace scores {
ScoreManager::ScoreManager() {

}

void ScoreManager::addScore(string& playerName, int time, int puzzle) {
	vector<Score*> sortedScores = this->scores;
	std::sort(sortedScores.begin(), sortedScores.end(), compareByTimeDescending);

	if (sortedScores.size() < Settings::MaximumHighScores) {
		this->scores.push_back(new Score(this->scores.size(), playerName, time, puzzle));
	} else {
		for (Score* score : sortedScores) {
			if (score->getTime() > time) {
				this->removeScore(score->getId());
				this->scores.push_back(new Score(this->scores.size(), playerName, time, puzzle));
				return;
			}
		}
	}
}

void ScoreManager::removeScore(int idToRemove) {
    for (auto iterator = this->scores.begin(); iterator != this->scores.end(); iterator++) {
        if ((*iterator)->getId() == idToRemove) {
        	*iterator = nullptr;
            delete *iterator;
            this->scores.erase(iterator);
            return;
        }
    }
}

void ScoreManager::resetScores() {
    for (auto score : this->scores) {
    	score = nullptr;
        delete score;
    }

	this->scores.clear();
}

vector<Score*> ScoreManager::getScores() {
	return this->scores;
}

vector<Score*> ScoreManager::getScoresSortedByTime() {
	vector<Score*> sortableScores = this->scores;
	std::sort(sortableScores.begin(), sortableScores.end(), compareByTimeAscending);
	return sortableScores;
}

vector<Score*> ScoreManager::getScoresSortedByPuzzleNumber() {
	vector<Score*> sortableScores = this->scores;
	std::sort(sortableScores.begin(), sortableScores.end(), compareByPuzzleNumber);
	return sortableScores;
}

void ScoreManager::loadScores() {
	this->resetScores();
	ScoreManagerFileIO fileIO;
	fileIO.loadScores(Settings::HighScoresFileName, *this);
}

void ScoreManager::saveScores() {
	ScoreManagerFileIO fileIO;
	fileIO.saveScores(Settings::HighScoresFileName, *this);
}

bool compareByTimeAscending(Score* firstScore, Score* secondScore) {
	return firstScore->getTime() < secondScore->getTime();
}

bool compareByTimeDescending(Score* firstScore, Score* secondScore) {
	return firstScore->getTime() > secondScore->getTime();
}

bool compareByPuzzleNumber(Score* firstScore, Score* secondScore) {
	if (firstScore->getPuzzleNumber() == secondScore->getPuzzleNumber()) {
		return compareByTimeAscending(firstScore, secondScore);
	}

	return firstScore->getPuzzleNumber() > secondScore->getPuzzleNumber();
}

ScoreManager::~ScoreManager() {
	this->resetScores();
}

}
