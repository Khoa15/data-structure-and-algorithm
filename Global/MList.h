#pragma once
#ifndef _M_LIST_H_
#define _M_LIST_H_
#include "LinkedList.h"

template <class T>
class MList : public SList<T>
{
private:
    SList<T> *pHead;
    SList<T> *pTail;
public:
    MList() : pHead(NULL), pTail(NULL) {}
    ~MList();

    void setHead(SList<T> *head);
    void setTail(SList<T> *tail);

    SList<T> *getHead();
    SList<T> *getTail();

    void insertHead(SList<T> *l);
    void insertTail(SList<T> *l);

    bool deleteSList(SList<T> *l);
};

template <class T>
void MList<T>::setHead(SList<T> *head){
    pHead = head;
}

template <class T>
void MList<T>::setTail(SList<T> *tail){
    pTail = tail;
}

template <class T>
SList<T> *getHead(){
    return pHead;
}

template <class T>
SList<T> *getTail(){
    return pTail;
}

template <class T>
void MList<T>::insertHead(SList<T> *l){
    if(l == NULL) return;
    if(getHead() == NULL){
        setHead(l);
        setTail(l);
        return;
    }
    l->setNext(getHead());
    setHead(l);
}

template <class T>
void MList<T>::insertTail(SList<T> *l){
    if(l == NULL) return;
    if(getTail() == NULL){
        setHead(l);
        setTail(l);
        return;
    }
    getTail()->setNext(l);
    setTail(l);
}

template <class T>
bool MList<T>::deleteSList(SList<T> *l){
    if(l == NULL) return false;
    if(getHead() == l){
        setHead(l->getNext());
        if(getTail() == l){
            setTail(NULL);
        }
    }
    SList<T> *tmp = getHead();
    while(tmp->getNext() != NULL){
        if(tmp->getNext() == l){
            
        }
    }
}
#endif