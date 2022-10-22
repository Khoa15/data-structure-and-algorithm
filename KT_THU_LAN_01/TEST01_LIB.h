#pragma once
#ifndef _TEST_1_H
#define _TEST_1_H
#include <iostream>
#include <string>
using namespace std;
struct Book{
    char Id[11];
    char name[31];
    int totalPages;
    float price;
    int year;

    void getData();
    void showData();
};
typedef Book Data;
class NBook{
private:
    Data Info;
    NBook* pNext;
public:
    NBook() : pNext(NULL) {}
    NBook* getNext(){return pNext;}
    Data getInfo(){return Info;}
    void setInfo(Data x){Info = x;}

    void setNext(NBook *book){pNext = book;}
};

class ListBook{
private:
    NBook* pHead;
public:
    ListBook() : pHead(NULL) {}
    NBook* getHead();
    void getFile(string file);
    void setHead(NBook* book){pHead = book;}
    void addHead(NBook* book);
    int countBookPagesLargerXyearIsY(int x = 500, int y = 2018);
    void deleteBook(NBook* book);
    void findBookPriceLargerX(int x);
    void addBookBeforeBookHavePriceSmallerX(NBook* book, int x);
    void deleteAllBooksPriceLargeX(int x = 100000);
    void showList();
    NBook* createNode(Data Info);
};

struct Node{
    char val[2];
    Node* pNext;
};
struct Stack{
    Node* pHead;

    Node pop();
    Node* top();
    void push(Node* p);
};

#endif