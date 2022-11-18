#pragma once
#ifndef _BTree_H_
#define _BTree_H_
#include <queue>
#include <stack>
#include "Node.h"
#include "IntNumber.h"
#include <stdlib.h>

template <class T>
class BTree : public Node<T>
{
private:
    Node<T> *Root;
    int height;
public:
    BTree() : Root(NULL), height(0) {}
    BTree(Node<T> *root) : Root(root), height(0) {}
    ~BTree(){
        deleteTree(this->getRoot());
    }
    Node<T> *getRoot();
    bool setRoot(Node<T> *root);

    void init(Node<T> *root);
    bool createBTreeFromKeyboard();
    bool createRandomBTree();

    bool isEmpty();
    bool insertTNode(Node<T> *node);
    bool deleteTNode(T x, Node<T> *root);
    bool createBSTreeNumberFromFile(char filename[]);

    bool isBTree(Node<T> *root);
    bool isAVL(Node<T> *root);

    int countTNode(Node<T> *root);
    int countTNodeIsLeaf(Node<T> *root);
    int countTnodeHaveTwoChild(Node<T> *root);
    int sumTNode(Node<T> *root);
    int getHeight(Node<T> *root);
    int countTNodeOfLevelK(int k, Node<T> *root);

    void showTNodeIsLeafOfLevelK(int k, Node<T> *root);
    void showTNodeAtLevelK(int k, Node<T> *root);
    void rotateRight();
    void rotateLeft();

    void traverseNLR(Node<T> *root);
    void traverseLNR(Node<T> *root);
    void traverseLRN(Node<T> *root);
    void traverseNRL(Node<T> *root);
    void traverseRNL(Node<T> *root);
    void traverseRLN(Node<T> *root);

    void traverseBreadthNLR(Node<T> *root);
    void traverseDepthNLR(Node<T> *root);


    Node<T> *findTNode(T x);
    Node<T> *findTNodeMinDistanceX(T x);
    Node<T> *findTNodeMaxDistanceX(T x);

    // find root of tnode
    Node<T> *findRootTNode(T x);
    // find root of tnode min at right of root
    Node<T> *findRootTNodeMinRight(Node<T> *root);
    // find root of tnode max at left of root
    Node<T> *findRootTNodeMaxLeft(Node<T> *root);

    bool deleteTree(Node<T> *root);
};

template <class T>
Node<T> *BTree<T>::getRoot(){
    return Root;
}

template <class T>
bool BTree<T>::setRoot(Node<T> *root){
    Root = root;
    return true;
}

template <class T>
void BTree<T>::init(Node<T> *root){
    Root = root;
}

template <class T>
bool BTree<T>::createBTreeFromKeyboard(){
    int n = 0;
    do{
        cout << "Enter n elements of tree with n larger than zero: ";
        cin >> n;
    }while(n <= 0);
    cout << n << " elements of tree";
    int x = 0;
    for(int i = 0; i < n; i++){
        cout << "Enter a number: ";
        cin >> x;
        if(this->insertTNode(createNode(x)) == false){
            this->deleteTree(this->getRoot());
            return false;
        }
    }
    return true;
}

template <class T>
bool BTree<T>::createRandomBTree(){
    srand(time(NULL));
    int n = random(5, 20);
    bool flag = false;
    for(int i = 0; i < n; i++){
        if(this->insertTNode(createNode(random(1, 99))) == false){
            if(flag == true){
                this->deleteTree(this->getRoot());
                return false;
            }
            flag = true;
        }
    }
    return true;
}

template <class T>
bool BTree<T>::isEmpty(){
    return (Root == NULL);
}

template <class T>
bool BTree<T>::insertTNode(Node<T> *node){
    if(node == NULL) return false;
    Node<T> *tmp = this->getRoot();
    if(tmp == NULL){
        this->setRoot(node);
        return true;
    }
    while(1){
        if(tmp->getInfo() == node->getInfo()){
            return false;
        }
        if(tmp->getInfo() < node->getInfo()){
            if(tmp->getNext() == NULL){
                tmp->setNext(node);
                return true;
            }
            tmp = tmp->getNext();
        }else{
            if(tmp->getPrev() == NULL){
                tmp->setPrev(node);
                return true;
            }
            tmp = tmp->getPrev();
        }
    }
}


