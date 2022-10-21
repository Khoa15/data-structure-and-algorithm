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

    short int type(){
        if(diemKQ >= 8.5){
            // std::cout << "GIOI";
            return 3;
        }else if(diemKQ >= 7 && diemKQ < 8.5){
            // std::cout << "KHA";
            return 2;
        }else if(diemKQ >= 5){
            // std::cout << "TRUNG BINH";
            return 1;
        }
        return 0;
    }
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
    void showNode();
    Node* createNode(Data Info);
};

class SList {
public:
    Node* pHead;
    Node* pTail;
    SList() : pHead(NULL), pTail(NULL) {}
    SList(Node* p) : pHead(p), pTail(p) {}
    ~SList() { delete[] pHead; delete pTail; }

    void getInputNode(Data* info);
    void addTail(Node* x);
    void printList();
    void addNodeXAfterNodeY(Node* x, Node* y);
    //1
    void getFile(char* _filename);
    void deleteNode(Node* p);
    void addNode(Node* x);
    void setNodeToHead(Node* p);

    Node* findStudentById(Data* Info);//a, b
    Node* findStudentByName(Data* Info);//a, b
    void sortBy(char *type);//c, d
    void addStudent(Node* x);
    void deleteStudent(Node* p);
    SList* createNewListDESCByScore();
    void printStudents();
    Node* maxScoreStudent();
    Node* minScoreStudent();
    Node* minScoreGoodStudent();
    Node* findStudentAroundScore(float x);//m
    void deleteAllStudentsByName(Data* info);
};

#endif