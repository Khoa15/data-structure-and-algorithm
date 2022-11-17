#pragma once
#ifndef _QUEUE_H_
#define _QUEUE_H_
#include "LinkedList.h"

template <class T>
class Queue : public SList<T>{
private:
    SList<T> *Head;
    SList<T> *Tail;
    int sizeQueue;
public:
    Queue() : Head(NULL), Tail(NULL), sizeQueue(0) {}
    void setHead(SList<T> *l);
    void setTail(SList<T> *l);

    SList<T> *getHead();
    SList<T> *getTail();

    void push(SList<T>* p);
    int getSize();
    void setSize(int sizeStack);
    SList<T>* pop();
    SList<T>* top();
};

template <class T>
void Queue<T>::setHead(SList<T> *l){
    Head = l;
}

template <class T>
void Queue<T>::setTail(SList<T> *l){
    Tail = l;
}

template <class T>
SList<T> *Queue<T>::getHead(){
    return Head;
}

template <class T>
SList<T> *Queue<T>::getTail(){
    return Tail;
}

template <typename T>
int Queue<T>::getSize(){
    return sizeQueue;
}

template <typename T>
void Queue<T>::setSize(int sizeQueue){
    sizeQueue = sizeQueue;
}

template <typename T>
void Queue<T>::push(SList<T>* p){
    if(p == NULL) return;
    sizeQueue += 1;
    if(getHead() == NULL){
        setHead(p);
        return;
    }
    getTail()->setNext(p);
    setTail(p);
}

template <typename T>
SList<T>* Queue<T>::pop(){
    if(getHead() == NULL) return NULL;
    SList<T> *p = getHead();
    setHead(p->getNext());
    return p;
}

template <typename T>
SList<T>* Queue<T>::top(){
    return getHead();
}
#endif