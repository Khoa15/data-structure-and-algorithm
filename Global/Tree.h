#pragma once
#ifndef _TREE_H_
#define _TREE_H_
#include "TNode.h"


template <class T>
class Tree : public TNode<T>
{
private:
    TNode<T> *Root;
    int height;
public:
    Tree() : Root(NULL), height(0) {}
    Tree(TNode<T> *root) : Root(root), height(0) {}

    TNode<T> *getRoot();

    void init(TNode<T> *Root);
    bool isEmpty();
    bool insertTNode(TNode<T> *p);
    
    int countTNode(TNode<T> *p = getRoot());
    int countTNodeIsLeaf(TNode<T> *p = getRoot());
    int countTnodeHaveTwoChild(TNode<T> *p = getRoot());
    int sumTNode(TNode<T> *p = getRoot());
    int getHeight(TNode<T> *p = getRoot());

    void traverseNLR(TNode<T> *p = getRoot());
    void traverseLNR(TNode<T> *p = getRoot());
    void traverseLRN(TNode<T> *p = getRoot());

    TNode<T> *findTNode(T x);
};

template <class T>
TNode<T> *Tree<T>::getRoot(){
    return Root;
}

template <class T>
void Tree<T>::init(TNode<T> *root){
    Root = root;
}

template <class T>
bool Tree<T>::isEmpty(){
    return (Root == NULL);
}

template <class T>
bool Tree<T>::insertTNode(TNode<T> *p){
    if(p == NULL) return false;
    TNode<T> *tmp = Root;
    while(1){
        if(tmp == NULL){
            tmp = p;
            return true;
        }
        if(tmp->getInfo() < p->getInfo()){
            tmp = tmp->getNext();
        }else{
            tmp = tmp->getPrev();
        }
    }
}

template <class T>
int Tree<T>::countTNode(TNode<T> *p){
    if(Root == NULL) return 0;
    int nl = countTNode(p->getPrev());
    int nr = countTNode(p->getNext());
    return 1 + nl + nr;
}

template <class T>
int Tree<T>::countTNodeIsLeaf(TNode<T> *p){
    if(p == NULL) return 0;
    int countLeafLeft = countTNodeIsLeaf(p->getPrev());
    int countLeafRight = countTNodeIsLeaf(p->getNext());
    return countLeafLeft + countLeafRight;
}

template <class T>
int Tree<T>::countTnodeHaveTwoChild(TNode<T> *p){
    if(p == NULL || p->getNext() == NULL || p->getPrev() == NULL) return 0;
    int countNodeLeft = countTnodeHaveTwoChild(p->getPrev());
    int countNodeRight = countTnodeHaveTwoChild(p->getNext());
    return countNodeLeft + countNodeRight + 1;
}

template <class T>
int Tree<T>::sumTNode(TNode<T> *p){
    if(p == NULL) return 0;
    int sumLeft = sumTNode(p->getPrev()),
        sumRight = sumTNode(p->getNext());
    return sumLeft + sumRight + p->getInfo();
}

template <class T>
int Tree<T>::getHeight(TNode<T> *p){
    if(p == NULL) return 0;
    int heightLeft = getHeight(p->getPrev()),
        heightRight = getHeight(p->getNext());
    return (heightLeft > heightRight) ? heightLeft + 1 : heightRight + 1;
}

template <class T>
void Tree<T>::traverseNLR(TNode<T> *p){
    if(p == NULL) return;
    p->showInfo();
    traverseNLR(p->getNext());
    traverseNLR(p->getPrev());
}
template <class T>
void Tree<T>::traverseLNR(TNode<T> *p){
    if(p == NULL) return;
    traverseLRN(p->getPrev());
    p->showInfo();
    traverseLRN(p->getNext()());
}

template <class T>
void Tree<T>::traverseLRN(TNode<T> *p){
    if(p == NULL) return;
    traverseLRN(p->getPrev());
    traverseLRN(p->getNext());
    p->showInfo();
}

template <class T>
TNode<T> *Tree<T>::findTNode(T x){
    if(Root == NULL) return NULL;
    if(Root->getInfo() == x) return Root;
    TNode<T> *tmp = Root;
    while(tmp != NULL){
        if(tmp->getInfo() == x) return tmp;
        if(tmp->getInfo() < x) tmp = tmp->getNext();
        else tmp = tmp->getPrev();
    }
    return tmp;
}
#endif