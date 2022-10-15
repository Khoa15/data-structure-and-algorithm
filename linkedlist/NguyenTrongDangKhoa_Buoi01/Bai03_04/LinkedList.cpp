#include "LinkedList.h"
#include <iostream>
#include <algorithm>
#include <Windows.h>
using namespace std;
void SList::printList() {
	for (Node* tmp = getHead(); tmp != NULL; tmp = tmp->Next()) {
		std::cout << tmp->Info() << " ";
	}
	std::cout << endl;
}
void SList::addNode(int x) {
	Node* p = new Node(x);
	if (p == NULL) {
		std::cout << "Your memory is not enough";
		return;
	}
	if (getHead() == NULL) {
		setHead(p);
		setTail(p);
		return;
	}
	if(getHead()->Info() > x){
		p->setNext(getHead());
		setHead(p);
		return;
	}
	if(getTail()->Info() < x){
		getTail()->setNext(p);
		setTail(p);
		return;
	}
	for (Node* tmp = getHead(); tmp->Next() != NULL; tmp = tmp->Next()) {
		if(tmp->Next()->Info() >= p->Info()){
			p->setNext(tmp->Next());
			tmp->setNext(p);
			return;
		}
	}
}
void SList::connectSListAfterX(SList* sl2, int x) {
	bool flag = false;
	for (Node* tmp = getHead(); tmp != NULL; tmp = tmp->Next()) {
		if (tmp->Info() == x) {
			sl2->getTail()->setNext(tmp->Next());
			tmp->setNext(sl2->getHead());
			// delete sl2;
			flag = true;
			break;
		} 
	}
	if (flag == false) {
		cout << "Khong co phan tu x\n";
	}
}
void SList::printASC(Node* cur) {
	if (cur == NULL) return;
	printASC(cur->Next());
	cout << cur->Info() << " ";
}

void SList::sortList(bool isASC) {
	for (Node* x = getHead(); x != NULL; x = x->Next()){
		Node* min = x;
		for (Node* y = x->Next(); y != NULL; y = y->Next()) {
			if (min->Info() > y->Info()) {
				min = y;
			}
		}
		x->swapVal(min);
	}
}
void SList::merge(SList* sl) {
	if(pHead == NULL){
		setHead(sl->getHead());
		setTail(sl->getTail());
		return;
	}
	getTail()->setNext(sl->getHead());
	setTail(sl->getTail());
}
void SList::mergeASC(SList* sl) {
	merge(sl);
	sortList(false);
}
void SList::mergeDESC(SList* sl) {
	merge(sl);
	sortList(true);
}
void SList::mergeEvenASCOddDESC(SList* sl) {
	merge(sl);
	Node* key = NULL;
	for (Node* x = getHead(); x != NULL; x = x->Next()) {
		if (x->Info() % 2 == 0) {
			key = x;
			for (Node* y = x->Next(); y != NULL; y = y->Next()) {
				if (y->Info() % 2 == 0 && y->Info() < key->Info()) {
					key = y;
				}
			}
		}
		else {
			key = x;
			for (Node* y = x->Next(); y != NULL; y = y->Next()) {
				if (y->Info() % 2 == 0 && y->Info() < key->Info()) {
					key = y;
				}
			}
		}
		x->swapVal(key);
	}
}
void SList::mergeEvenPosASCOddPosDESC(SList* sl) {
	merge(sl);
	Node* key = NULL;
	int i = 0;
	for (Node* x = getHead(); x != NULL; x = x->Next()) {
		if (i % 2 == 0) {
			key = x;
			for (Node* y = x->Next(); y != NULL; y = y->Next()) {
				if (y->Info() % 2 == 0 && y->Info() < key->Info()) {
					key = y;
				}
			}
		}
		else {
			key = x;
			for (Node* y = x->Next(); y != NULL; y = y->Next()) {
				if (y->Info() % 2 == 0 && y->Info() < key->Info()) {
					key = y;
				}
			}
		}
		x->swapVal(key);
		i++;
	}
}
void Menu(short int option);
void Bai3(SList* sl, SList* sl2);
void Bai4(SList* sl, SList* sl1, SList* sl2);

int  main() {
	srand(time(0));
	SetConsoleOutputCP(65001);
	short int option = 0;
	SList* sl = new SList(), *sl1 = new SList(), * sl2 = new SList();
	sl->createSList();
	sl1->createSList();
	sl2->createSList();
	while (1) {
		if(option == 0){
			Menu(option);
			cout << "Choose an option: ";
			cin >> option;
		}
		Menu(option);
		switch (option) {
		case 3:
			Bai3(sl, sl2);
			break;
		case 4:
			Bai4(sl, sl1, sl2);
			break;
		case 0:
			return 0;
			break;
		default:
			option = 0;
			break;
		}
	}
}

void Menu(short int option) {
	switch (option) {
	case 3:
		printf(
			"1. In danh sach\n"
			"2. Chen phan tu x vao danh sach sao cho van giu nguyen tang dan.\n"
			"3. In danh sach theo thu tu giam dan.\n"
			"4. Noi danh sach sl2 vao sau phan tu co gia tri x trong danh sach sl1\n"
			"0. Quay lai\n"
		);
		break;
	case 4:
		printf("1. In danh sach\n"
			"2. Tron 2 danh sach tren tang dan\n"
			"3. Tron 2 danh sach thanh mot danh sach sl giam dan\n"
			"4. Tron 2 danh sach thanh mot danh sach sl sao cho cac phan tu co gia tri chan tang dan, cac phan tu co gia tri le giam dan\n"
			"5. Tron 2 danh sach thanh mot danh sach sl sao cho cac phan tu co vi tri chan tang dan, cac phan tu co vi tri le giam dan\n"
			"0. Quay lai\n"
		);
		break;
	default:
		printf(
			"3. Bai 3\n"
			"4. Bai 4\n"
			"0. Thoat\n"
		);
		break;
	}
}

void Bai3(SList* sl, SList* sl2) {
	short int option = 0;
	int x = 0;
	cout << "Choose an option: ";
	cin >> option;
	switch (option) {
	case 0:
		return;
		break;
	case 1:
		printf("SL: ");
		sl->printList();
		printf("\nSL2: ");
		sl2->printList();
		break;
	case 2:
		printf("Enter value's x: ");
		scanf("%d", &x);
		sl->addNode(x);
		break;
	case 3:
		sl->printASC(sl->getHead());
		printf("\n");
		break;
	case 4:
		printf("Enter value's x: ");
		scanf("%d", &x);
		sl->connectSListAfterX(sl2, x);
		break;
	}
}

void Bai4(SList* sl, SList* sl1, SList* sl2) {
	sl->deleteList();
	short int option = 0;
	cin >> option;
	switch (option) {
	case 0:
		return;
		break;
	case 1:
		printf("SL: ");
		sl->printList();
		printf("\nSL1: ");
		sl1->printList();
		printf("\nSL2: ");
		sl2->printList();
		break;
	case 2:
		sl->mergeASC(sl2);
		sl->mergeASC(sl1);
		break;
	case 3:
		sl->mergeDESC(sl2);
		sl->mergeDESC(sl1);
		break;
	case 4:
		sl->mergeEvenASCOddDESC(sl2);
		sl->mergeEvenASCOddDESC(sl1);
		break;
	case 5:
		sl1->mergeEvenPosASCOddPosDESC(sl2);
		break;
	}
}