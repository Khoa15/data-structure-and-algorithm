#pragma once
#ifndef _LINKED_LIST_H_
#define _LINKED_LIST_H_
#include <iostream>
typedef int Data;
class Node {
public:
    Data val;
    Node* pNext;
    Node() : val(0), pNext(NULL) {}
    Node(Data x) : val(x), pNext(NULL) {}
    Node(Data x, Node* next) : val(x), pNext(next) {}
};

class SList {
public:
    Node* pHead;
    Node* pTail;
    SList() : pHead(NULL), pTail(NULL) {}
    SList(Node* p) : pHead(p), pTail(p) {}
    ~SList() { delete[] pHead; delete pTail; }

    void addTail(int x);
    void printList(){
        for(Node* tmp = pHead; tmp != NULL; tmp = tmp->pNext) printf("%d ", tmp->val);
    }
    //1
    void getFile(char* _filename);
    void deleteNode(Node* p);
    void deleteHead();
    void deleteNodeAfterX(int x);
    void deleteNodeValEqualX(int x);
    void deleteList();
    void deleteEvenNode();
};

#endif