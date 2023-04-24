/*
 * ErrorMessages.cpp
 *
 *  Created on: Apr 13, 2023
 *      Author: adecesa1
 */

#include "ErrorMessages.h"

namespace errormessages {
/**
 * The destructor for the error messages
 */
ErrorMessages::ErrorMessages() {

}

/**
 * The constructor for the error messages
 */
ErrorMessages::~ErrorMessages() {

}

const string ErrorMessages::IdCannotBeNegative = "The id cannot be negative";
const string ErrorMessages::ValueCannotBeNegative =
		"The value cannot be negative";
const string ErrorMessages::ValueCannotBeAboveMaximum =
		"The value cannot be more than the maximum amount of nodes";
const string ErrorMessages::IndexCannotBeNegative =
		"The index cannot be negative";
const string ErrorMessages::CannotAddNodeIfAlreadyPresent =
		"Cannot add a node that is already present";
const string ErrorMessages::CannotDeleteStartingNode =
		"Cannot delete a starting node";
const string ErrorMessages::CannotReplaceStartingNode =
		"Cannot replace a starting node";
const string ErrorMessages::CannotDeleteNullNode = "The node to delete is null";
const string ErrorMessages::CannotReplaceNullNode =
		"The node to replace is null";
const char *ErrorMessages::InvalidInputValue = "The value must be 1-64";
const char *ErrorMessages::IncorrectSolution = "The solution is incorrect";

const char *ErrorMessages::DuplicateInput = "Cannot contain duplicates";
const char *ErrorMessages::BoardIncomplete = "Board not complete";
const char *ErrorMessages::PuzzleCouldNotBeFound = "Puzzle could not be found";
const string ErrorMessages::PlayerNameCannotBeNull =
		"The player name cannot be null";
const string ErrorMessages::PlayerNameCannotBeEmpty =
		"The player name cannot be empty";
const string ErrorMessages::TimeCannotBeNegative = "The time cannot be negative";
const string ErrorMessages::PuzzleNumberCannotBeNegative =
		"The puzzle number cannot be negative";
const string ErrorMessages::ManagerCannotBeNull = "The manager cannot be null";

}
