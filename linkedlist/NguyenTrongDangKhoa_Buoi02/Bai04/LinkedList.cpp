#include "LinkedList.h"

Node* createNode(Data Info){
    cout << "Nhap co so \"a\": " ;
    cin >> Info.coso;
    cout << "Nhap so mu \"n\": ";
    cin >> Info.somu;
    Node* p = new Node(Info);
    if(p == NULL){
        cout << "Memory is not enough";
        return;
    }
    return p;
}

Node* Node::plus(Node* q){
    if(Info.somu != q->getInfo().somu) return NULL;
    Data x;
    x.coso = Info.coso + q->getInfo().coso;
    x.somu = Info.somu;
    Node* p = new Node(x);
    return p;
}

Node* Node::minus(Node* q){
    if(Info.somu != q->getInfo().somu) return NULL;
    Data x;
    x.coso = Info.coso - q->getInfo().coso;
    x.somu = Info.somu;
    Node* p = new Node(x);
    return p;
}

Node* Node::multiply(Node* q){
    Data x;
    x.somu = Info.somu + q->getInfo().somu;
    x.coso = Info.coso * q->getInfo().coso;
    return new Node(x);
}

float Node::calculate(int x){
    return Info.coso*pow(x, Info.somu);
}
//=======================================

void LinkedList::deleteNode(Node* p){
    if(getHead() == p){
        setHead(p->getNext());
        delete p;
    }
    for(Node* tmp = getHead(); tmp->getNext() != NULL; tmp = tmp->getNext()){
        if(tmp->getNext() == p){
            tmp->setNext(p->getNext());
            delete p;
        }
    }
}

void LinkedList::sortDESC(){
    for(Node* x = getHead(); x != NULL; x = x->getNext()){
        for(Node* y = x->getNext(); y != NULL; y = y->getNext()){
            if(x->getInfo().somu < y->getInfo().somu){
                swap(x->getInfo(), y->getInfo());
            }
        }
    }
}
void LinkedList::simply(){
    for(Node* x = getHead(); x != NULL; x = x->getNext()){
        Node* tmp = x;
        for(Node* y = x->getNext(); y != NULL; y = y->getNext()){
            Node* tmp2 = tmp->plus(y);
            if(tmp2 != NULL){
                deleteNode(y);
                tmp = tmp2;
                delete tmp2;
            }
        }
        x->setInfo(tmp->getInfo().coso, tmp->getInfo().somu);
        delete tmp;
    }
}
void LinkedList::addMonomial(Node* p){
    if(p == NULL) return;
    if(getHead() == NULL){
        setHead(p);
        return;
    }

    for(Node* tmp = getHead();tmp->getNext() != NULL; tmp = tmp->getNext()){
        if(tmp->getNext()->getInfo().somu > p->getInfo().somu){
            p->setNext(tmp->getNext());
            tmp->setNext(p);
            break;
        }
    }

}
void LinkedList::deleteMonomial(int bac){
    for(Node* tmp = getHead(); tmp != NULL; tmp = tmp->getNext()){
        if(bac == tmp->getInfo().somu){
            deleteNode(tmp);
        }
    }
}
float LinkedList::calculate(int x){
    float rs = 0;
    for(Node* tmp = getHead(); tmp != NULL; tmp = tmp->getNext()){
        rs += tmp->calculate(x);
    }
    return rs;
}

/*
f
*/

LinkedList* bla(LinkedList *P, LinkedList *Q, char type[2]){
    LinkedList* sl = new LinkedList();
    for(Node* p = P->getHead(); p != NULL; p = p->getNext()){
        for(Node* q = Q->getHead(); q != NULL; q = q->getNext()){
            switch(type[0]){
                case 'p'://plus
                    sl->addMonomial(p->plus(q));
                    break;
                case 'n'://minus
                    sl->addMonomial(p->minus(q));
                    break;
                case 'm'://multiply
                    sl->addMonomial(p->multiply(q));
                    break;
            }
        }
    }
}

/*./end f*/