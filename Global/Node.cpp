#include "Node.h"

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
void Node<T>::setInfo(T Info){
    Info = Info;
}

template <typename T>
void Node<T>::setNext(Node* p){
    pNext = p;
}

