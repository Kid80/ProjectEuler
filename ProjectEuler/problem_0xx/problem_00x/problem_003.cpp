#include <cstdint>

#include "problem_00x.hpp"

#include <vector>

uint64_t problem_003(uint64_t n) {
	if (n <= 1) {
		return 0;
	}
	std::vector<uint64_t> prime_factors;
	for (int i = 2; i < n; i++) {
		if (n % i == 0) {
			//__debugbreak();
			bool is_prime = true;
			for (int j = 0; j < prime_factors.size() && is_prime; j++) {
				if (i % prime_factors[j] == 0) {
					is_prime = false;
				}
			}
			if (is_prime) {
				prime_factors.push_back(i);
			}
		}
	}
	//__debugbreak();
	return prime_factors[prime_factors.size() - 1];
}