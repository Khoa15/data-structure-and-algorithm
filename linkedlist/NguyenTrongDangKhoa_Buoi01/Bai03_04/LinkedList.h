#pragma once
#ifndef _LINKED_LIST_
#define _LINKED_LIST_
#include <iostream>
#include "Helper.h"
class Node {
	int info;
	Node* pNext;
public:
	Node() : info(0), pNext(NULL) {}
	Node(int x) : info(x), pNext(NULL) {}
	Node(int x, Node* next) : info(x), pNext(next) {}

	Node* Next() { return pNext; }
	Node* setNext(Node* p) {
		pNext = p;
	}
	int Info() { return info; }
};

class SList {
	Node* pHead;
	Node* pTail;
public:
	SList(){
		pHead = NULL;
		pTail = NULL;
	}
	~SList() {
		delete[] pHead;
	}
	Node* getHead() { return pHead; }
	void setHead(Node* p) { pHead = p; }
	Node* getTail() { return pTail; }
	void setTail(Node* p) { pTail = p; }
	void printList();
	//3
	void addNode(int x);
	void printASC(Node* cur);
	void connectSListAfterX(SList* sl, int x);

	//4
	void sort(bool isASC = false);
	void merge(SList* sl);
	void mergeASC(SList* sl);
	void mergeDESC(SList* sl);
	void mergeEvenASCOddDESC(SList* sl);
	void mergeEvenPosASCOddPosDESC(SList* sl);
	
	
	void createSList() {
		for (int i = 0; i < randrange(4, 10); i++) {
			addNode(randrange(-10, 15));
		}
	}
};
#endif