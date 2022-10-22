#pragma once
#ifndef _NODE_H_
#define _NODE_H_
#include <iostream>
using namspace std;
typedef int Data;
class Node{
private:
    Data Info;
    Node* pNext;
public:
    Node() : pNext(NULL) {}

    Data getInfo();
    Node* getNext();

    void setInfo(Data Info);
    void setNext(Node* p);
};
#endif