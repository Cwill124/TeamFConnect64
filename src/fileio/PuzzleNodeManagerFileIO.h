#ifndef FILEIO_PUZZLENODEMANAGERFILEIO_H_
#define FILEIO_PUZZLENODEMANAGERFILEIO_H_

#include <PuzzleNodeManager.h>

namespace fileio {
class PuzzleNodeManagerFileIO final {
public:
	/**
	 * The constructor for the puzzle node manager file io
	 *
	 * Precondition: None
	 * Postcondition: None
	 */
	PuzzleNodeManagerFileIO();
	/**
	 * The destructor for the puzzle node manager file io
	 *
	 * Precondition: None
	 * Postcondition: None
	 */
	virtual ~PuzzleNodeManagerFileIO();
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
	void loadPuzzleNodes(const string& filename, PuzzleNodeManager &manager, vector<PuzzleNode*> nodes);
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
	void savePuzzleNodes(const string& filename, PuzzleNodeManager &manager, vector<PuzzleNode*> nodes);
};

}
#endif /* FILEIO_PUZZLENODEMANAGERFILEIO_H_ */
