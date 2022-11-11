#pragma once
#ifndef _NUMBER_H_
#define _NUMBER_H_
#include <stdlib.h>
template <typename T>
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

int random(int mi, int ma){
    return rand() %( ma - mi + 1 )+ mi;
}
#endif