#pragma once
#ifndef _LINKED_LIST_H_
#define _LINKED_LIST_H_
#include "Node.h"
template <class T>
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

    void cleanList();
};
template class SList<int>;
template class SList<float>;


template <typename T>
Node<T>* SList<T>::getHead(){
    return pHead;
}

template <typename T>
Node<T>* SList<T>::getTail(){
    return pTail;
}

template <typename T>
void SList<T>::setHead(Node<T>* p){
    pHead = p;
}

template <typename T>
void SList<T>::setTail(Node<T>* p){
    pTail = p;
}

template <typename T>
bool SList<T>::isEmpty(){
    return (getHead() == NULL) ? true : false;
}

template <typename T>
bool SList<T>::insertHead(Node<T>* p){
    if(p == NULL) return false;
    if(isEmpty() == true){
        setHead(p);
        setTail(p);
        return true;
    }
    p->setNext(getHead());
    setHead(p);
    return true;
}

template <typename T>
bool SList<T>::insertTail(Node<T>* p){
    if(p == NULL) return false;
    if(isEmpty() == true){
        setHead(p);
        setTail(p);
        return true;
    }
    getTail()->setNext(p);
    setTail(p);
    return true;
}

template <typename T>
bool SList<T>::insertBeforeNode(Node<T>* p, Node<T>* cur){
    if(p == NULL || cur == NULL) return false;
    Node<T>* nodeBefore = getBeforeNode(cur);
    if(nodeBefore == NULL) return false;
    nodeBefore->setNext(p);
    p->setNext(cur);
    return true;
}

template <typename T>
Node<T>* SList<T>::findNode(T x){
    for(Node<T>* tmp = getHead(); tmp != NULL; tmp = tmp->getNext()){
        if(tmp->getInfo() == x){
            return tmp;
        }
    }
    return NULL;
}

template <typename T>
Node<T>* SList<T>::getBeforeNode(Node<T>* cur){
    for(Node<T>* tmp = getHead(); tmp->getNext() != NULL; tmp = tmp->getNext()){
        if(tmp->getNext() == cur){
            return tmp;
        }
    }
    return NULL;
}

template <typename T>
bool SList<T>::deleteNode(Node<T>* p){
    if(isEmpty() == true || p == NULL) return false;
    if(getHead() == p && getTail() == p){
        setHead(NULL);
        setTail(NULL);
        delete p;
        return true;
    }
    if(getHead() == p){
        setHead(p->getNext());
        delete p;
        return true;
    }
    Node<T>* nodeBefore = getBeforeNode(p);
    if(nodeBefore == NULL) return false;
    nodeBefore->setNext(p->getNext());
    delete p;
    return true;
}

template <typename T>
void SList<T>::cleanList(){
    Node<T> *tmp = getHead();
    while(tmp != NULL){
        Node<T> *next = tmp->getNext();
        delete tmp;
        tmp = next;
    }
    setHead(NULL);
    setTail(NULL);
}
#endif