#include <iostream>

struct Node{
    int top;
    int bot;
    Node* pNexint;

    Node() : top(0), bot(1), pNexint(NULL) {}
    Node(int val) : top(val), bot(1), pNexint(NULL) {}
    Node(int val, int bot) : top(val), bot(bot), pNexint(NULL) {}
    Node(int val, Node* nexint) : top(val), pNexint(nexint) {}
    Node(int val, int bot, Node* nexint) : top(val), bot(bot), pNexint(nexint) {}

    void plus(int a){
        top += a;
    }

    void plus2(int a){
        top += a;

    }
};

class SList{
    Node* pHead;
    Node* pTail;
public:
    SList() : pHead(NULL), pTail(NULL) {}
};


int main(){
    Node* p = new Node(10);
    p->plus(10);
    std::cout << p->top;

    delete p;
    return 0;
}