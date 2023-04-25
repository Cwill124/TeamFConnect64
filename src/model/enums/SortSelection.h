/*
 * SortSelection.h
 *
 *  Created on: Apr 25, 2023
 *      Author: adecesa1
 */

#ifndef MODEL_ENUMS_SORTSELECTION_H_
#define MODEL_ENUMS_SORTSELECTION_H_

namespace enums {
class SortSelection final {
public:
	enum Selection {
		TIME, NUMBER
	};

	SortSelection();
	virtual ~SortSelection();
};
}
#endif /* MODEL_ENUMS_SORTSELECTION_H_ */
