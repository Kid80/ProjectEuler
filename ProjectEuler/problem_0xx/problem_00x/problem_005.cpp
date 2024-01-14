#include <cstdint>

#include "problem_00x.hpp"

#include <vector>

// LCM of all the numbers 1 - n
uint64_t problem_005(uint64_t n) {
	if (n == 1) {
		return 1;
	}
	std::vector<int> primes;
	for (int i = 2; i < n; i++) {
		bool is_prime = true;
		for (int j = 0; j < primes.size() && is_prime; j++) {
			if (i % primes[j] == 0) {
				is_prime = false;
			}
		}
		if (is_prime) {
			primes.push_back(i);
		}
	}
	std::vector<int> prime_factors(primes.size());
	for (int i = 2; i < n; i++) {
		for (int j = 0; j < primes.size(); j++) {
			int value = i;
			int power = 0;
			while (value % primes[j] == 0) {
				power++;
				value /= primes[j];
			}
			if (power > prime_factors[j]) {
				prime_factors[j] = power;
			}
		}
	}
	int result = 1;
	for (int i = 0; i < primes.size(); i++) {
		for (int j = 0; j < prime_factors[i]; j++) {
			result *= primes[i];
		}
	}
	return result;
}