// Frist: find root of tnode need to deleted then delete
template <class T>
bool BTree<T>::deleteTNode(T x, Node<T> *root){
    if(root == NULL) return false;
    if(root -> getNext() -> getInfo() != x && root -> getPrev() -> getInfo() != x){
        // if user forgot find root is true then: 
        root = findRootTNode(x);
    }
    Node<T> *tmp = NULL;
    if(root->getPrev()->getInfo() == x){
        tmp = root->getPrev();
    }
    tmp = root->getNext();
    if(tmp -> getNext() == NULL){
        root->setNext(tmp->getPrev());
        return true;
    }
    Node<T> *tmp2 = findRootTNodeMinRight(this->getRoot());
    tmp->setInfo(tmp2->getPrev()->getInfo());
    tmp2->setPrev(tmp2->getPrev()->getNext());
    return true;
}

template <class T>
bool BTree<T>::createBSTreeNumberFromFile(char filename[]){
    FILE *f;
    f = fopen(filename, "rt");
    if(f == NULL) return false;
    int n;
    cin >> n;
    T x;
    for(int i = 0; i < n; i++){
        cin >> x;
        if(this->insertTNode(createNode(x)) == false){
            return false;
        }
    }
    fclose(f);
    return true;
}

template <class T>
bool isBTree(Node<T> *root){
    if(root == NULL) return true;
    if(root->getNext() != NULL){
        if(root->getInfo() > root->getNext()->getInfo()) return false;
    }
    if(root->getPrev() != NULL){
        if(root->getInfo() < root->getPrev()->getInfo()) return false;
    }
    bool 
        l = isBTree(root->getNext()),
        r = isBTree(root->getPrev());
    return (l || r);
}

template <class T>
bool BTree<T>::isAVL(Node<T> *root){
    if(root == NULL ) return true;
    int balance = height(root->getNext()) - height(root->getPrev());

    return (balance == 0);
}

template <class T>
int BTree<T>::countTNode(Node<T> *root){
    if(root == NULL) return 0;
    int nl = countTNode(root->getPrev());
    int nr = countTNode(root->getNext());
    return 1 + nl + nr;
}

template <class T>
int BTree<T>::countTNodeIsLeaf(Node<T> *root){
    if(root == NULL) return 0;
    int countLeafLeft = countTNodeIsLeaf(root->getPrev());
    int countLeafRight = countTNodeIsLeaf(root->getNext());
    return countLeafLeft + countLeafRight;
}

template <class T>
int BTree<T>::countTnodeHaveTwoChild(Node<T> *root){
    if(root == NULL || root->getNext() == NULL || root->getPrev() == NULL) return 0;
    int countNodeLeft = countTnodeHaveTwoChild(root->getPrev());
    int countNodeRight = countTnodeHaveTwoChild(root->getNext());
    return countNodeLeft + countNodeRight + 1;
}

template <class T>
int BTree<T>::sumTNode(Node<T> *root){
    if(root == NULL) return 0;
    int sumLeft = sumTNode(root->getPrev()),
        sumRight = sumTNode(root->getNext());
    return sumLeft + sumRight + root->getInfo();
}

template <class T>
int BTree<T>::getHeight(Node<T> *root){
    if(root == NULL) return 0;
    int heightLeft = getHeight(root->getPrev()),
        heightRight = getHeight(root->getNext());
    return (heightLeft > heightRight) ? heightLeft + 1 : heightRight + 1;
}

template <class T>
int BTree<T>::countTNodeOfLevelK(int k, Node<T> *root){
    if(root == NULL) return 0;
    if(k == 0) return 1;
    k -= 1;
    int cnl = countTNodeOfLevelK(k, root->getPrev()),
        cnr = countTNodeOfLevelK(k, root->getNext());
    return cnl + cnr;
}

template <class T>
void BTree<T>::showTNodeIsLeafOfLevelK(int k, Node<T> *root){
    if(root == NULL) return;
    if(k == 0 && root->getPrev() == NULL && root->getNext() == NULL) root->showInfo();
    k -= 1;
    showTNodeIsLeafOfLevelK(k, root->getPrev());
    showTNodeIsLeafOfLevelK(k, root->getNext());
}

template <class T>
void BTree<T>::showTNodeAtLevelK(int k, Node<T> *root){
    if(root == NULL || k < 0) return;
    k-=1;
    root->showInfo();
    showTNodeAtLevelK(k, root->getNext());
    showTNodeAtLevelK(k, root->getPrev());
}


