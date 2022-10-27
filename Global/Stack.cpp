#include "Stack.h"

template <typename T>
int Stack<T>::getSize(){
    
}
template <typename T>
void setSize();

template <typename T>
int Stack<T>::size(){
    return sizeStack;
}

template <typename T>
void Stack<T>::push(Node<T>* p){
    if(insertHead(p)){
        sizeStack += 1;
    }
}

template <typename T>
void Stack<T>::pop(){
    if(deleteNode(getHead())){
        sizeStack -= 1;
    }
}

template <typename T>
Node<T>* Stack<T>::top(){
    return getHead();
}