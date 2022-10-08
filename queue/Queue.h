#include <iostream>
typedef int Data;
template<typename N>
class Node{
public:
    N info;
    Node* pNext;
    Node() : info(0), pNext(NULL) {}
    Node(N info) : info(info), pNext(NULL) {}
    Node(N info, Node* next) : info(info), pNext(next) {}
    
};

template<typename Q>
class Queue{
public:
    Node<Q>* pHead;
    Node<Q>* pTail;
    Queue(): pHead(NULL), pTail(NULL) {}
    ~Queue(){
        delete[] pHead;
    }

    bool isEmpty(){return pHead==NULL;}
    void push(Q x);
    Node<Q>* pop();
    void front();
    void back();
};