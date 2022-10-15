#pragma once
#ifndef _HELPER_
#define _HELPER_
#include <math.h>

template<class T>void swap(T& a, T& b) {
	T c = a;
	a = b;
	b = c;
}

bool isPrime(int x) {
	if (x < 2) return false;
	for (int i = 2; i <= sqrt(x); i++) {
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
#endif