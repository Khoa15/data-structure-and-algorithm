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
	void setNext(Node* p) {
		pNext = p;
	}
	void setInfo(int x){ info = x;}
	int Info() { return info; }
	void swapVal(Node* q){
		int tmp = info;
		info = q->Info();
		q->setInfo(tmp);
	}
};

class SList {
	Node* pHead;
	Node* pTail;
public:
	SList(){
		pHead = NULL;
		pTail = NULL;
	}
	void deleteList(){
		Node* tmp = pHead;
		while(tmp != NULL){
			Node* next = tmp->Next();
			delete tmp;
			tmp = next;
		}
		pHead = NULL;
		pTail = NULL;
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
	void sortList(bool isASC = false);
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