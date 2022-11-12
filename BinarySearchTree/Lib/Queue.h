#pragma once
#ifndef _QUEUE_H_
#define _QUEUE_H_
#include "LinkedList.h"

template <class T>
class Queue : public SList<T>{
private:
    int sizeQueue;
public:
    Queue() : sizeQueue(0){}
    void push(Node<T>* p);
    // SList<T>* getList();
    int getSize();
    void setSize(int sizeStack);
    void pop();
    Node<T>* top();
};

// template <typename T>
// SList<T>* getList(){
//     return SList<T>::getHead();
// }

template <typename T>
int Queue<T>::getSize(){
    return sizeQueue;
}

template <typename T>
void Queue<T>::setSize(int sizeQueue){
    sizeQueue = sizeQueue;
}

template <typename T>
void Queue<T>::push(Node<T>* p){
    if(SList<T>::insertTail(p) == true){
        sizeQueue += 1;
    }
}

template <typename T>
void Queue<T>::pop(){
    if(SList<T>::deleteNode(SList<T>::getHead()) == true){
        sizeQueue -= 1;
    }
}

template <typename T>
Node<T>* Queue<T>::top(){
    return SList<T>::getHead();
}
#endif