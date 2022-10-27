#pragma once
#ifndef _NODE_H_
#define _NODE_H_
#include <iostream>
using namespace std;
// typedef int Data;

template <typename T>
class Node{
private:
    T Info;
    Node<T>* pNext;
public:
    Node() : Info(0), pNext(NULL) {}
    Node(T inf) : Info(inf), pNext(NULL) {}

    T getInfo();
    Node<T>* getNext();

    void setInfo(T Info);
    void setNext(Node<T>* p);
};
#endif