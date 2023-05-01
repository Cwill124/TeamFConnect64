#ifndef MODEL_ENUMS_SORTSELECTION_H_
#define MODEL_ENUMS_SORTSELECTION_H_

namespace enums {
/**
 * Holds the sort selection
 */
class SortSelection final {
public:
	/**
	 * The sort selection values
	 */
	enum Selection {
		TIME, NUMBER
	};

	/**
	 * The constructor for the sort selection
	 *
	 * Precondition: None
	 * Postcondition: None
	 */
	SortSelection();
	/**
	 * The destructor for the sort selection
	 *
	 * Precondition: None
	 * Postcondition: None
	 */
	virtual ~SortSelection();
};
}
#endif /* MODEL_ENUMS_SORTSELECTION_H_ */
