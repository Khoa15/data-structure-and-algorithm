#pragma once
#ifndef _BTree_H_
#define _BTree_H_
#include "TNode.h"
#include "Number.h"
#include "LinkedList.h"
#include <queue>
#include <stack>
#include <stdlib.h>

template <class T>
class BTree : public TNode<T>
{
private:
    TNode<T> *Root;
    int height;
public:
    BTree() : Root(NULL), height(0) {}
    BTree(TNode<T> *root) : Root(root), height(0) {}
    ~(){
        deleteTree();
    }
    TNode<T> *getRoot();

    void init(TNode<T> *root = Root);
    void createBTreeFromKeyboard();
    bool createRandomBTree();

    bool isEmpty();
    bool isBinarySearchTree(TNode<T> *root = Root);
    bool insertTNode(TNode<T> *root = Root);
    bool deleteTNode(T x, TNode<T> *root = Root);
    bool createBSTreeNumberFromFile(char filename[]);
    
    int countTNode(TNode<T> *root = Root);
    int countTNodeIsLeaf(TNode<T> *root = Root);
    int countTnodeHaveTwoChild(TNode<T> *root = Root);
    int sumTNode(TNode<T> *root = Root);
    int getHeight(TNode<T> *root = Root);
    int countTNodeOfLevelK(int k, TNode<T> *root = Root);

    void showTNodeIsLeafOfLevelK(int k, TNode<T> *root = Root);

    void rotateRight();
    void rotateLeft();

    void traverseNLR(TNode<T> *root = Root);
    void traverseLNR(TNode<T> *root = Root);
    void traverseLRN(TNode<T> *root = Root);
    void traverseNRL(TNode<T> *root = Root);
    void traverseRNL(TNode<T> *root = Root);
    void traverseRLN(TNode<T> *root = Root);

    void traverseBreadthNLR(TNode<T> *root = Root);
    void traverseDepthNLR(TNode<T> *root = Root);

    TNode<T> *findRootOfTwoTNode(TNode<T> *TNode1, TNode<T> *TNode2);
    TNode<T> *findTNode(T x, TNode<T> *root = Root);
    TNode<T> *findTNodeMinDistanceX(T x);
    TNode<T> *findTNodeMaxDistanceX(T x);

    // find root of tnode
    TNode<T> *findRootTNode(T x);
    // find root of tnode min at right of root
    TNode<T> *findRootTNodeMinRight(TNode<T> *root = Root);
    // find root of tnode max at left of root
    TNode<T> *findRootTNodeMaxLeft(TNode<T> *root = Root);

    bool deleteTree(TNode<T> *root = Root);
};

template <class T>
TNode<T> *BTree<T>::getRoot(){
    return Root;
}

template <class T>
void BTree<T>::init(TNode<T> *root){
    Root = root;
}

template <class T>
void BTree<T>::createBTreeFromKeyboard(){
    int n = 0;
    do{
        cout << "Nhập n số phần tử của cây(n > 0): ";
        cin >> n;
    }while(n <= 0);

    int x = 0;
    for(int i = 0; i < n; i++){
        cin >> x;
        if(this->createTNode(createNode(x)) == NULL){
            return;
        }
    }
}

template <class T>
bool BTree<T>::createRandomBTree(){
    int n = random;
    for(int i = 0; i < n; i++){
        if(this->createTNode(createNode(random(1, 99))) == NULL){
            this->deleteTree();
            return false;
        }
    }
    return true;
}

template <class T>
bool BTree<T>::isEmpty(){
    return (Root == NULL);
}

template <class T>
bool BTree<T>::isBinarySearchTree(TNode<T> *root){
    if(getRoot() == NULL) return false;
    if(root == NULL) return true;
    if(
        root->getPrev() != NULL && root->getPrev()->getInfo() > root->getInfo()
        ||
        root->getNext() != NULL && root->getNext()->getInfo() < root->getInfo()
    ) return false;
    isBinarySearchTree(root->getPrev());
    isBinarySearchTree(root->getNext());
}


template <class T>
bool BTree<T>::insertTNode(TNode<T> *root){
    if(root == NULL) return false;
    TNode<T> *tmp = root;
    while(1){
        if(tmp == NULL){
            tmp = root;
            return true;
        }
        if(tmp->getInfo() == root->getInfo()){
            return false;
        }
        if(tmp->getInfo() < root->getInfo()){
            tmp = tmp->getNext();
        }else{
            tmp = tmp->getPrev();
        }
    }
}


