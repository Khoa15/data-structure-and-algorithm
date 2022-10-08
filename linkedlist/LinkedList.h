/*
Nguyễn Trọng Đăng Khoa
2001215879
12DHTHTD
*/
#include <iostream>
#include <math.h>
typedef int Data;

class Node {
public:
    Data top;
    Data bot;
    Node* pNext;
    Node() : top(0), bot(1), pNext(NULL) {}
    Node(Data x) : top(x), bot(1), pNext(NULL) {}
    Node(Data x, Data y) : top(x), bot(y), pNext(NULL) {}
    Node(Data x, Node* next) : top(x), bot(1), pNext(next) {}
    Node(Data x, Data y, Node* next) : top(x), bot(y), pNext(next) {}

    Node* create(Data x) {
        Node* p = new Node(x);
        if (p == NULL) {
            std::cout << "Memory is not enough";
        }
        return p;
    }

    Node plus(Node* b) {
        Node result;
        result.top = top * b->bot + bot * b->top;
        result.bot = bot * b->bot;
        return result;
    }

    Node multiple(Node* b) {
        Node result;
        result.top = top * b->top;
        result.bot = bot * b->bot;
        return result;
    }

    float divide() {
        return top / bot;
    }

    void erase() {
        delete this;
    }

    void simplify() {
        int ucln = gcd(top, bot);
        top /= ucln;
        bot /= ucln;
    }

    void print() {
        std::cout << top << "/" << bot << " ";
    }
};

class SList {
    Node* pHead;
    Node* pTail;
public:
    SList() : pHead(NULL), pTail(NULL) {}
    SList(Node* p) : pHead(p), pTail(p) {}
    ~SList() { delete[] pHead; delete pTail; }
    
    bool isEmpty() { return pHead == NULL; }
    Node* getHead() { return pHead; }
    Node* getTail() { return pTail; }
    void setHead(Node* x) { pHead = x; }
    void setTail(Node* x) { pTail = x; }

    void addHead(Node* p);
    void addTail(Node* p);
    void addXBeforeY(Data x, Data y);
    void deleteNode(Node* p);
    void deleteNodeLargerX(Data x);
    void deleteEvenVal();
    void sort(bool isASC = false);
    int countPrimeNumber();
    int totalSquareNumber();
    Node* findMinVal();
    Node* findMaxVal();
    int countXLarger2Y();
    void divideList(SList* sl1, SList* sl2);

    void printSList(bool isFraction = false) {
        for (Node* p = pHead; p != NULL; p = p->pNext) {
            if (isFraction == false)
                std::cout << p->top << " ";
            else
                std::cout << p->top << "/" << p->bot << " ";
        }
        std::cout << std::endl;
    }

    //2
    void getListInput(int n);
    void simplifyListFraction();
    Node sumListFraction();
    Node multipleListFraction();
    Node* findMinFraction();
    Node* findMaxFraction();
    Node* printListFractionLargeY(Data y = 1);
    Node* findNode(Node x);
};