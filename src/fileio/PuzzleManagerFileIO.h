#ifndef FILEIO_PUZZLEMANAGERFILEIO_H_
#define FILEIO_PUZZLEMANAGERFILEIO_H_

#include <PuzzleManager.h>

using namespace puzzle;

namespace fileio {
/**
 * The file io for the puzzle manager
 */
class PuzzleManagerFileIO final {
public:
	/**
	 * The constructor for the puzzle node manager file io
	 *
	 * Precondition: None
	 * Postcondition: None
	 */
	PuzzleManagerFileIO();
	/**
	 * The destructor for the puzzle node manager file io
	 *
	 * Precondition: None
	 * Postcondition: None
	 */
	virtual ~PuzzleManagerFileIO();
	/**
	 * Loads the puzzle nodes
	 *
	 * Precondition: None
	 * Postcondition: manager is populated with the puzzle information
	 *
	 * Param: filename the file name
	 * Param: manager the manager
	 * Param: nodes the nodes
	 */
	void loadPuzzleNodes(const string &filename, PuzzleManager &manager,
			vector<PuzzleNode*> nodes);
	/**
	 * Saves the puzzle nodes
	 *
	 * Precondition: None
	 * Postcondition: None
	 *
	 * Param: filename the file name
	 * Param: manager the manager
	 * Param: nodes the nodes
	 */
	void savePuzzleNodes(const string &filename, PuzzleManager &manager,
			vector<PuzzleNode*> nodes);
};

}
#endif /* FILEIO_PUZZLEMANAGERFILEIO_H_ */