// Frist: find root of tnode need to deleted then delete
template <class T>
bool BTree<T>::deleteTNode(T x, TNode<T> *root){
    if(root == NULL) return false;
    if(root -> getNext() -> getInfo() != x && root -> getPrev() -> getInfo() != x){
        // if user forgot find root is true then: 
        root = findRootTNode(x);
    }
    TNode<T> *tmp = NULL;
    if(root->getPrev()->getInfo() == x){
        tmp = root->getPrev();
    }
    tmp = root->getNext();
    if(tmp -> getNext() == NULL){
        root->setNext(tmp->getPrev());
        return true;
    }
    TNode<T> *tmp2 = findRootTNodeMinRight();
    tmp->setInfo(tmp2->getPrev()->getInfo());
    tmp2->setPrev(tmp2->getPrev()->getNext());
    return true;
}

template <class T>
bool BTree<T>::createBSTreeNumberFromFile(char filename[]){
    FILE *f;
    f = open(filename, "rt");
    if(f == NULL) return false;
    int n;
    cin >> n;
    T x;
    for(int i = 0; i < n; i++){
        cin >> x;
        this->createTNode(createNode(x));
    }
    fclose(f);
    return true;
}

template <class T>
int BTree<T>::countTNode(TNode<T> *root){
    if(root == NULL) return 0;
    int nl = countTNode(root->getPrev());
    int nr = countTNode(root->getNext());
    return 1 + nl + nr;
}

template <class T>
int BTree<T>::countTNodeIsLeaf(TNode<T> *root){
    if(root == NULL) return 0;
    int countLeafLeft = countTNodeIsLeaf(root->getPrev());
    int countLeafRight = countTNodeIsLeaf(root->getNext());
    return countLeafLeft + countLeafRight;
}

template <class T>
int BTree<T>::countTnodeHaveTwoChild(TNode<T> *root){
    if(root == NULL || root->getNext() == NULL || root->getPrev() == NULL) return 0;
    int countNodeLeft = countTnodeHaveTwoChild(root->getPrev());
    int countNodeRight = countTnodeHaveTwoChild(root->getNext());
    return countNodeLeft + countNodeRight + 1;
}

template <class T>
int BTree<T>::sumTNode(TNode<T> *root){
    if(root == NULL) return 0;
    int sumLeft = sumTNode(root->getPrev()),
        sumRight = sumTNode(root->getNext());
    return sumLeft + sumRight + root->getInfo();
}

template <class T>
int BTree<T>::getHeight(TNode<T> *root){
    if(root == NULL) return 0;
    int heightLeft = getHeight(root->getPrev()),
        heightRight = getHeight(root->getNext());
    return (heightLeft > heightRight) ? heightLeft + 1 : heightRight + 1;
}

template <class T>
int countTNodeOfLevelK(int k, TNode<T> *root){
    if(root == NULL) return 0;
    if(k == 0) return 1;
    k -= 1;
    int cnl = countTNodeOfLevelK(k, root->getPrev()),
        cnr = countTNodeOfLevelK(k, root->getNext());
    return cnl + cnr;
}

template <class T>
void BTree<T>::showTNodeIsLeafOfLevelK(int k, TNode<T> *root){
    if(root == NULL) return;
    if(k == 0 && root->getPrev() == NULL && root->getNext() == NULL) root->showInfo();
    k -= 1;
    showTNodeIsLeafOfLevelK(k, root->getPrev());
    showTNodeIsLeafOfLevelK(k, root->getNext());
}


template <class T>
void BTree<T>::traverseNLR(TNode<T> *root){
    if(root == NULL) return;
    root->showInfo();
    traverseNLR(root->getNext());
    traverseNLR(root->getPrev());
}
template <class T>
void BTree<T>::traverseLNR(TNode<T> *root){
    if(root == NULL) return;
    traverseLRN(root->getPrev());
    root->showInfo();
    traverseLRN(root->getNext()());
}

template <class T>
void BTree<T>::traverseLRN(TNode<T> *root){
    if(root == NULL) return;
    traverseLRN(root->getPrev());
    traverseLRN(root->getNext());
    root->showInfo();
}

template <class T>
void BTree<T>::traverseNRL(TNode<T> *root){
    if(root == NULL) return;
    root->showInfo();
    traverseNRL(root->getNext());
    traverseNRL(root->getPrev());
}

template <class T>
void BTree<T>::traverseRNL(TNode<T> *root){
    if(root == NULL) return;
    traverseRNL(root->getNext());
    root->showInfo();
    traverseRNL(root->getPrev());
}

template <class T>
void BTree<T>::traverseRLN(TNode<T> *root){
    if(root == NULL) return;
    traverseRLN(root->getNext());
    traverseRLN(root->getPrev());
    root->showInfo();
}

