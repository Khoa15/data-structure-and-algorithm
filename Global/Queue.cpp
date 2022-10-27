#include "Queue.h"

template <typename T>
void Queue<T>::push(Node<T>* p){
    insertTail(p);
}