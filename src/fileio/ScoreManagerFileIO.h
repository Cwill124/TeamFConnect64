#ifndef FILEIO_SCOREMANAGERFILEIO_H_
#define FILEIO_SCOREMANAGERFILEIO_H_

#include <ScoreManager.h>

using namespace scores;

namespace fileio {
class ScoreManagerFileIO final {
public:
	/**
	 * The constructor for the score manager file io
	 *
	 * Precondition: None
	 * Postcondition: None
	 */
	ScoreManagerFileIO();
	/**
	 * The destructor for the score manager file io
	 *
	 * Precondition: None
	 * Postcondition: None
	 */
	virtual ~ScoreManagerFileIO();
	/**
	 * Loads the scores
	 *
	 * Precondition: None
	 * Postcondition: The manager has the scores from the file
	 */
	void loadScores(const string& filename, ScoreManager& manager);
	/**
	 * Saves the scores
	 *
	 * Precondition: None
	 * Postcondition: None
	 */
	void saveScores(const string& filename, ScoreManager& manager);
};

}

#endif /* FILEIO_SCOREMANAGERFILEIO_H_ */
