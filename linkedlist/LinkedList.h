/*
Nguyễn Trọng Đăng Khoa
2001215879
12DHTHTD
*/
#include <iostream>
#include <math.h>
typedef int T;


/*
Node cho cả bài 1 và bài 2;
    bài 1 là số nguyên val/1 thì bot là 1;
    bài 2 là phân số val/bot;
*/
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
        if(p == NULL) return;
        if(pHead == NULL){
            pHead = p;
            pTail = p;
            return;
        }
        p->pNext = pHead;
        pHead = p;
    }

    void addTail(Node* p){
        if(p == NULL) return;
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

    //2. b
    void inputFraction(int n){
        int top = 0, bot = 1;
        for(int i = 0; i < n; i++){
            printf("Nhap top va bot: ");
            scanf("%d %d", &top, &bot);
            Node* p;
            addTail(p->create(top, bot));
        }
    }

    void printListFraction(){
        for(Node* tmp = pHead; tmp != NULL; tmp = tmp->pNext){
            std::cout << tmp->val << "/" << tmp->bot << " ";
        }
    }

    //./end 2. b

    //2. c
    int gcd(int a, int b){
        if(b == 0) return a;
        return gcd(b, a % b);
    }
    Node* simplifyFraction(Node* a){
        int UCLN = gcd(a->val, a->bot);
        a->val /= UCLN;
        a->bot /= UCLN;
        return a;
    } 
    void simplifyListFraction(){
        for(Node* tmp = pHead; tmp != NULL; tmp = tmp->pNext){
            tmp = simplifyFraction(tmp);
        }
    }
    //./end 2. c

    //2. d
    Node sumFraction(Node* a, Node* b){
        if(a == NULL || b == NULL) return NULL;
        int top = a->val * b->bot + b->val * a->bot,
            bot = a->bot * b->bot; 
        Node c = *c.create(top, bot);
        return c;
    }
    Node* sumListFraction(){
        if(pHead == NULL) return NULL;
        Node* sum = pHead; 
        for(Node* tmp = pHead->pNext; tmp != NULL; tmp = tmp->pNext){
            sum = &sumFraction(sum, tmp);
        }
        return sum;
    }
    Node multipleFraction(Node* a, Node* b){
        if(a == NULL || b == NULL) return NULL;
        int top = a->val * b->val,
            bot = a->bot * b->bot;
        Node c = *c.create(top, bot);
        return c;
    }
    Node* multipleListFraction(){
        if(pHead == NULL) return NULL;
        Node* multiple = pHead;
        for(Node* tmp = pHead->pNext; tmp != NULL; tmp = tmp->pNext){
            multiple = &multipleFraction(multiple, tmp);
        }

        return multiple;
    }
    //./end 2. d

    //2. e
    bool isFracALargerB(Node* a, Node* b){
        return (a->val / a->bot > b->val / b->bot) ? true : false;
    }
    Node findMaxMinFraction(bool isFindMax = false){
        if(pHead == NULL) return NULL;
        Node result = *pHead;
        for(Node* tmp = pHead->pNext; tmp != NULL; tmp = tmp->pNext){
            bool check = isFracALargerB(&result, tmp);
            if((isFindMax == false && check == true) ||
                (isFindMax == true && check == false)){
                result = *tmp;
            }
        }
        return result;
    }
    //./ end 2. e

    //2. f
    void plusFractionToOne(){
        Node a = *a.create(1, 1);
        for(Node* tmp = pHead; tmp != NULL; tmp = tmp->pNext){
            tmp = &sumFraction(&a, tmp);
        }
    }
    //./ end 2. f

    //2. g
    void printFractionLargeOne(){
        Node a = *a.create(1, 1);
        for(Node* tmp = pHead; tmp != NULL; tmp = tmp->pNext){
            if(isFracALargerB(tmp, &a)){
                std::cout << tmp->val << "/" << tmp->bot << " ";
            }
        }
    }
    //./ end 2. g

    //2. h
    Node* findFraction(Node* p){
        for(Node* tmp = pHead; tmp != NULL; tmp = tmp->pNext){
            if(p->val == tmp->val && p->bot == tmp->bot){
                return tmp;
            }
        }
    }
    //./ end 2. h

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