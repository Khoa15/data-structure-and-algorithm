#pragma once
#ifndef _NODE_H_
#define _NODE_H_
#include <iostream>
using namespace std;
// typedef int Data;

template <class T>
class Node{
private:
    T Info;
    Node<T>* pNext;
    Node<T>* pPrev;
public:
    Node() : Info(0), pNext(NULL), pPrev(NULL) {}
    Node(T inf) : Info(inf), pNext(NULL), pPrev(NULL) {}

    T getInfo();
    Node<T> *getNext();
    Node<T> *getPrev();

    void setInfo(T Info);
    void setNext(Node<T>* p);
    void setPrev(Node<T>* p);

    void showInfo(){
        cout << Info << "\t";
    }
};
template <typename T>
Node<T>* createNode(T x){
    Node<T> *p = new Node(x);
    if(p == NULL){
        cout << "Your memory is not enough";
        return NULL;
    }
    return p;
}



template <typename T>
T Node<T>::getInfo(){
    return Info;
}

template <typename T>
Node<T>* Node<T>::getNext(){
    return pNext;
}

template <typename T>
Node<T> *Node<T>::getPrev(){
    return pPrev;
}

template <typename T>
void Node<T>::setPrev(Node<T> *p){
    pPrev = p;
}

template <typename T>
void Node<T>::setInfo(T Info){
    Info = Info;
}

template <typename T>
void Node<T>::setNext(Node* p){
    pNext = p;
}
#endif