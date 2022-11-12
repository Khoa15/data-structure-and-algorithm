#pragma once
#ifndef _NUMBER_H_
#define _NUMBER_H_
#include <stdlib.h>
template <class T>
class Number{
public:
    T n;
    Number() : n(0) {}
    Number(T x) : n(x) {}

    int length();
    int generate(int min, int max);
    bool isPrime();
    bool isSquare();
    bool isPerfect();
    bool isAbundant();// tổng các ước số không tính bản thân > chính nó
    bool isOdd();
    bool isEven();
    bool isInt();
    bool isDouble();
};

template <class T>
bool Number<T>::isPrime(){
    if(n < 2) return false;
    if(n == 2) return true;
    if(n % 2 == 0 || n % 3 == 0) return false;
    for(int i = 3; i < sqrt(n); i++){
        if(n % i == 0) return false;
    }

    return false;
}

int random(int mi, int ma){
    return rand() %( ma - mi + 1 )+ mi;
}
#endif