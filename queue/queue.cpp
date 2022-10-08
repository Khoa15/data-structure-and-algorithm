#include <iostream>
#include "Queue.h"
template<typename Q>
void Queue<Q>::push(Q x){
    Node<Q>* p = new Node<Q>(x);
    if(p == NULL){
        printf("Memory is not enough\n");
        return;
    }
    if(isEmpty() == true){
        pHead = p;
        pTail = p;
        return;
    }
    pTail->pNext = p;
    pTail = p;
}

template<typename Q>
Node<Q>* Queue<Q>::pop(){
    Node<Q>* tmp = pHead;
    pHead = pHead->pNext;
    return tmp;
}

int main(){
    Queue<int> q1;
    q1.push(10);
    q1.push(5);
    q1.push(8);
    q1.push(6);

    std::cout << q1.pop()->info << std::endl << q1.pop()->info;
    return 0;
}