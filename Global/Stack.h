#pragma once
#ifndef _STACK_H_
#define _STACK_H_
#include "LinkedList.h"

template <typename T>
class Stack : public SList<T>{
private:
    int sizeStack;
public:
    Stack() : sizeStack(0) {}
    int getSize();
    void setSize();
    int size();
    void push(Node<T>* p);
    void pop();
    Node<T>* top();
};
#endif