#pragma once
#ifndef _INT_NUMBER_H_
#define _INT_NUMBER_H_
#include <stdlib.h>
#include <math.h>

int random(int mi, int ma){
    return rand() %( ma - mi + 1 )+ mi;
}

int length(int n){
    int i = abs(n),
        l = 0;
    while(i){
        i /= 10;
        l += 1;
    }
    return l;
}

int generate(int min, int max){
    return random(min, max);
}

bool isPrime(int n){
    if(n < 2) return false;
    if(n == 2) return true;
    if(n % 2 == 0 || n % 3 == 0) return false;
    for(int i = 3; i < sqrt(n); i++){
        if(n % i == 0) return false;
    }

    return false;
}

bool isSquare(int n){
    if(n < 0) return false;
    return sqrt(n) * sqrt(n) == n;
}

bool isPerfect(int n){
    if(n < 0) return false;
    int s = 0;
    for(int i = 1; i < n/2; i++){
        s += (n % i == 0) ? i : 0;
    }
    return s == n;
}

bool isAbundant(int n){
    if(n < 0) return false;
    int s = 0;
    for(int i = 1; i < n/2; i++){
        s += (n % i == 0) ? i : 0;
    }

    return s > 0;
}

bool isEven(int n){
    return abs(n) % 2 == 0;
}

bool isOdd(int n){
    return abs(n) % 2 != 0;
}
#endif