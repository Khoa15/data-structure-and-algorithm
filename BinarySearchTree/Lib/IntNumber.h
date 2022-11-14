#pragma once
#ifndef _INT_NUMBER_H_
#define _INT_NUMBER_H_
#include <stdlib.h>
#include <math.h>
int random(int mi, int ma);
int gcd(int a, int b);

class IntNumber{
private:
    int n;
public:
    IntNumber() : n(0) {}
    IntNumber(int x) : n(x) {}

    int value();
    bool input();
    int length();
    int generate(int min, int max);
    bool isPrime();
    bool isSquare();
    bool isPerfect();
    bool isAbundant();// tổng các ước số không tính bản thân > chính nó
    bool isOdd();
    bool isEven();
};

int IntNumber::value(){
    return n;
}

bool IntNumber::input(){
    if(cin >> n) return true;
    return false;
}

int IntNumber::length(){
    int i = abs(n),
        l = 0;
    while(i){
        i /= 10;
        l += 1;
    }
    return l;
}

int IntNumber::generate(int min, int max){
    n = random(min, max);
    return n;
}

bool IntNumber::isPrime(){
    if(n < 2) return false;
    if(n == 2) return true;
    if(n % 2 == 0 || n % 3 == 0) return false;
    for(int i = 3; i < sqrt(n); i++){
        if(n % i == 0) return false;
    }

    return false;
}

bool IntNumber::isSquare(){
    if(n < 0) return false;
    return sqrt(n) * sqrt(n) == n;
}

bool IntNumber::isPerfect(){
    if(n < 0) return false;
    int s = 0;
    for(int i = 1; i < n/2; i++){
        s += (n % i == 0) ? i : 0;
    }
    return s == n;
}

bool IntNumber::isAbundant(){
    if(n < 0) return false;
    int s = 0;
    for(int i = 1; i < n/2; i++){
        s += (n % i == 0) ? i : 0;
    }

    return s > 0;
}

bool IntNumber::isEven(){
    return abs(n) % 2 == 0;
}

bool IntNumber::isOdd(){
    return abs(n) % 2 != 0;
}

int random(int mi, int ma){
    return rand() %( ma - mi + 1 )+ mi;
}
#endif