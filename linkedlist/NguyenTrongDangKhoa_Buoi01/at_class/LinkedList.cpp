#include <iostream>
#include "Helper.h"
#include "LinkedList.h"
void SList::addHead(Node* p) {
	if (isEmpty() == true) {
		setHead(p);
		setTail(p);
		return;
	}
	p->pNext = pHead;
	setHead(p);
}

void SList::addTail(Node* p) {
	if (isEmpty() == true) {
		setHead(p);
		setTail(p);
		return;
	}
	Node* tmp = pHead;
	while (tmp->pNext != NULL) {
		tmp = tmp->pNext;
	}
	tmp->pNext = p;
	setTail(p);	
}
void SList::addXBeforeY(Data x, Data y){
	if (pHead->top == y) {
		addHead(new Node(x));
		return;
	}
	for (Node* tmp = pHead; tmp->pNext != NULL; tmp = tmp->pNext) {
		if (tmp->pNext->top == y) {
			Node* p = new Node(x);
			p->pNext = tmp->pNext;
			tmp->pNext = p;
			return;
		}
	}
}
void SList::deleteNode(Node* p) {
	if (pHead == p) {
		setHead(p->pNext);
		delete p;
		return;
	}
	for (Node* tmp = pHead; tmp != NULL; tmp = tmp->pNext) {
		if (tmp->pNext == p) {
			tmp->pNext = p->pNext;
			delete p;
			return;
		}
	}
}
void SList::deleteNodeLargerX(Data x){
	for (Node* tmp = pHead; tmp != NULL; tmp = tmp->pNext) {
		if (tmp->top > x) {
			deleteNode(tmp);
		}
	}
}
void SList::deleteEvenVal(){
	for (Node* tmp = pHead; tmp != NULL; tmp = tmp->pNext) {
		if (tmp->top % 2 == 0) {
			deleteNode(tmp);
		}
	}
}
void SList::sort(bool isASC){
	for (Node* x = pHead; x != NULL; x = x->pNext) {
		Data mi = x->top;
		for (Node* y = x; y != NULL; y = y->pNext) {
			if (mi > y->top) {
				mi = y->top;
			}
		}
		swap(mi, x->top);
	}
}
int SList::countPrimeNumber(){
	int result = 0;
	for (Node* p = pHead; p != NULL; p = p->pNext) {
		if (isPrime(p->top)) {
			result += 1;
		}
	}
	return result;
}
int SList::totalSquareNumber(){
	int result = 0;
	for (Node* p = pHead; p != NULL; p = p->pNext) {
		if (isSquare(p->top) == true) {
			result += p->top;
		}
	}
	return result;
}
Node* SList::findMinVal(){
	Node* result = pHead;
	for (Node* p = pHead->pNext; p != NULL; p = p->pNext) {
		if (result->top > p->top) {
			result = p;
		}
	}
	return result;
}
Node* SList::findMaxVal(){
	Node* result = pHead;
	for (Node* p = pHead->pNext; p != NULL; p = p->pNext) {
		if (result->top < p->top) {
			result = p;
		}
	}
	return result;
}
int SList::countXLarger2Y(){
	int result = 0;
	for (Node* p = pHead; p->pNext != NULL; p = p->pNext) {
		if (p->top / 2 > p->pNext->top) {
			result += 1;
		}
	}
	return result;
}
void SList::divideList(SList* sl1, SList* sl2){
	for (Node* p = pHead; p != NULL; p = p->pNext) {
		if (p->top % 2 == 0) {
			sl1->addTail(p);
			continue;
		}
		sl2->addTail(p);
	}
}

///2

void SList::getListInput(int n) {
	for (int i = 0; i < n; i++) {
		Node* p = new Node();
		printf("Nhap tu va phan so: ");
		scanf("%d%d", &p->top, &p->bot);
		addTail(p);
	}
}

void SList::simplifyListFraction() {
	for (Node* p = pHead; p != NULL; p = p->pNext) {
		p->simplify();
	}
}

Node SList::sumListFraction() {
	Node result = Node();
	for (Node* p = pHead; p != NULL; p = p->pNext) {
		result.plus(p);
	}
	return result;
}
Node SList::multipleListFraction() {
	Node result = Node(1);
	for (Node* p = pHead; p != NULL; p = p->pNext) {
		result.multiple(p);
	}
	return result;
}
Node* SList::findMinFraction() {
	Node* result = pHead;
	for(Node* p = pHead->pNext; p != NULL; p = p->pNext){
		if (result->divide() > p->divide()) {
			result = p;
		}
	}
	return result;
}
Node* SList::findMaxFraction() {
	Node* result = pHead;
	for (Node* p = pHead->pNext; p != NULL; p = p->pNext) {
		if (result->divide() < p->divide()) {
			result = p;
		}
	}
	return result;
}

void SList::plusListFraction(Data x) {
	Node tmp(x);
	for (Node* p = pHead; p != NULL; p = p->pNext) {
		p->plus(&tmp);
	}
}

void SList::printListFractionLargeY(Data y) {
	// Default: y = 1
	for (Node* p = pHead; p != NULL; p = p->pNext) {
		if(p->divide() > y*1.0)p->print();
	}
}

Node* SList::findNode(Node x) {
	for (Node* p = pHead; p != NULL; p = p->pNext) {
		if (x.top == p->top && x.bot == p->bot) return p;
	}
	return NULL;
}