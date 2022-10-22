#pragma once
#ifndef _BIG_INT_H_
#define _BIG_INT_H_
#include <iostream>
#include <math.h>
#include <string.h>
using namespace std;
class Node{
public:
    char val[2];
    Node* pNext;

    Node() : val("\0"), pNext(NULL) {}

};

class BigInt{
public:
    Node* pHead;
    Node* pTail;
    bool isPositive = true;
    BigInt() : pHead(NULL), pTail(NULL) {}
    int length = 0;
    void printNumbers(Node* p);
    void addNumber(Node* p);
    
    BigInt* plus(BigInt *Q);
    BigInt* minus(BigInt *Q);
    BigInt* multiply(BigInt *Q);
    BigInt* divide(BigInt *Q);
};
#endif