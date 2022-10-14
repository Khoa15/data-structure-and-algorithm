/*
Nguyễn Trọng Đăng Khoa
2001215879
12DHTHTD
*/
#pragma once
#ifndef _LINKED_LIST_
#define _LINKED_LIST_
#include <iostream>
#include <math.h>
#include "Node.h"

class SList {
    Node* pHead;
    Node* pTail;
public:
    SList() : pHead(NULL), pTail(NULL) {}
    SList(Node* p) : pHead(p), pTail(p) {}
    ~SList() { delete[] pHead; delete pTail; }
    
    bool isEmpty() { return pHead == NULL; }
    Node* getHead() { return pHead; }
    Node* getTail() { return pTail; }
    void setHead(Node* x) { pHead = x; }
    void setTail(Node* x) { pTail = x; }

    void addHead(Node* p);
    void addTail(Node* p);
    void addXBeforeY(Data x, Data y);
    void deleteNode(Node* p);
    void deleteNodeLargerX(Data x);
    void deleteEvenVal();
    void sort(bool isASC = false);
    int countPrimeNumber();
    int totalSquareNumber();
    Node* findMinVal();
    Node* findMaxVal();
    int countXLarger2Y();
    void divideList(SList* sl1, SList* sl2);

    void printSList(bool isFraction = false) {
        for (Node* p = pHead; p != NULL; p = p->pNext) {
            if (isFraction == false)
                std::cout << p->top << " ";
            else
                std::cout << p->top << "/" << p->bot << " ";
        }
        std::cout << std::endl;
    }

    //2
    void getListInput(int n);
    void simplifyListFraction();
    Node sumListFraction();
    Node multipleListFraction();
    Node* findMinFraction();
    Node* findMaxFraction();
    void plusListFraction(Data x = 1);
    void printListFractionLargeY(Data y = 1);
    Node* findNode(Node x);
};

#endif