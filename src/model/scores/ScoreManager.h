/*
 * The score manager
 */

#ifndef MODEL_SCORES_SCOREMANAGER_H_
#define MODEL_SCORES_SCOREMANAGER_H_

#include <string>
#include <vector>
#include <scores/Score.h>

using namespace std;

namespace scores {
class ScoreManager final {
private:
	vector<Score*> scores;
public:
	/**
	 * The constructor for the score manager
	 *
	 * Precondition: None
	 * Postcondition: None
	 */
	ScoreManager();
	/**
	 * The destructor for the score manager
	 *
	 * Precondition: None
	 * Postcondition: None
	 */
	virtual ~ScoreManager();
	/**
	 * Adds a score to the score manager
	 *
	 * Precondition: None
	 * Postcondition: The score is added
	 *
	 * Param: playerName the player name
	 * Param: time the time
	 * Param: puzzle the puzzle
	 */
	void addScore(string& playerName, int time, int puzzle);
	/**
	 * Removes a score from the score manager
	 *
	 * Precondition: None
	 * Postcondition: The score is removed
	 *
	 * Param: idToRemove the id to remove
	 */
	void removeScore(int idToRemove);
	/**
	 * Resets the scores from the manager
	 *
	 * Precondition: None
	 * Postcondition: The scores are reset
	 */
	void resetScores();
	/**
	 * Gets the scores
	 *
	 * Precondition: None
	 * Postcondition: None
	 *
	 * Returns: The scores
	 */
	vector<Score*> getScores();
	/**
	 * Gets the scores sorted by time
	 *
	 * Precondition: None
	 * Postcondition: None
	 *
	 * Returns: The scores sorted by time
	 */
	vector<Score*> getScoresSortedByTime();
	/**
	 * Gets the scores sorted by puzzle number
	 *
	 * Precondition: None
	 * Postcondition: None
	 *
	 * Returns: The scores sorted by puzzle number
	 */
	vector<Score*> getScoresSortedByPuzzleNumber();
	/**
	 * Loads the scores from the high scores file
	 *
	 * Precondition: None
	 * Postcondition: The scores are loaded from the file
	 */
	void loadScores();
	/**
	 * Saves the scores to the high scores file
	 *
	 * Precondition: None
	 * Postcondition: None
	 */
	void saveScores();
};
/**
 * Compares scores by time ascending
 *
 * Precondition: None
 * Postcondition: None
 *
 * Param firstScore the first score
 * Param secondScore the second score
 */
bool compareByTimeAscending(Score* firstScore, Score* secondScore);

/**
 * Compares scores by time descending
 *
 * Precondition: None
 * Postcondition: None
 *
 * Param firstScore the first score
 * Param secondScore the second score
 */
bool compareByTimeDescending(Score* firstScore, Score* secondScore);
/**
 * Compares scores by puzzle number
 *
 * Precondition: None
 * Postcondition: None
 *
 * Param firstScore the first score
 * Param secondScore the second score
 */
bool compareByPuzzleNumber(Score* firstScore, Score* secondScore);
}
#endif /* MODEL_SCORES_SCOREMANAGER_H_ */
