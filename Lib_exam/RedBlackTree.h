#pragma once
#ifndef _RED_BLACK_TREE_H_
#define _RED_BLACK_TREE_H_
#include <iostream>
#include <queue>
using namespace std;
typedef int ItemType;
enum ECOLOR {RED, BLACK};

struct BRTNode{
    ItemType Info;
    ECOLOR Color;
    BRTNode *Left, *Right, *Parent;

    BRTNode() : Left(NULL), Right(NULL), Parent(NULL) {}
    ~BRTNode(){
        delete this;
    }
};

struct BRTree{
    BRTNode *Root;
    BRTree() : Root(NULL) {}
    ~BRTree() {
        delete this;
    }
};

BRTNode* createBRTNode(ItemType x) {
    BRTNode* p = new BRTNode;
    if(p == NULL)
    {
        cout << "Can't allocate new node.";
        return NULL;
    }
    p->Info = x;
    p->Color = RED;
    p->Left = NULL;
    p->Right = NULL;
    p->Parent = NULL;
    return p;
}

void setColor(int colorBackground, int colorText){
    #ifdef _WIN32
    HANDLE hColor = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hColor, colorBackground * 16 + colorText);
    #endif
}

void showBRTNode(BRTNode *p){
    if(p -> Color == RED){
        setColor(15, 12);
    }else if(p -> Color == BLACK){
        setColor(15, 0);
    }

    cprintf("%4d", p->Info);
    setColor(14, 2);
}

void swapColors(ECOLOR &color1, ECOLOR &color2){
    ECOLOR tmp = color1;
    color1 = color2;
    color2 = tmp;
}

void swapInfo(ItemType &info1, ItemType &info2){
    ItemType tmp = info1;
    info1 = info2;
    info2 = tmp;
}

void levelOrder(BRTNode *root){
    if(root == NULL) return;
    queue<BRTNode *> q;
    q.push(root);

    while(q.empty() == false){
        BRTNode *p = q.front();
        q.pop();
        showBRTNode(p);
        if(p -> Left != NULL){
            q.push(p->Left);
        }else{
            q.push(p->Right);
        }
    }
}

void showLevelOrder(BRTNode *root){
    cout << endl << "Breath First Traverse" << endl;
    if(root == NULL){
        cout << "Tree is empty!" << endl;
        return;
    }
    levelOrder(root);
}

BRTNode* BRTInsert(BRTNode* root, BRTNode* p){
    if(root == NULL) return p;
    if(p->Info < root->Info){
        root->Left = BRTInsert(root->Left, p);
        root->Left->Parent = root;
    }else{
        root->Right = BRTInsert(root->Right, p);
        root->Right->Parent = root;
    }

    return root;
}

void rotateLeft(BRTNode *&root, BRTNode *&p){
    BRTNode* pRight = p->Right;

    p->Right = pRight -> Left;
    if(p->Right != NULL){
        p->Right->Parent = p;
    }

    pRight -> Parent = p->Parent;

    if(p->Parent == NULL){
        root = pRight;
    }else if(p == p->Parent->Left){
        p->Parent->Left = pRight;
    }else{
        p->Parent->Right = pRight;
    }

    pRight->Left = p;
    p->Parent = pRight;
}

void rotateRight(BRTNode *&root, BRTNode *&p) {
    BRTNode *pLeft = p->Left;
    p->Left = pLeft->Right;
    
    if(p->Left != NULL)
        p->Left->Parent = p;
    
    pLeft->Parent = p->Parent;
    if(p->Parent == NULL)
        root = pLeft;
    else if(p == p->Parent->Left)
        p->Parent->Left = pLeft;
    else
        p->Parent->Right = pLeft;
    
    pLeft->Right = p;
    p->Parent = pLeft;
}

