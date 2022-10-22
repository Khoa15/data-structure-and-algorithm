#include "BigInt.h"

Node* createNode(char *val){
    Node* p = new Node();
    if(p == NULL){
        cout << "Memory is not enought";
        return NULL;
    }
    // strcpy(p->val[0], val);
    p->val[0] = val[0];
    p->pNext = NULL;
    return p;
}
//============================================================
void BigInt::printNumbers(Node* p){
    if(p == NULL) return;
    printNumbers(p->pNext);
    cout << p->val[0];
}
void BigInt::addNumber(Node* p){
    if(p == NULL) return;
    length += 1;
    if(pHead == NULL){
        pHead = p;
        return;
    }
    Node* tmp = pHead;
    while(tmp->pNext != NULL){
        tmp = tmp->pNext;
    }
    tmp->pNext = p;
    pTail = p;
}
BigInt* copy(Node* pHead){
    BigInt* a;
    for(Node* tmp = pHead; tmp != NULL; tmp = tmp->pNext){
        a->addNumber(createNode(tmp->val));
    }
    return a;
}
BigInt* BigInt::plus(BigInt* Q){
    BigInt *a = new BigInt();
    if(Q->pHead == NULL || pHead == NULL){
        delete a;
        a = copy((pHead == NULL) ? Q->pHead : pHead);
        return a;
    }
    bool large = false;
    if(length > Q->length){
        large = true;
    }
    int carry = 0;
    Node* q = (large) ? Q->pHead : pHead;
    for(Node* tmp = (large) ? pHead : Q->pHead; tmp != NULL; tmp = tmp->pNext){
        int rs = atoi(tmp->val) + atoi((q != NULL) ? q->val : "0") + carry;
        if(rs > 9){
            rs = 9;
            carry = rs - 9;
        }
        char l = rs + '0';
        a->addNumber(createNode(&l));
        if(q != NULL){
            q = q->pNext;

        }
    }
    return a;
}

BigInt* BigInt::minus(BigInt* Q){
    BigInt *a = new BigInt();
    if(Q->pHead == NULL || pHead == NULL){
        delete a;
        a = copy((pHead == NULL) ? Q->pHead : pHead);
        return a;
    }
    bool large = false;
    a->isPositive = false;
    if(length > Q->length){
        a->isPositive = true;
        large = true;
    }
    int carry = 0;
    Node* q = (large) ? Q->pHead : pHead;
    for(Node* tmp = (large) ? pHead : Q->pHead; tmp != NULL; tmp = tmp->pNext){
        int rs;
        if(atoi(tmp->val) - carry - atoi((q != NULL) ? q->val : "0") < 0){
            rs = 10 + atoi(tmp->val) - carry - atoi((q != NULL) ? q->val : "0");
            if(carry != 0) carry -= 1;
            carry += 1;
        }else{
            rs = atoi(tmp->val) - carry - atoi((q != NULL) ? q->val : "0");
            if(carry != 0){ carry -= 1;}
        }
        // 250 - 565 =  -305
        char l = rs + '0';
        a->addNumber(createNode(&l));
        if(q != NULL){
            q = q->pNext;
        }
    }
    return a;
}

// BigInt* BigInt::multiply(BigInt* Q){
//     for(Node* x = pHead; x != NULL; x = x->pNext){
//         int a = 1;
//         for(Node* y = Q->pHead; y != NULL; y = y->pNext){
//             atoi(y->val) * atoi(x->val);
//         }
//     }
// }
///

int main(){
    char    *a = "10000",
            *b = "200";
    BigInt  *P = new BigInt(),
            *Q = new BigInt(),
            *A = new BigInt();
    for(int i = strlen(b)-1; i >= 0; i--){
        P->addNumber(createNode(&b[i]));
    }
    for(int i = strlen(a)-1; i >= 0; i--){
        Q->addNumber(createNode(&a[i]));
    }
    A = P->minus(Q);
    A->printNumbers(A->pHead);
    return 0;
}