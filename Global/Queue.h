#pragma once
#ifndef _QUEUE_H_
#define _QUEUE_H_
#include "Stack.h"

template <typename T>
class Queue : public Stack<T>, public LinkedList<T>{
public:
    void push(Node<T>* p);
    // void pop();
};
#endif