#ifndef _BRTREE_H_
#define _BRTREE_H_
#include "BRTNode.h"


template <class T>
class BRTree
{
private:
    BRTNode *Root;
public:
    BRTree() : Root(NULL) {};

    void setRoot(BRTNode *p);
    void getRoot(BRTNode *p);

    bool insertNode(BRTNode *node);

    void levelOrder(BRTNode *root);
    
};


#endif