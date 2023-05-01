#ifndef MODEL_PUZZLENODE_H_
#define MODEL_PUZZLENODE_H_

namespace puzzle {
/**
 * The puzzle node
 */
class PuzzleNode final {
private:
	int value;
	int index;
	bool isStarting;
public:
	/**
	 * The three parameter constructor for the Node
	 *
	 * Precondition: index >= 0 && value >= 0 && value IS NOT EQUAL TO OR ABOVE maximum number of cells
	 * Postcondition: this->getIndex() == index && this->getValue() == value
	 *
	 * Param: index the index
	 * Param: value the value
	 * Param: isStarting if the node is a starting node
	 */
	PuzzleNode(int index, int value, bool isStarting);
	/**
	 * The destructor for the Node
	 *
	 * Precondition: None
	 * Postcondition: None
	 */
	virtual ~PuzzleNode();

	/**
	 * Gets the value
	 *
	 * Precondition: None
	 * Postcondition: None
	 *
	 * Returns: the value
	 */
	int getValue();
	/**
	 * Gets the index
	 *
	 * Precondition: None
	 * Postcondition: None
	 *
	 * Returns: the index
	 */
	int getIndex();
	/**
	 * Gets if the node is a starting node
	 *
	 * Precondition: None
	 * Postcondition: None
	 *
	 * Returns: If the node is a starting node
	 */
	bool getIsStarting();
	/**
	 * Sets the value
	 *
	 * Precondition: value >= 1
	 * Postcondition: this->getValue() == valueToSet
	 *
	 * Param valueToSet the value to set
	 */
	void setValue(int valueToSet);
};

}

#endif /* MODEL_PUZZLENODE_H_ */
