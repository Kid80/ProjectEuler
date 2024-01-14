#include <cstdint>

#include "problem_00x.hpp"

// The sum of all the even fibonacci numbers below n
uint64_t problem_002(uint64_t n) {
	int sum = 0;
	int numbers[2];
	numbers[0] = 0;
	numbers[1] = 1;
	int index = 0;
	while (numbers[0] < n && numbers[1] < n) {
		numbers[index % 2] = numbers[0] + numbers[1];
		index++;
		sum += numbers[index % 2] % 2 == 0 ? numbers[index % 2] : 0;
	}
	return sum;
}