#include "problem_01x.hpp"

#include <vector>
#include <iostream>


// Finding the first triangular number with more than 500 factors
uint64_t problem_012(int target_num_factors) {
	// Find first 500 primes
	const int prime_depth = target_num_factors;
	std::vector<uint64_t> primes(prime_depth);
	{
		int prime = 0;
		for (int i = 2; prime < prime_depth; i++) {
			bool is_prime = true;
			for (int j = 0; j < prime && is_prime; j++) {
				if (i % primes[j] == 0) {
					is_prime = false;
				}
			}
			if (is_prime) {
				primes[prime] = i;
				prime++;
			}
		}
	}
	// For every triangular number check how many times it is divisible by each prime
	// Let n be the number of times it is divisible by a prime + 1
	// The total number of factors is equal to the sum of n for each prime
	bool num_found = false;
	uint64_t num = 1;
	for (int n = 1; !num_found; n++) {
		num = (n * (n + 1)) / 2;
		int num_factors = 1;
		for (int i = 0; i < prime_depth; i++) {
			int times_divisible = 1;
			uint64_t temp_num = num;
			while (temp_num % primes[i] == 0) {
				times_divisible++;
				temp_num /= primes[i];
			}
			num_factors *= times_divisible;
		}
		if (num_factors >= target_num_factors) {
			num_found = true;
		}
	}
	return num;
}