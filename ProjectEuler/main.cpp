#include <iostream>

#include <chrono>
#include <vector>

// Find the sum of all the multiples of 3 and 5 below 1000
int problem_1() {
	int sum = 0;
	for (int i = 0; i < 1000; i++) {
		if (i % 3 == 0 || i % 5 == 0) {
			sum += i;
		}
	}
	return sum;
}

int problem_1_new() {
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


// The sum of all the even fibonacci numbers below 4,000,000
int problem_2() {
	int sum = 0;
	int numbers[2];
	numbers[0] = 0;
	numbers[1] = 1;
	int index = 0;
	while (numbers[0] < 4000000 && numbers[1] < 4000000) {
		numbers[index % 2] = numbers[0] + numbers[1];
		index++;
		sum += numbers[index % 2] % 2 == 0 ? numbers[index % 2] : 0;
	}
	return sum;
}

// The largest prime factor of n
typedef unsigned long long problem_3_t;

int problem_3(problem_3_t n) {
	if (n <= 1) {
		return 0;
	}
	std::vector<problem_3_t> prime_factors;
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

// LCM of all the numbers 1 - n
int problem_5(int n) {
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

bool is_palindrome(int n) {
	int length = 1;
	for (int pow_ten = 10; pow_ten <= n; pow_ten *= 10) {
		length++;
	}
	n 
	return true;
}

int main() {
	//600851475143
	auto start = std::chrono::high_resolution_clock::now();
	//std::cout << problem_3(600851475143);
	//std::cout << problem_7(10001) << std::endl;
	//std::cout << problem_9(1000) << std::endl;
	is_palindrome(10);
	auto end = std::chrono::high_resolution_clock::now();
	auto time = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
	std::cout << "Time taken: " << time.count() << "ms\n";
	while (1);
	return 0;
}