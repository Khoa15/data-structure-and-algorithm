/*
Nguyễn Trọng Đăng Khoa
2001215879
12DHTHTD
*/
#include <iostream>
#include <math.h>
typedef int T;
int gcd(int a, int b){
    if(b == 0) return a;
    return gcd(b, a % b);
}
struct Node{
    T val;
    T bot;
    Node* pNext;
    Node() : val(0), bot(1), pNext(NULL) {}
    Node(T x) : val(x), bot(1), pNext(NULL) {}
    Node(T x, T y) : val(x), bot(y), pNext(NULL) {}
    Node(T x, Node* next) : val(x), bot(1), pNext(next) {}
    Node(T x, T y, Node* next) : val(x), bot(y), pNext(next) {}

    void showNode(){
        std::cout << val;
    }

    Node* create(T x, T y = 1){
        Node* p = new Node(x, y);
        if(p == NULL) return NULL;
        return p;
    }

    void plus(Node* b){
        Node kq;
        kq.val = val * b->bot + bot * b->val;
        kq.bot = bot * b->bot;
    }

    void simplify(){
        int ucln = gcd(val, bot);
        val /= ucln;
        bot /= ucln;
    }
};

class SList{
    Node* pHead;
    Node* pTail;
public:
    SList(): pHead(NULL), pTail(NULL) {}
    SList(Node* p) : pHead(p), pTail(p) {}
    ~SList() {delete []pHead;}

    bool isEmpty(){return pHead == NULL;}
    void addHead(Node* p);
    void addTail(Node* p);
    void addNodeBeforeValue(Node* q, T y);
    bool isExist(Node* p);
    void addAfterNode( Node* cur, Node* p);
    void deleteHead();
    void deleteTail();
    void deleteAfterNode(Node* q);
    void deleteNode(Node* p);
    void deleteNodeLargerValue(T x);
    void deleteEvenList();
    void swap(T& a, T& b);
    void sortSList(bool isASC = 0);
    bool isPrime(int val);
    int countPrime();
    bool isSquareNumber(int val);
    int countSquareNumber();
    Node* findMinValue();
    Node* findMaxValue();
    int countALarger2B();
    void decideOddEven(SList* sl1, SList* sl2);
    void inputFraction(int n);
    void printListFraction();
    Node* simplifyFraction(Node* a);
    void simplifyListFraction();
    Node sumListFraction();
    Node* multipleFraction(Node* a, Node* b);
    Node* multipleListFraction();
    bool isFracALargerB(Node* a, Node* b);
    Node* findMaxMinFraction(bool isFindMax = false);
    Node plusFractionToOne();
    void printFractionLargeOne();
    Node* findFraction(Node* p);
    void printSList();
    void deleteSList(Node* p);
};