template <class T>
void BTree<T>::traverseBreadthNLR(TNode<T> *root){
    if(root == NULL) return;

    queue<TNode<T> *> q;
    q.push(root);

    while(q.isEmpty() == false){
        TNode<T> *p = q.front();
        q.pop();
        p->showInfo();

        if(p->getPrev() != NULL){
            q.push(p->getPrev());
        }else{
            q.push(p->getNext());
        }
    }
}

template <class T>
void BTree<T>::traverseDepthNLR(TNode<T> *root){
    if(root == NULL) return;
    stack<TNode<T> *> stk;
    stk.push(root);
    while(stk.isEmpty() == false){
        TNode<T> *tmp = stk.top();
        stk.pop();
        tmp->showInfo();

        if(tmp->getNext() != NULL) stk.push(p->getNext());
        if(tmp->getPrev() != NULL) stk.push(p->getPrev());
    }
}

template <class T>
TNode<T> *BTree<T>::findRootOfTwoTNode(TNode<T> *TNode1, TNode<T> *TNode2){
    if(TNode1 == NULL || TNode2 == NULL) return NULL;
    // findTNode()
    TNode<T>    *tmp = getRoot(),
                *tmp2 = getRoot();
    while(tmp != NULL){
        TNode<T> *Left = findTNode(TNode1->getInfo(), tmp->getPrev()),
                *Right = findTNode(TNode2->getInfo(), tmp->getNext());
        if(Left == Right) return tmp;
    }

    return tmp;
}


template <class T>
TNode<T> *BTree<T>::findTNode(T x, TNode<T> *root){
    if(root == NULL) return NULL;
    if(root->getInfo() == x) return root;
    TNode<T> *tmp = root;
    while(tmp != NULL){
        if(tmp->getInfo() == x) return tmp;
        if(tmp->getInfo() < x) tmp = tmp->getNext();
        else tmp = tmp->getPrev();
    }
    return tmp;
}

template <class T>
TNode<T> *BTree<T>::findTNodeMinDistanceX(T x){
    if(getRoot() == NULL) return NULL;
    TNode<T>*result = getRoot(),
            *tmp = getRoot();
    while(tmp != NULL){
        if(tmp->getInfo() == x) return tmp;
        if(abs(result->getInfo() - x) > abs(tmp->getInfo() - x)){
            result = tmp;
        }

        if(x > tmp->getInfo()){
            // RIGHT
            tmp = tmp->getNext();
        }else{
            tmp = tmp->getPrev();
        }
    }
    return result;
}

template <class T>
TNode<T> *BTree<T>::findTNodeMaxDistanceX(T x){
    if(getRoot() == NULL) return NULL;
    TNode<T>    *TNodeLeft  = getRoot(),
                *TNodeRight = getRoot();
    while(TNodeLeft->getPrev() != NULL) TNodeLeft = TNodeLeft->getPrev();
    while(TNodeRight->getPrev() != NULL) TNodeRight = TNodeRight->getNext();
    int disLeft = abs(x - TNodeLeft->getInfo()),
        disRight = abs(x - TNodeRight->getInfo());
    return (disLeft > disRight) ? TNodeLeft : TNodeRight;
}

template <class T>
TNode<T> *BTree<T>::findRootTNode(T x){
    if(getRoot() == NULL) return NULL;
    if(getRoot()->getInfo() == x) return NULL;
    TNode<T> *tmp = getRoot();
    while(tmp != NULL){
        if(tmp->getInfo() > x){
            // Left
            if(tmp->getPrev()->getInfo() == x) return tmp;
            tmp = tmp->getPrev();
        }else{
            // Right
            if(tmp->getNext()->getInfo() == x) return tmp;
            tmp = tmp->getNext();
        }
    }
    return tmp;
}

template <class T>
TNode<T> *BTree<T>::findRootTNodeMinRight(TNode<T> *root){
    if(root == NULL) return NULL;
    TNode<T> *tmp = root->getNext();
    if(tmp == NULL) return NULL;
    while(tmp->getPrev() != NULL){
        tmp = tmp->getPrev();
    }
    return tmp;
}

template <class T>
TNode<T> *BTree<T>::findRootTNodeMaxLeft(TNode<T> *root){
    if(root == NULL) return NULL;
    TNode<T> *tmp = root->getPrev();
    if(tmp == NULL) return NULL;
    while(tmp->getNext() != NULL){
        tmp = tmp->getNext();
    }
    return tmp;
}

template <class T>
bool deleteTree(TNode<T> *root){
    if(root == NULL) return false;
    deleteTree(root->getPrev());
    deleteTree(root->getNext());

    delete root;
}

#endif