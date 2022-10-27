#pragma once
#ifndef _LINKED_LIST_H_
#define _LINKED_LIST_H_
#include "Node.h"
template <typename T>
class SList{
private:
    Node<T>* pHead;
    Node<T>* pTail;
public:
    SList() : pHead(NULL), pTail(NULL) {}
    SList(Node<T>* head, Node<T>* tail) : pHead(head), pTail(tail) {}
    
    Node<T>* getHead();
    Node<T>* getTail();

    void setHead(Node<T>* p);
    void setTail(Node<T>* p);

    bool isEmpty();
    
    bool insertHead(Node<T>* p);
    bool insertTail(Node<T>* p);
    bool insertBeforeNode(Node<T>* p, Node<T>* cur);

    Node<T>* findNode(T x);
    Node<T>* getBeforeNode(Node<T>* cur);

    bool deleteNode(Node<T>* p);
};
#endif