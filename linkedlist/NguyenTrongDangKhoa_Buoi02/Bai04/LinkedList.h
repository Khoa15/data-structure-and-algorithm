#pragma once
#ifndef _LINKED_LIST_H_
#define _LINKED_LIST_H_
#include <iostream>
#include <math.h>
using namespace std;
struct DATHUC{
    float coso;
    int somu;
};

typedef DATHUC Data;
class Node{
private:
    Data Info;
    Node* pNext;
public:
    Node() : pNext(NULL) {}
    Node(Data x) : Info(x), pNext(NULL) {}
    Node(Data x, Node* next) : Info(x), pNext(next) {}

    Node* getNext(){return pNext;}
    void setNext(Node* p){pNext = p;}
    Data getInfo(){return Info;}
    void setInfo(float c, int s){Info.coso = c; Info.somu = s;}


    Node* plus(Node* q);
    Node* minus(Node* q);
    Node* multiply(Node* q);

    float calculate(int x);
};

class LinkedList
{
private:
    Node* pHead;
public:
    LinkedList() : pHead(NULL) {}
    LinkedList(Node* p) : pHead(p) {}

    Node* getHead(){return pHead;}
    void setHead(Node* p){pHead = p;}
    void deleteNode(Node* p);
    void sortDESC();
    void simply();
    void addMonomial(Node* p);
    void deleteMonomial(int bac);
    float calculate(int x);
    
};

#endif