#include "Node.h"

template <typename T>
T Node<T>::getInfo(){
    return Info;
}

template <typename T>
Node<T>* Node<T>::getNext(){
    return pNext;
}

template <typename T>
void Node<T>::setInfo(T Info){
    Info = Info;
}

template <typename T>
void Node<T>::setNext(Node* p){
    pNext = p;
}

