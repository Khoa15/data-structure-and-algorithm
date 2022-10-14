#pragma once
#ifndef _NODE_
#define _NODE_
#include <iostream>
#include "Helper.h"
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
            printf("Memory is not enough");
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
        return (float)top / bot;
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
        printf("%d/%d ", top, bot);
    }
};
#endif