/* S???a l???i c???u tr??c khi ch??n BRTNode v??o ho???c x??a 
node */
void fixViolation(BRTNode *&root, BRTNode *&p) {
    BRTNode *pParent = NULL;
    BRTNode *pGrandParent = NULL;
    while ((p != root) && (p->Color != BLACK) && (p->Parent->Color == RED)){
        pParent = p->Parent;
        pGrandParent = p->Parent->Parent;
        if(pParent == pGrandParent->Left)
        {
            BRTNode *pUncle = pGrandParent->Right;
            if(pUncle!=NULL && pUncle->Color==RED)
            {
                pGrandParent->Color = RED;
                pParent->Color = BLACK;
                pUncle->Color = BLACK;
                p = pGrandParent;
            }
            else
            {
                if(p == pParent->Right)
                {
                    rotateLeft(root, pParent);
                    p = pParent;
                    pParent = p->Parent;
                }
                rotateRight(root, pGrandParent);
                swapColors(pParent->Color,
                pGrandParent->Color);
                p = pParent;
            }
        }else{
            BRTNode *pUncle = pGrandParent->Left;
            
            if(pUncle != NULL && pUncle->Color==RED)
            {
                pGrandParent->Color = RED;
                pParent->Color = BLACK;
                pUncle->Color = BLACK;
                p = pGrandParent;
            }else
            {
                if(p == pParent->Left)
                {
                    rotateRight(root, pParent);
                    p = pParent;
                    pParent = p->Parent;
                }
                rotateLeft(root, pGrandParent);
                swapColors(pParent->Color,
                pGrandParent->Color);
                p = pParent;
            }
        }
    }
    root->Color = BLACK;
}

void insert(BRTNode *&root, ItemType x) {
    BRTNode *pNew = createBRTNode(x);
    root = BRTInsert(root, pNew);
    fixViolation(root, pNew);
}

/* Ki???m tra xem node hi???n t???i c?? ph???i l?? node con 
tr??i c???a node cha kh??ng */
bool isOnLeft(BRTNode *p) {
    return p == p->Parent->Left;
}

BRTNode *findUncle(BRTNode *p) {
    if(p->Parent == NULL || p->Parent->Parent == NULL)
        return NULL;
    if(isOnLeft(p->Parent))
        return p->Parent->Parent->Right;

    return p->Parent->Parent->Left;
}

/* Tr??? v??? con tr??? cho node anh em */
BRTNode *findSibling(BRTNode *p) {
    if(p->Parent == NULL) return NULL;
    
    if(isOnLeft(p)) return p->Parent->Right;
    
    return p->Parent->Left;
}

/* T??m n??t kh??ng c?? n??t con b??n tr??i trong c??y con 
c???a n??t ???? cho */
BRTNode *findSuccessor(BRTNode *p) {
    BRTNode *temp = p;
    while (temp->Left != NULL)
        temp = temp->Left;
    return temp;
}


/* Ki???m tra node hi???n t???i c?? node con l?? n??t ????? hay 
kh??ng */
bool hasRedChild(BRTNode *p) {
    return (p->Left!=NULL && p->Left->Color==RED) || (p->Right!=NULL && p->Right->Color==RED);
}

/* T??m n??t thay th??? n??t ???? x??a trong BSTree */
BRTNode *BSTReplace(BRTNode *p) {
    // Khi n??t c?? 2 con
    if(p->Left != NULL && p->Right != NULL) return findSuccessor(p->Right);

    // Khi node l?? 
    if(p->Left == NULL && p->Right == NULL) return NULL;

    // Khi node c?? m???t con
    if(p->Left != NULL) return p->Left;
    
    return p->Right;
}

