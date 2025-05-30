#ifndef MODEL_PUZZLENODEMANAGER_H_
#define MODEL_PUZZLENODEMANAGER_H_

#include <PuzzleNode.h>
#include <string>
#include <vector>
#include <Settings.h>

using namespace std;
using namespace settings;

namespace puzzle {
/**
 * The puzzle manager
 */
class PuzzleManager final {
private:
	int currentPuzzleIndex;
	int time;
	vector<PuzzleNode*> nodes;

	PuzzleNode* getLeftPuzzleNode(int index);
	PuzzleNode* getRightPuzzleNode(int index);
	PuzzleNode* getTopPuzzleNode(int index);
	PuzzleNode* getBottomPuzzleNode(int index);

	bool isSolved(PuzzleNode &node, vector<PuzzleNode*> &visitedNodes);
	bool isValidNextPath(int neighborNodeValueToCheck,
			int currentNodeValueToCheck);
	bool containsValue(int value);
public:
	/**
	 * The constructor for the puzzle node manager
	 *
	 * Precondition: None
	 * Postcondition: None
	 */
	PuzzleManager();
	/**
	 * The destructor for the puzzle node manager
	 *
	 * Precondition: None
	 * Postcondition: None
	 */
	virtual ~PuzzleManager();

	/**
	 * Gets the puzzle nodes
	 *
	 * Precondition: None
	 * Postcondition: None
	 *
	 * Returns: The puzzle nodes
	 */
	vector<PuzzleNode*> getPuzzleNodes();
	/**
	 * Increments the puzzle time
	 *
	 * Precondition: None
	 * Postcondition: getPuzzleTIme() == getPuzzleTIme()@prev + 1
	 */
	void incrementTime();
	/**
	 * Sets the puzzle time
	 *
	 * Precondition: time >= 0
	 * Postcondition: getPuzzleTIme() == time
	 */
	void setTime(int time);
	/**
	 * Gets the puzzle time
	 *
	 * Precondition: None
	 * Postcondition: None
	 *
	 * Returns: The puzzle time
	 */
	int getTime();
	/**
	 * Adds a puzzle node
	 *
	 * Precondition: value cannot be contained already
	 * Postcondition: None
	 *
	 * Param: value the value to add
	 * Param: index the index to add
	 * Param: isStarting whether or not the node is starting
	 */
	void addPuzzleNode(int value, int index, bool isStarting);
	/**
	 * Gets a puzzle node
	 *
	 * Precondition: index >= 0
	 * Postcondition: None
	 *
	 * Param: index the index
	 *
	 * Return: The puzzle node at the given index
	 */
	PuzzleNode& getPuzzleNode(int index);
	/**
	 * Gets the current puzzle index
	 *
	 * Precondition: None
	 * Postcondition: None
	 *
	 * Return: The current puzzle index
	 */
	int getCurrentPuzzleIndex();
	/**
	 * Sets the current puzzle index
	 *
	 * Precondition: index >= 0
	 * Postcondition: getCurrentPuzzleIndex() == index
	 *
	 * Param: index the index to set
	 */
	void setCurrentPuzzleIndex(int index);
	/**
	 * Gets the remaining node names
	 *
	 * Precondition: None
	 * Postcondition: None
	 *
	 * Return: The remaining node names
	 */
	vector<string> getRemainingNodeNames();
	/**
	 * Deletes a puzzle node
	 *
	 * Precondition: Precondition: node at index is not null && node at index is not starting && index >= 0
	 * Postcondition: The puzzle node at index is null
	 *
	 * Param: index the index
	 */
	void deletePuzzleNode(int index);
	/**
	 * Replaces a puzzle node
	 *
	 * Precondition: Precondition: node at index is not null && node at index is not starting && index >= 0
	 * Postcondition: The puzzle node at index is a node with the new value
	 *
	 * Param: index the index
	 * Param: value the value
	 */
	void replacePuzzleNode(int index, int value);
	/**
	 * Resets the board
	 *
	 * Precondition: None
	 * Postcondition: All nodes are null
	 */
	void resetBoard();
	/**
	 * Checks if the board is solved
	 *
	 * Precondition: None
	 * Postcondition: None
	 *
	 * Return: true if the board is solved, false otherwise
	 */
	bool isSolved();
	/**
	 * Checks if the board is completed
	 *
	 * Precondition: None
	 * Postcondition: None
	 *
	 * Return: true if the board is completed, false otherwise
	 */
	bool isCompleted();
	/**
	 * Saves the nodes of the board
	 *
	 * Precondition: fileToSaveTo != null AND fileToSaveTo IS NOT empty
	 * Postcondition: None
	 *
	 * Param fileToSaveTo the file to save to
	 */
	void saveNodes(const string &fileToSaveTo);
	/**
	 * Loads the nodes of the board
	 *
	 * Precondition: fileToLoadFrom != null AND fileToLoadFrom IS NOT empty
	 * Postcondition: The nodes match the node data from the file
	 *
	 * Param: fileToLoadFrom the file to load from
	 */
	void loadNodes(const string &fileToLoadFrom);
	/**
	 * Loads the next puzzle
	 *
	 * Precondition: None
	 * Postcondition: The puzzle is equal to the puzzle data from a file
	 */
	void loadNewPuzzle();
	/**
	 *	Checks to see if the value exists the nodes besides the inputed node
	 *	used for checking for dupes
	 *
	 *	Param: value the value that is being searched for
	 *	Param: node the node that contains the value already and is ignored
	 *
	 *	Precondition: none
	 *	Postcondition: none
	 *
	 *	Returns: true if a different node is found with value, false otherwise
	 */
	bool containsValue(int value, PuzzleNode *node);
};
}

#endif /* MODEL_PUZZLENODEMANAGER_H_ */
