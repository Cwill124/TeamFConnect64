#ifndef MODEL_SCORES_SCORE_H_
#define MODEL_SCORES_SCORE_H_

#include <Score.h>
#include <stdexcept>
#include <ErrorMessages.h>

using namespace std;

namespace scores {
/**
 * The score
 */
class Score final {
private:
	int id;
	string playerName;
	int time;
	int puzzleNumber;
public:
	/**
	 * The constructor for the Score
	 *
	 * Precondition: playerName IS NOT empty && time > 0 && puzzleNumber > 0
	 * Postcondition: getPlayerName() == playerName && getTime == time && getPuzzleNumber == puzzleNumber
	 *
	 * Param: id the id
	 * Param: playerName the player name
	 * Param: time the time
	 * Param: puzzleNumber the puzzle number
	 */
	Score(int id, const string &playerName, int time, int puzzleNumber);
	/**
	 * The destructor for the score
	 *
	 * Precondition: None
	 * Postcondition: None
	 */
	virtual ~Score();
	/**
	 * Gets the id
	 *
	 * Precondition: None
	 * Postcondition: None
	 *
	 * Returns: The id
	 */
	int getId();
	/**
	 * Gets the player name
	 *
	 * Precondition: None
	 * Postcondition: None
	 *
	 * Returns: The player name
	 */
	string& getPlayerName();
	/**
	 * Gets the time
	 *
	 * Precondition: None
	 * Postcondition: None
	 *
	 * Returns: The time
	 */
	int getTime();
	/**
	 * Gets the puzzle number
	 *
	 * Precondition: None
	 * Postcondition: None
	 *
	 * Returns: The puzzle number
	 */
	int getPuzzleNumber();
};
}

#endif /* MODEL_SCORES_SCORE_H_ */
