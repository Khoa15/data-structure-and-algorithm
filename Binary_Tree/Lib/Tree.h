#pragma once
#ifndef _TREE_H_
#define _TREE_H_
#include "Node.h"


template <class T>
class Tree : public Node<T>
{
private:
    Node<T> *Root;
    int height;
public:
    Tree() : Root(NULL), height(0) {}
    Tree(Node<T> *root) : Root(root), height(0) {}

    Node<T> *getRoot();

    void init(Node<T> *Root);
    bool isEmpty();
    bool insertTNode(Node<T> *p);
    
    int countTNode(Node<T> *p = getRoot());
    int countTNodeIsLeaf(Node<T> *p = getRoot());
    int countTNodeHaveTwoChild(Node<T> *p = getRoot());
    int sumTNode(Node<T> *p = getRoot());
    int getHeight(Node<T> *p = getRoot());

    void traverseNLR(Node<T> *p = getRoot());
    void traverseLNR(Node<T> *p = getRoot());
    void traverseLRN(Node<T> *p = getRoot());
    void traverseNRL(Node<T> *p = getRoot());
    void traverseRNL(Node<T> *p = getRoot());
    void traverseRLN(Node<T> *p = getRoot());

    void listNodeLargerThanX(Node<T> *p, T x);

    Node<T> *findNode(T x);
};

template <class T>
Node<T> *Tree<T>::getRoot(){
    return Root;
}

template <class T>
void Tree<T>::init(Node<T> *root){
    Root = root;
}

template <class T>
bool Tree<T>::isEmpty(){
    return (Root == NULL);
}

template <class T>
bool Tree<T>::insertTNode(Node<T> *p){
    if(p == NULL) return false;
    if(Root == NULL){
        Root = p;
        return true;
    }
    Node<T> *tmp = Root;
    while(1){
        if(tmp == NULL){
            tmp->setInfo(p->getInfo());
            delete p;
            return true;
        }
        if(tmp->getInfo() < p->getInfo()){
            if(tmp->getNext() == NULL){
                tmp->setNext(p);
                break;
            }
            tmp = tmp->getNext();
        }else{
            if(tmp->getPrev() == NULL){
                tmp->setPrev(p);
                break;
            }
            tmp = tmp->getPrev();
        }
    }
}

template <class T>
int Tree<T>::countTNode(Node<T> *p){
    if(Root == NULL) return 0;
    int nl = countTNode(p->getPrev());
    int nr = countTNode(p->getNext());
    return 1 + nl + nr;
}

template <class T>
int Tree<T>::countTNodeIsLeaf(Node<T> *p){
    if(p == NULL) return 0;
    int countLeafLeft = countTNodeIsLeaf(p->getPrev());
    int countLeafRight = countTNodeIsLeaf(p->getNext());
    return countLeafLeft + countLeafRight;
}

template <class T>
int Tree<T>::countTNodeHaveTwoChild(Node<T> *p){
    if(p == NULL || p->getNext() == NULL || p->getPrev() == NULL) return 0;
    int countNodeLeft = countTNodeHaveTwoChild(p->getPrev());
    int countNodeRight = countTNodeHaveTwoChild(p->getNext());
    return countNodeLeft + countNodeRight + 1;
}

template <class T>
int Tree<T>::sumTNode(Node<T> *p){
    if(p == NULL) return 0;
    int sumLeft = sumTNode(p->getPrev()),
        sumRight = sumTNode(p->getNext());
    return sumLeft + sumRight + p->getInfo();
}

template <class T>
int Tree<T>::getHeight(Node<T> *p){
    if(p == NULL) return 0;
    int heightLeft = getHeight(p->getPrev()),
        heightRight = getHeight(p->getNext());
    return (heightLeft > heightRight) ? heightLeft + 1 : heightRight + 1;
}

template <class T>
void Tree<T>::traverseNLR(Node<T> *p){
    if(p == NULL) return;
    p->showInfo();
    traverseNLR(p->getPrev());
    traverseNLR(p->getNext());
}
template <class T>
void Tree<T>::traverseLNR(Node<T> *p){
    if(p == NULL) return;
    traverseLRN(p->getPrev());
    p->showInfo();
    traverseLRN(p->getNext());
}

template <class T>
void Tree<T>::traverseLRN(Node<T> *p){
    if(p == NULL) return;
    traverseLRN(p->getPrev());
    traverseLRN(p->getNext());
    p->showInfo();
}

template <class T>
void traverseNRL(Node<T> *p){
    if(p == NULL) return;
    p->showInfo();
    traverseNRL(p->getNext());
    traverseNRL(p->getPrev());
}

template <class T>
void traverseRNL(Node<T> *p = getRoot()){
    if(p == NULL) return;
    traverseRNL(p->getNext());
    p->showInfo();
    traverseRNL(p->getPrev());
}

template <class T>
void traverseRLN(Node<T> *p = getRoot()){
    if(p == NULL) return;
    traverseRLN(p->getNext());
    traverseRLN(p->getPrev());
    p->showInfo();
}

template <class T>
void Tree<T>::listNodeLargerThanX(Node<T> *p, T x){
    if(p == NULL) return;
    if(p->getInfo() > x) p->showInfo();
    listNodeLargerThanX(p->getNext());
    listNodeLargerThanX(p->getPrev());
}

template <class T>
Node<T> *Tree<T>::findNode(T x){
    if(Root == NULL) return NULL;
    if(Root->getInfo() == x) return Root;
    Node<T> *tmp = Root;
    while(tmp != NULL){
        if(tmp->getInfo() == x) return tmp;
        if(tmp->getInfo() < x) tmp = tmp->getNext();
        else tmp = tmp->getPrev();
    }
    return tmp;
}
#endif