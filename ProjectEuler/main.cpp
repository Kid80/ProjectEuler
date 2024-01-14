#include <iostream>

#include <chrono>
#include <vector>

int problem_6() {
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

// Find the nth prime
int problem_7(long long int n) {
	std::vector<long long int> primes(n);
	int i = 0;
	int number = 2;
	while (i < n) {
		bool is_prime = true;
		for (int j = 0; j < i && is_prime; j++) {
			if (number % primes[j] == 0) {
				is_prime = false;
			}
		}
		if (is_prime) {
			primes[i] = number;
			i++;
		}
		number++;
	}
	return primes[n - 1];
}


// a^2 + b^2 = c^2
// a + b + c = n
// find abc
int problem_9(int n) {
	int a = 0;
	int b = 0;
	int c = 0;
	for (b = 1; b < n; b++) {
		float a_f = ((float)n * n - 2 * b * n) / (2 * n - 2 * b);
		a = (n * n - 2 * b * n) / (2 * n - 2 * b);
		if (a_f == (float)a) {
			float c_f = std::sqrt(a * a + b * b);
			c = (int)c_f;
			if ((float)c == c_f) {
				return a * b * c;
			}
		}
	}
}

// Problem 10
// Find sum of primes up to n
uint64_t problem_10(int n) {
	std::vector<int> primes;
	uint64_t sum = 0;
	for (int i = 2; i < n; i++) {
		bool is_prime = true;
		for (int j = 0; j < primes.size() && is_prime; j++) {
			if (i % primes[j] == 0) {
				is_prime = false;
			}
		}
		if (is_prime) {
			primes.push_back(i);
			sum += i;
		}
	}
	return sum;
}

// Collatz sequence
// If n is odd, n = 3n + 1
// If n is even, n = n / 2

// Problem 14:
// Find the longest Collatz Sequence below n
uint64_t problem_14(int n) {
	uint64_t longest_chain = 0;
	uint64_t longest_start = 1;
	std::vector<uint64_t> lengths(n);
	lengths[0] = 0;
	lengths[1] = 0;
	for (int i = 2; i < n; i++) {
		uint64_t current = i;
		int length = 0;
		while (current >= i) {
			length++;
			if (current % 2 == 0) {
				current /= 2;
			}
			else {
				current = current * 3 + 1;
			}
		}
		length += lengths[current];
		lengths[i] = length;
		if (length > longest_chain) {
			longest_chain = length;
			longest_start = i;
		}
	}
	return longest_start;
}

int main() {
	//600851475143
	auto start = std::chrono::high_resolution_clock::now();
	//std::cout << problem_3(600851475143);
	//std::cout << problem_7(10001) << std::endl;
	//std::cout << problem_9(1000) << std::endl;
	std::cout << "Result: " << problem_14(1000000) << std::endl;
	auto end = std::chrono::high_resolution_clock::now();
	auto time = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
	std::cout << "Time taken: " << time.count() << "ms\n";
	while (1);
	return 0;
}