/* X??a n??t ???? cho */
void deleteNode(BRTNode *&root, BRTNode *pDelete) {
    BRTNode *pReplace = BSTReplace(pDelete);
    // ????ng khi pReplace v?? pDelete ?????u ??en
    bool flagDoubleBlack = ((pReplace == NULL || pReplace->Color == BLACK) && (pDelete->Color == BLACK));
    BRTNode *pParent = pDelete->Parent;
    if(pReplace == NULL) {
        // pReplace l?? NULL do ???? pDelete l?? l?? 
        if(pDelete == root) {
        // pDelete l?? root, l??m cho root l?? NULL 
        root = NULL;
        }else {
            if(flagDoubleBlack) {
                // pReplace v?? pDelete ?????u ??en
                // pDelete l?? l??, s???a m??u ??en k??p
                fixDoubleBlack(root, pDelete);
            }else {
                // pReplace ho???c pDelete l?? ?????
                if(findSibling(pDelete) != NULL)
                    // node anh ch??? em kh??ng r???ng,
                    // l??m cho n?? m??u ?????
                    findSibling(pDelete)->Color = RED;
            }
            // X??a pDelete kh???i c??y 
            if(isOnLeft(pDelete)) {
                pParent->Left = NULL;
            }else {
                pParent->Right = NULL;
            }
        }
        delete pDelete;
        return;
    }
    if(pDelete->Left==NULL || pDelete->Right==NULL){
        // pDelete c?? 1 node con
        if(pDelete == root) {
            // G??n gi?? tr??? c???a pReplace cho pDelete
            // v?? x??a pReplace
            pDelete->Info = pReplace->Info;
            pDelete->Left = pDelete->Right = NULL;
            delete pReplace;
        }else {
            // T??ch node pDelete kh???i c??y v?? 
            // di chuy???n node pReplace l??n
            if(isOnLeft(pDelete)) {
                pParent->Left = pReplace;
            }else {
                pParent->Right = pReplace;
            }
            delete pDelete;
            pReplace->Parent = pParent;
            if(flagDoubleBlack) {
                // pReplace v?? pDelete ?????u ??en,
                // s???a hai m??u ??en ??? pReplace
                fixDoubleBlack(root, pReplace);
            }else {
                // pReplace ho???c pDelete ?????, 
                // m??u pReplace ??en 
                pReplace->Color = BLACK;
            }
        }
        return;
    }
    // pDelete c?? 2 con, ho??n ?????i gi?? tr??? v???i 
    // n??t th??? m???ng v?? ????? quy 
    swapInfos(pReplace->Info, pDelete->Info);
    deleteNode(root, pReplace);
}

void fixDoubleBlack(BRTNode *&root, BRTNode *p) {
    // p l?? node g???c th?? return
    if(p == root) return;
    BRTNode *pSibling = findSibling(p);
    BRTNode *pParent = p->Parent;
    if(pSibling == NULL) {
        // Kh??ng c?? sibiling, 
        // m??u ??en k??p ???????c ?????y l??n 
        fixDoubleBlack(root, pParent);
    }else {
        if(pSibling->Color == RED) {
            // Anh em m??u ?????
            pParent->Color = RED;
            pSibling->Color = BLACK;
            if(isOnLeft(pSibling)) {
                // Tr?????ng h???p left 
                rotateRight(root, pParent);
            }else {
                // Tr?????ng h???p right 
                rotateLeft(root, pParent);
            }
            fixDoubleBlack(root, p);
        }else {
            // Anh em ??en 
            if(hasRedChild(pSibling)) {
            // ??t nh???t 1 tr??? em m??u ?????
                if(pSibling->Left != NULL && Sibling->Left->Color == RED) {
                    if(isOnLeft(pSibling)) {
                        // left - left 
                        pSibling->Left->Color =
                        pSibling->Color;
                        pSibling->Color = 
                        pParent->Color;
                        rotateRight(root, pParent);
                    }else {
                        // right - left 
                        pSibling->Left->Color =
                        pParent->Color;
                        rotateRight(root, pSibling);
                        rotateLeft(root, pParent);
                    }
                }else {
                    if(isOnLeft(pSibling)) {
                        // left - right 
                        pSibling->Right->Color = 
                        Parent->Color;
                        rotateLeft(root, pSibling);
                        rotateRight(root, pParent);
                    }else {
                        // right - right 
                        pSibling->Right->Color =
                        pSibling->Color;
                        pSibling->Color = 
                        pParent->Color;
                        rotateLeft(root, pParent);
                    }
                }
                pParent->Color = BLACK;
            }else {
                // Hai con ??en 
                pSibling->Color = RED;
                if(pParent->Color == BLACK)
                    fixDoubleBlack(root, pParent);
                else
                    pParent->Color = BLACK;
            }
        }
    }
}

/* T??m ki???m m???t gi?? tr??? tr??n c??y */
BRTNode *search(BRTNode *root, ItemType x) {
    BRTNode *temp = root;
    while (temp != NULL) {
        if(x == temp->Info) {
            return temp;
        }else if(x < temp->Info) {
            temp = temp->Left;
        }else {
            temp = temp->Right;
        }
    }
    return NULL; //Kh??ng t??m th???y x trong c??y
}
#endif