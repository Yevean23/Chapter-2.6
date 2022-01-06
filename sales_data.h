#pragma once
#ifndef string
#include <string>;
#endif

struct sales_data {
	std::string isbn;
	unsigned booksSold = 0;
	double revenue = 0.0;
};