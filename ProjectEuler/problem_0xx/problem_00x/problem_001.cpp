#include <cstdint>

#include "problem_00x.hpp"

// Find the sum of all the multiples of 3 and 5 below n
uint64_t problem_001(uint64_t n) {
	int sum = 0;
	for (int i = 0; i < n; i++) {
		if (i % 3 == 0 || i % 5 == 0) {
			sum += i;
		}
	}
	return sum;
}

int problem_001_new() {
	int n = 1000;
	int m = n / 15;
	int t = m * 45;
	if (m > 0) {
		t += 105 * m * (m - 1) / 2;
	}
	for (int i = m * 15; i < n; i++) {
		if (i % 3 == 0 || i % 5 == 0) {
			t += i;
		}
	}
	return t;
}