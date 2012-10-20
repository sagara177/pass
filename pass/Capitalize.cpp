/*
 * Capitalize.cpp
 *
 *  Created on: 2012/10/20
 *      Author: sagara
 */

#include <string>
#include <sstream>
#include <cstring>

#include "Capitalize.h"

std::string Capitalize::operator()(std::string& s) {
	std::stringstream ss;
	for (size_t i = 0; i < s.size(); ++i) {
		char c;
		ss << (c = (i == 0) ? toupper(s.at(i)) : tolower(s.at(i)));
	}
	return ss.str();
}
