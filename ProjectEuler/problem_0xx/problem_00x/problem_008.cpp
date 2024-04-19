#include "problem_00x.hpp"

#include <iostream>
#include <string>
#include <vector>

// Find the 13 adjacent digits in the number that have the greatest product
uint64_t problem_008() {
	//uint64_t value = 0;
	std::string input;
	std::cout << "Enter number: ";
	std::cin >> input;
	std::vector<int> values(input.length());
	for (int i = 0; i < input.length(); i++) {
		values[i] = input.c_str()[i] - '0';
	}

	uint64_t max_product = 0;
	for (int i = 0; (i + 13) < values.size(); i++) {
		uint64_t product = 1;
		for (int j = 0; j < 13; j++) {
			product *= values[i + j];
		}
		if (product > max_product) {
			max_product = product;
		}
	}
	return max_product;
}