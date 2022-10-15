#pragma once
#ifndef _HELPER_
#define _HELPER_
#include <math.h>
#include <time.h>
bool isPrime(int x) {
	if (x < 2) return false;
	for (int i = 0; i < sqrt(x); i++) {
		if (x % i == 0) {
			return false;
		}
	}
	return true;
}

bool isSquare(int x) {
	if (sqrt(x) * sqrt(x) == x) return true;
	return false;
}

int gcd(int a, int b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}

int randrange(int min, int max) {
	return (rand() % (max - min + 1)) + min;
}
#endif