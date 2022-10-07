#include <iostream>

using namespace std;

struct SNode{
    int data;
    SNode* next;
};

struct Stack{
    SNode* top;
};

SNode* createNewNode(int n){
    SNode* p = new SNode;
    if(p == NULL) return NULL;
    p->data = n;
    p->next = NULL;
    return p;
}

void push(Stack *stk, SNode* p){
    if (p == NULL) return;
    if(stk->top == NULL){
        stk->top = p;
        return;
    }
    p->next = stk->top;
    stk->top = p;
}

SNode* top(Stack* stk){
    return stk->top;
}

SNode* pop(Stack* stk){
    SNode* p = stk->top;
    stk->top = p->next;
    return p;
}