template <class T>
void BTree<T>::traverseNLR(Node<T> *root){
    if(root == NULL) return;
    root->showInfo();
    traverseNLR(root->getNext());
    traverseNLR(root->getPrev());
}
template <class T>
void BTree<T>::traverseLNR(Node<T> *root){
    if(root == NULL) return;
    traverseLRN(root->getPrev());
    root->showInfo();
    traverseLRN(root->getNext());
}

template <class T>
void BTree<T>::traverseLRN(Node<T> *root){
    if(root == NULL) return;
    traverseLRN(root->getPrev());
    traverseLRN(root->getNext());
    root->showInfo();
}

template <class T>
void BTree<T>::traverseNRL(Node<T> *root){
    if(root == NULL) return;
    root->showInfo();
    traverseNRL(root->getNext());
    traverseNRL(root->getPrev());
}

template <class T>
void BTree<T>::traverseRNL(Node<T> *root){
    if(root == NULL) return;
    traverseRNL(root->getNext());
    root->showInfo();
    traverseRNL(root->getPrev());
}

template <class T>
void BTree<T>::traverseRLN(Node<T> *root){
    if(root == NULL) return;
    traverseRLN(root->getNext());
    traverseRLN(root->getPrev());
    root->showInfo();
}

template <class T>
void BTree<T>::traverseBreadthNLR(Node<T> *root){
    if(root == NULL) return;

    queue<Node<T> *> q;
    q.push(root);

    while(q.empty() == false){
        Node<T> *p = q.front();
        q.pop();
        p->showInfo();

        if(p->getPrev() != NULL){
            q.push(p->getPrev());
        }
        if(p->getNext() != NULL){
            q.push(p->getNext());
        }
    }
}

template <class T>
void BTree<T>::traverseDepthNLR(Node<T> *root){
    if(root == NULL) return;
    stack<Node<T> *> stk;
    stk.push(root);
    while(stk.empty() == false){
        Node<T> *tmp = stk.top();
        stk.pop();
        tmp->showInfo();

        if(tmp->getNext() != NULL) stk.push(tmp->getNext());
        if(tmp->getPrev() != NULL) stk.push(tmp->getPrev());
    }
}


template <class T>
Node<T> *BTree<T>::findTNode(T x){
    if(getRoot() == NULL) return NULL;
    if(getRoot()->getInfo() == x) return getRoot();
    Node<T> *tmp = Root;
    while(tmp != NULL){
        if(tmp->getInfo() == x) return tmp;
        if(tmp->getInfo() < x) tmp = tmp->getNext();
        else tmp = tmp->getPrev();
    }
    return tmp;
}

template <class T>
Node<T> *BTree<T>::findTNodeMinDistanceX(T x){
    if(getRoot() == NULL) return NULL;
    Node<T>*result = getRoot(),
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
Node<T> *BTree<T>::findTNodeMaxDistanceX(T x){
    if(getRoot() == NULL) return NULL;
    Node<T>    *TNodeLeft  = getRoot(),
                *TNodeRight = getRoot();
    while(TNodeLeft->getPrev() != NULL) TNodeLeft = TNodeLeft->getPrev();
    while(TNodeRight->getPrev() != NULL) TNodeRight = TNodeRight->getNext();
    int disLeft = abs(x - TNodeLeft->getInfo()),
        disRight = abs(x - TNodeRight->getInfo());
    return (disLeft > disRight) ? TNodeLeft : TNodeRight;
}

template <class T>
Node<T> *BTree<T>::findRootTNode(T x){
    if(getRoot() == NULL) return NULL;
    if(getRoot()->getInfo() == x) return NULL;
    Node<T> *tmp = getRoot();
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
Node<T> *BTree<T>::findRootTNodeMinRight(Node<T> *root){
    if(root == NULL) return NULL;
    Node<T> *tmp = root->getNext();
    if(tmp == NULL) return NULL;
    while(tmp->getPrev() != NULL){
        tmp = tmp->getPrev();
    }
    return tmp;
}

template <class T>
Node<T> *BTree<T>::findRootTNodeMaxLeft(Node<T> *root){
    if(root == NULL) return NULL;
    Node<T> *tmp = root->getPrev();
    if(tmp == NULL) return NULL;
    while(tmp->getNext() != NULL){
        tmp = tmp->getNext();
    }
    return tmp;
}

template <class T>
bool BTree<T>::deleteTree(Node<T> *root){
    if(root == NULL) return false;
    deleteTree(root->getPrev());
    deleteTree(root->getNext());

    delete root;
    setRoot(NULL);
    return true;
}

#endif