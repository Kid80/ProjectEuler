#include <iostream>

#include "Problem3/problem3.h"
#include <chrono>

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
	std::cout << problem_1_new();
	while (1);
	return 0;
}