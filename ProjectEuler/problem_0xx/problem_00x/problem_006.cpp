#include "problem_00x.hpp"

#include <iostream>

uint64_t problem_006() {
	int sum = 0;
	for (int i = 0; i <= 100; i++) {
		std::cout << i << std::endl;
		for (int j = i + 1; j <= 100; j++) {
			sum += i * j;
		}
	}
	sum *= 2;
	return sum;
}