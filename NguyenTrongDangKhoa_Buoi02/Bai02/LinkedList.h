#pragma once
#ifndef _LINKED_LIST_H_
#define _LINKED_LIST_H_
#include <iostream>
struct Music{
    char name[51];
    char author[41];
    char singer[41];
    unsigned int time;
};
typedef Music Data;

class Node {
public:
    Data info;
    Node* pNext;
    Node() : pNext(NULL) {}
    Node(Data x) : info(x), pNext(NULL) {}
    Node(Data x, Node* next) : info(x), pNext(next) {}
    void showNode(){
        printf(
            "Bai hat: %s\n"
            "Tac gia: %s\n"
            "Ca sy: %s\n"
            "Thoi luong: %d\n"
            "===========\n",
            info.name,
            info.author,
            info.singer,
            info.time
            );
    }
};

class SList {
public:
    Node* pHead;
    Node* pTail;
    SList() : pHead(NULL), pTail(NULL) {}
    SList(Node* p) : pHead(p), pTail(p) {}
    ~SList() { delete[] pHead; delete pTail; }

    void addTail(Data x);
    void printList();
    //1
    void getFile(char* _filename);
    void deleteNode(Node* p);
    void deleteSong(char* name);
    unsigned int sumTimeList();
    void addNode(Data x);
    bool isExists(char* name);
    Node* findNode(char* name);
    void sortByName();
    void sortBySinger();
    void setNodeToHead(Node* p);
};

#endif