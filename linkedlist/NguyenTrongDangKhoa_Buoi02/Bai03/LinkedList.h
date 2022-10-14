#pragma once
#ifndef _LINKED_LIST_H_
#define _LINKED_LIST_H_
#include <iostream>
struct Student{
    char maSV[11];
    char hoDem[41];
    char tenSV[41];
    short int namSinh;
    float diemKQ;
};

struct Subject{
    char id[11];
    char name[41];
    short int tinChi;
    float DTL, DCK, DMH;
};

typedef Student Data;

class Node {
public:
    Data info;
    Node* pNext;
    Node() : pNext(NULL) {}
    Node(Data x) : info(x), pNext(NULL) {}
    Node(Data x, Node* next) : info(x), pNext(next) {}
    void showNode(){
        printf(
            "%-5s %-5s %-5s %-5d %f\n",
            info.maSV,
            info.hoDem,
            info.tenSV,
            info.namSinh,
            info.diemKQ
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

    Node* findStudent(char *Id);//a, b
    void sortBy();//c, d
    void addStudent();
    void deleteStudent(Node* p);
    void createNewListDESCByScore();
    void printStudents();
    void maxScore();
    void minScore();
};

#endif