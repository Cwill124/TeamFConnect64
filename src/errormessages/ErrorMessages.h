/*
 * ErrorMessages.h
 *
 *  Created on: Apr 13, 2023
 *      Author: adecesa1
 */

#ifndef ERRORMESSAGES_ERRORMESSAGES_H_
#define ERRORMESSAGES_ERRORMESSAGES_H_

#include <string>
using namespace std;

namespace errormessages {
class ErrorMessages final {
public:
	/**
	 * The constructor for the error messages
	 */
	ErrorMessages();

	/**
	 * The destructor for the error messages
	 */
	virtual ~ErrorMessages();
	/**
	 * The error message for the id being negative
	 */
	const static string IdCannotBeNegative;
	/**
	 * The error message for the value being negative
	 */
	const static string ValueCannotBeNegative;
	/**
	 * The error message for the value being above the maximum
	 */
	const static string ValueCannotBeAboveMaximum;
	/**
	 * The error message for the index being negative
	 */
	const static string IndexCannotBeNegative;
	/**
	 * The error message for adding a node that is already present
	 */
	const static string CannotAddNodeIfAlreadyPresent;
	/**
	 * The error message for deleting a starting node
	 */
	const static string CannotDeleteStartingNode;
	/**
	 * The error message for replacing a starting node
	 */
	const static string CannotReplaceStartingNode;
	/**
	 * The error message for deleting a null node
	 */
	const static string CannotDeleteNullNode;
	/**
	 * The error message for replacing a null node
	 */
	const static string CannotReplaceNullNode;
	/**
	 * The error message for inserting a invalid value in inputbox
	 */
	const static char *InvalidInputValue;
	/**
	 * The error message for the solution being incorrect
	 */
	const static char *IncorrectSolution;

	/**
	 * The error message for the input being a duplicate
	 */
	const static char *DuplicateInput;
	/**
	 * The error message for the board being incomplete
	 */
	const static char *BoardIncomplete;
	/**
	 * The error message for puzzle trying to be loaded is not found
	 */
	const static char *PuzzleCouldNotBeFound;
	/* The error message for a null player name
	 */
	const static string PlayerNameCannotBeNull;
	/**
	 * The error message for an empty player name
	 */
	const static string PlayerNameCannotBeEmpty;
	/**
	 * The error message for the time being negative
	 */
	const static string TimeCannotBeNegative;
	/**
	 * The error message for the puzzle number being negative
	 */
	const static string PuzzleNumberCannotBeNegative;
	/**
	 * The error message for the manager being null
	 */
	const static string ManagerCannotBeNull;
	/**
	 * The error message for the Puzzle being null
	 */
	const static string PuzzleNameCannotBeNull;
	/**
	 * The error message for a Null RGB array
	 */
	const static string RGBArrayNull;
};
}

#endif /* ERRORMESSAGES_ERRORMESSAGES_H_ */
