/*
Nguyễn Trọng Đăng Khoa
2001215879
12DHTHTD
*/
#include <iostream>
#include <math.h>
typedef int T;

template<typename N>
struct Node{
    T val;
    Node* pNext;
    Node() : val(0), pNext(NULL) {}
    Node(T x) : val(x), pNext(NULL) {}
    Node(T x, Node* next) : val(x), pNext(next) {}

    void showNode(){
        std::cout << val;
    }

    Node* create(T x){
        Node* p = new Node(x);
        if(p == NULL) return NULL;
        return p;
    }
};

struct PhanSo{
    T tu;
    T mau;
    PhanSo* pNext;
    PhanSo() : tu(0), mau(1), pNext(NULL){}
    PhanSo(T x, T y) : tu(x), mau(y), pNext(NULL){}
    PhanSo(T x, T y, PhanSo* pNext) : tu(x), mau(y), pNext(NULL) {}

};

class SList{
public:
    Node* pHead;
    Node* pTail;
    SList(): pHead(NULL), pTail(NULL) {}
    SList(Node* p) : pHead(p), pTail(p) {}
    bool isEmpty(){
        return (pHead == NULL) ? true : false;
    }

    /*
        Add topologies
    */

    void addHead(Node* p){
        if(pHead == NULL){
            pHead = p;
            pTail = p;
            return;
        }
        p->pNext = pHead;
        pHead = p;
    }

    void addTail(Node* p){
        if(pHead == NULL){
            pHead = p;
            pTail = p;
            return;
        }
        Node* tmp = pHead;
        while(tmp->pNext != NULL){
            tmp = tmp->pNext;
        }
        tmp->pNext = p;
    }

    void addNodeBeforeValue(Node* q, T y){
        if(pHead->val == y){
            addHead(q);
            return;
        }
        for(Node* tmp = pHead; tmp->pNext != NULL; tmp = tmp->pNext){
            if(tmp->pNext->val == y){
                q->pNext = tmp->pNext;
                tmp->pNext = q;
                return;
            }
        }
    }

    bool isExist(Node* p){
        for(Node* tmp = pHead; tmp != NULL; tmp = tmp->pNext){
            if (p == tmp){
                return true;
            }
        }
        return false;
    }

    void addAfterNode( Node* cur, Node* p){
        if(isExist(cur) == false) return;
        p->pNext = cur->pNext;
        cur->pNext = p;
    }
    //./End Add

    /*
    Delete topologies
    
    */
    void deleteHead(){
        if(pHead == NULL) return;
        if(pHead == pTail){
            delete pHead;
            pHead = pTail = NULL;
            return;
        }
        Node* tmp = pHead;
        pHead = pHead->pNext;
        delete tmp;
    }

    void deleteTail(){
        if(pTail == NULL) return;
        if(pHead == pTail){
            delete pTail;
            pHead = pTail = NULL;
            return;
        }
        for(Node* tmp = pHead; tmp->pNext->pNext != NULL; tmp = tmp->pNext){
            if(tmp->pNext->pNext == NULL){
                pTail = tmp;
                delete tmp->pNext->pNext;
                return;
            }
        }
    }

    void deleteAfterNode(Node* q){
        if(isExist(q) == false) return;
        if(q->pNext->pNext == NULL){
            delete q->pNext->pNext;
            q->pNext = NULL;
            return;
        }
        Node* tmp = q->pNext->pNext;
        delete q->pNext;
        q->pNext = tmp;
    }

    void deleteNode(Node* p){
        if(pHead == p){
            deleteHead();
            return;
        }
        if(pTail == p){
            deleteTail();
            return;
        }
        Node* tmp = pHead;
        for(; tmp->pNext != NULL;  tmp = tmp->pNext){
            if(tmp->pNext == p){
                tmp->pNext = p->pNext;
                delete p;
                return;
            }
        }
    }

    //1. c
    void deleteNodeLargerValue(T x){
        Node* tmp = pHead;
        for(; tmp != NULL; tmp = tmp->pNext){
            if(tmp->val > x){
                deleteNode(tmp);
            }
        }
    }

    // ./ End Delete

    //1. d

    void swap(T& a, T& b){
        T tmp = a;
        a = b;
        b = tmp;
    }

    void sortSList(bool isASC = 0){ // true is ASC, false is DESC
        for(Node* x = pHead; x != NULL; x = x->pNext){
            Node* obj = x;
            for(Node* y = x->pNext; y != NULL; y = y->pNext){
                if((obj->val > y->val && isASC) || (obj->val < y->val && !isASC)){
                    obj = y;
                }
            }
            swap(x->val, obj->val);
        }
    }

    //1. e
    bool isPrime(int val){
        if(val < 2) return false;
        for(int i = 2; i < sqrt(val); i++){
            if(val % i == 0) return false;
        }

        return true;
    }
    int countPrime(){
        int count = 0;
        for(Node* tmp = pHead; tmp != NULL; tmp = tmp->pNext){
            if(isPrime(tmp->val)) ++count;
        }
        return count;
    }

    //1. f
    bool isSquareNumber(int val){
        if(sqrt(val)*sqrt(val) == val) return true;
        return false;
    }

    int countSquareNumber(){
        int count = 0;
        for(Node* tmp = pHead; tmp != NULL; tmp = tmp->pNext){
            if(isSquareNumber(tmp->val)) ++count;
        }
        return count;
    }

    //1. h
    Node* findMinValue(){
        Node* Min = pHead;
        for(Node* tmp = pHead->pNext; tmp != NULL; tmp = tmp->pNext){
            if(tmp->val < Min->val) Min = tmp;
        }
        return Min;
    }

    Node* findMaxValue(){
        Node* Max = pHead;
        for(Node* tmp = pHead->pNext; tmp != NULL; tmp = tmp->pNext){
            if(tmp->val > Max->val) Max = tmp;
        }
        return Max;
    }

    //1. i
    int countALarger2B(){
        int count = 0;
        T cur = pHead->val;
        for(Node* tmp = pHead->pNext; tmp != NULL; tmp = tmp->pNext){
            if(cur / 2 == tmp->val) count++;
        }
        return count;
    }

    //1. j
    void decideOddEven(SList* sl1, SList* sl2){
        for(Node* tmp = pHead; tmp != NULL; tmp = tmp->pNext){
            if(tmp->val % 2 == 0){
                sl1->addTail(tmp);
            }else{
                sl2->addTail(tmp);
            }
        }
    }

    void printSList(){
        for(Node* tmp = pHead; tmp != NULL; tmp = tmp->pNext){
            std::cout << tmp->val << " ";
        }
    }

    void deleteSList(Node* p){
        if(p == NULL){
            delete this;
            return;
        }
        return deleteSList(p->pNext);
        delete p;
    }
};