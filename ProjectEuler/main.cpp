#include <iostream>

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
	int sum = 0;
	int n = 1000 / 15;
	if (n > 0) {
		sum = (n - 1) * n * 15 * 3 + (n + 1) * 60;
	}
	return sum;
	if (1000 % 15 < 3) {
		return sum;
	}
	sum += 3 + (n + 1) * 15;
	if (1000 % 15 < 5) {
		return sum;
	}
	sum += 5 + (n + 1) * 15;
	if (1000 % 15 < 6) {
		return sum;
	}
	sum += 6 + (n + 1) * 15;
	if (1000 % 15 < 9) {
		return sum;
	}
	sum += 9 + (n + 1) * 15;
	if (1000 % 15 < 10) {
		return sum;
	}
	sum += 10 + (n + 1) * 15;
	if (1000 % 15 < 12) {
		return sum;
	}
	sum += 12 + (n + 1) * 15;
	return sum;
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

// Largest prime factor of 600851475143
// Not good
int problem_3() {
	long long last_factor = 1;
	for (long long i = 1; i < 600851475143; i++) {
		bool is_factor = 600851475143 % i == 0;
		if (!is_factor) {
			continue;
		}
		bool is_prime = true;
		for (int j = 2; j < i && is_prime; i++) {
			if (i % j == 0) {
				is_prime = false;
				break;
			}
		}
		if (is_prime) {
			last_factor = i;
		}
	}
	return last_factor;
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

int main() {
	std::cout << problem_6();
}