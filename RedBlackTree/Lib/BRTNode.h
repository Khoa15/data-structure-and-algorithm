#pragma once
#ifndef _BRT_NODE_H_
#define _BRT_NODE_H_
#include <iostream>
using namespace std;
enum ECOLOR {RED, BLACK};

template <class T>
class BRTNode
{
private:
    T Info;
    ECOLOR Color; 
    BRTNode *pLeft;
    BRTNode *pRight;
    BRTNode *pParent;
public:
    BRTNode() : Color(RED), pLeft(NULL), pRight(NULL), pParent(NULL) {};
    BRTNode(T x) : Info(x), Color(RED), pLeft(NULL), pRight(NULL), pParent(NULL) {};
    
    void show();
    void swapColors();
    void swapInfos();

};
#endif