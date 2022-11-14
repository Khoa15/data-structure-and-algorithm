#pragma once
#ifndef _TNODE_H_
#define _TNODE_H_
#include "Node.h"

template <class T>
class TNode : public Node<T>
{
public:
    TNode<T> *getNext();
    TNode<T> *getPrev();

    bool isLeaf();
    bool deleteTNodeLeft();
    bool deleteTNodeRight();
    TNode<T> *createTNode(T info);
};

template <class T>
bool TNode<T>::isLeaf(){
    return (this->getNext() == NULL && this->getPrev() == NULL);
}

template <class T>
bool TNode<T>::deleteTNodeLeft(){
    if(this == NULL || isLeaf(this->getPrev()) == false) return false;
    delete this->getPrev();
    this->setPrev(NULL);
    return true;
}

template <class T>
bool TNode<T>::deleteTNodeRight(){
    if(this == NULL || isLeaf(this->getNext()) == false) return false;
    delete this->getNext();
    this->setNext(NULL);
    return true;
}

template <class T>
TNode<T> *TNode<T>::createTNode(T info){
    TNode<T> *p = new TNode<T>(info);
    if(p == NULL){
        cout << "Your memory is not enough\n";
    }
    return p;
}


#endif