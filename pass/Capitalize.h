/*
 * Capitalize.h
 *
 *  Created on: 2012/10/20
 *      Author: sagara
 */

#ifndef CAPITALIZE_H_
#define CAPITALIZE_H_

#include <functional>

struct Capitalize : public std::unary_function<std::string&, std::string> {
public:
	std::string operator()(std::string&);
};

#endif /* CAPITALIZE_H_ */
