/*
 * pass.cpp
 *
 *  Created on: 2012/10/20
 *      Author: sagara
 */

#include <iostream>
#include <string>
#include <ctime>
#include <vector>

#include <boost/random.hpp>
#include <boost/foreach.hpp>
#include <boost/algorithm/string.hpp>
#include <boost/range.hpp>

const std::string CHARS =
		"0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
const int LENGTH = 8;
const int NUM = 10;

typedef boost::mt19937 Engine;
typedef boost::uniform_smallint<> Distribution;
typedef boost::variate_generator<Engine, Distribution> Generator;

std::string password(Generator& rand)
{
	std::string pass = "";
	for (int i = 0; i < LENGTH; ++i)
		pass += CHARS[rand()];
	return pass;
}

void capitalize(std::string& str)
{
	boost::to_lower(str);
	boost::iterator_range<std::string::iterator> r(
			boost::make_iterator_range(str.begin(), str.begin() + 1));
	boost::to_upper(r);
}

int main()
{
	std::vector<std::string> passwords;

	Engine gen(static_cast<unsigned long>(time(0)));
	Distribution dst(0, CHARS.length() - 1);
	Generator rand(gen, dst);

	for (int i = 0; i < NUM; ++i)
		passwords.push_back(password(rand));

	BOOST_FOREACH(std::string& pass, passwords)
		capitalize(pass);

	BOOST_FOREACH(std::string& pass, passwords)
		std::cout << pass << std::endl;

	return EXIT_SUCCESS;
}
