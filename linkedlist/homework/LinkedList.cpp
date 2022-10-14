#include "LinkedList.h"
using namespace std;
#include "Helper.h"
void SList::printList() {
	for (Node* tmp = getHead(); tmp != NULL; tmp = tmp->Next()) {
		printf("%d", tmp->Info());
	}
}
void SList::addNode(int x) {
	Node* p = new Node(x);
	if (p == NULL) {
		printf("Your memory is not enough");
		return;
	}
	if (getHead() == false) {
		setHead(p);
		return;
	}
	for (Node* tmp = getHead(); tmp != NULL; tmp = tmp->Next()) {
		if (tmp->Info() <= p->Info()) {
			p->setNext(tmp->Next());
			tmp->setNext(p);
			return;
		}
	}
}
void SList::connectSListAfterX(SList* sl, int x) {
	bool flag = false;
	for (Node* tmp = getHead(); tmp != NULL; tmp = tmp->Next()) {
		if (tmp->Info() == x) {
			sl->setTail(tmp->Next());
			tmp->setNext(sl->getHead());
			delete sl;
			flag = true;
			break;
		}
	}
	if (flag == false) {
		printf("Khong co phan tu x\n");
	}
}
void SList::printASC(Node* cur) {
	if (cur == NULL) return;
	printASC(cur->Next());
	printf("%d ", cur->Info());
}

void SList::sort(bool isASC = false) {
	int min = getHead()->Info();
	for (Node* x = getHead(); x != NULL; x = x->Next()){
		min = x->Info();
		for (Node* y = x->Next(); y != NULL; y = y->Next()) {
			if (min > y->Info()) {
				min = y->Info();
			}
		}
		swap(x->Info(), min);
	}
}
void SList::merge(SList* sl) {
	getTail()->setNext(sl->getHead());
}
void SList::mergeASC(SList* sl) {
	merge(sl);
	sort();
}
void SList::mergeDESC(SList* sl) {
	merge(sl);
	sort(true);
}
void SList::mergeEvenASCOddDESC(SList* sl) {
	merge(sl);
	int key = getHead()->Info();
	for (Node* x = getHead(); x != NULL; x = x->Next()) {
		if (x->Info() % 2 == 0) {
			key = x->Info();
			for (Node* y = x->Next(); y != NULL; y = y->Next()) {
				if (y->Info() % 2 == 0 && y->Info() < key) {
					key = y->Info();
				}
			}
			swap(x->Info(), key);
		}
		else {
			key = x->Info();
			for (Node* y = x->Next(); y != NULL; y = y->Next()) {
				if (y->Info() % 2 == 0 && y->Info() < key) {
					key = y->Info();
				}
			}
			swap(x->Info(), key);
		}
	}
}
void SList::mergeEvenPosASCOddPosDESC(SList* sl) {
	merge(sl);
	int key = getHead()->Info();
	int i = 0;
	for (Node* x = getHead(); x != NULL; x = x->Next()) {
		if (i % 2 == 0) {
			key = x->Info();
			for (Node* y = x->Next(); y != NULL; y = y->Next()) {
				if (y->Info() % 2 == 0 && y->Info() < key) {
					key = y->Info();
				}
			}
			swap(x->Info(), key);
		}
		else {
			key = x->Info();
			for (Node* y = x->Next(); y != NULL; y = y->Next()) {
				if (y->Info() % 2 == 0 && y->Info() < key) {
					key = y->Info();
				}
			}
			swap(x->Info(), key);
		}
		i++;
	}
}