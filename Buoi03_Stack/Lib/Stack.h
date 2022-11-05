#pragma once
#ifndef _STACK_H_
#define _STACK_H_
#include "LinkedList.h"

template <class T>
class Stack : public SList<T>{
private:
    int sizeStack;
    SList<T> *sl;
public:
    Stack() : sizeStack(0), sl(new SList<T>()) {}
    bool isEmpty();
    SList<T>* getList();
    int getSize();
    void setSize(int sizeStack);
    int size();
    void push(Node<T>* p);
    void pop();
    void showList();
    Node<T>* top();
};

// template <typename T>
// Stack<T>::Stack(){
//     cout << SList<T>::getHead();
// }

template <typename T>
bool Stack<T>::isEmpty(){
    return (sl->getHead() == NULL);
}

template <typename T>
SList<T>* Stack<T>::getList(){
    return sl;
}
template <typename T>
int Stack<T>::getSize(){
    return sizeStack;
}
template <typename T>
void setSize(int sizeStack){
    sizeStack = sizeStack;
}

template <typename T>
int Stack<T>::size(){
    return sizeStack;
}

template <typename T>
void Stack<T>::push(Node<T>* p){
    if(getList()->insertHead(p)){
        sizeStack += 1;
    }
}

template <typename T>
void Stack<T>::pop(){
    if(getList()->deleteNode(getList()->getHead())){
        sizeStack -= 1;
    }
}

template <typename T>
void Stack<T>::showList(){
    for(Node<T> *tmp = sl->getHead(); tmp != NULL; tmp = tmp->getNext()){
        tmp->showInfo();
    }
}

template <typename T>
Node<T>* Stack<T>::top(){
    return getList()->getHead();
}

#endif