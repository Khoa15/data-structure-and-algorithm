<<<<<<< HEAD
#include "LinkedList.h"
#include "Helper.h"
#include <iostream>
#include <Windows.h>
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
    Node* tmp = pHead;
    while(tmp != NULL){
		if (tmp->top > x) {
            Node* tmp2 = tmp->pNext;
			deleteNode(tmp);
            tmp = tmp2;
            continue;
		}
        tmp = tmp->pNext;
    }
}
void SList::deleteEvenVal(){
	for (Node* tmp = pHead; tmp != NULL;) {
		if (tmp->top % 2 == 0) {
            Node* tmp2 = tmp->pNext;
			deleteNode(tmp);
            tmp = tmp2;
            continue;
		}
        tmp = tmp->pNext;
	}
}
void SList::sort(bool isASC){
	for (Node* x = pHead; x->pNext != NULL; x = x->pNext) {
		Data *mi = &(x->top);
		for (Node* y = x->pNext; y != NULL; y = y->pNext) {
			if ((*mi > y->top && isASC == true) || (isASC == false && *mi < y->top)) {
				mi = &(y->top);
			}
		}
		swap(*mi, x->top);
	}
}
int SList::countPrimeNumber(){
	int result = 0;
	for (Node* p = pHead; p != NULL; p = p->pNext) {
		if (isPrime(p->top) == true) {
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
			sl1->addTail(new Node(p->top));
			continue;
		}
		sl2->addTail(new Node(p->top));
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
    if(pHead == NULL){
        return Node(0);
    }
	Node result = *pHead;
	for (Node* p = pHead->pNext; p != NULL; p = p->pNext) {
        Node tmp = result.plus(p);
		result.top = tmp.top;
        result.bot = tmp.bot;
	}
	return result;
}
Node SList::multipleListFraction() {
    if(pHead == NULL){
        return Node(0);
    }
	Node result = *pHead;
	for (Node* p = pHead->pNext; p != NULL; p = p->pNext) {
        Node tmp = result.multiple(p);;
		result.top = tmp.top;
        result.bot = tmp.bot;
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
		Node tmp2 = p->plus(&tmp);
        p->top = tmp2.top;
        p->bot = tmp2.bot;
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


void Menu(int position = 0);
void Control(SList* sl, int position, int to, SList* sl1 = NULL, SList* sl2 = NULL) {
    int x = 0, y = 0;
    switch (position)
    {
    case 1:
        switch (to)
        {
        case 1:
            sl->printSList(false);
            break;
        case 2:
            printf("Enter value x: ");
            scanf("%d", &x);
            sl->addTail(new Node(x));
            break;
        case 3:
            printf("Enter value x and y: ");
            scanf("%d%d", &x, &y);
            sl->addXBeforeY(x, y);
            break;
        case 4:
            printf("Enter value x: ");
            scanf("%d", &x);
            sl->deleteNodeLargerX(x);
            break;
        case 5:
            sl->deleteEvenVal();
            break;
        case 6:
            printf("Press 0 to ASC or 1 to DESC: ");
            scanf("%d", &x);
            sl->sort(x);
            break;
        case 7:
            printf("Count prime numbers: %d\n", sl->countPrimeNumber());
            break;
        case 8:
            printf("Total square numbers: %d\n", sl->totalSquareNumber());
            break;
        case 9:
            printf("Min: %d\nMax: %d\n", sl->findMinVal()->top, sl->findMaxVal()->top);
            break;
        case 10:
            printf("Total node larger than two times behind it: ");
            printf("%d", sl->countXLarger2Y());
            break;
        case 11:
            printf("Divide even and odd numbers singly linked list\n");
            sl->divideList(sl1, sl2);
            printf("sl1: ");sl1->printSList();
            printf("\n");
            printf("sl2: ");sl2->printSList();
            break;
        default:
            break;
        }
        break;
    case 2:
        switch (to)
        {
        case 1:
            sl->printSList(true);
            break;
        case 2:
            printf("Enter n numbers: ");
            scanf("%d", &x);
            sl->getListInput(x);
            break;
        case 3:
            sl->simplifyListFraction();
            break;
        case 4:
            printf("Sum: ");sl->sumListFraction().print();
            printf("\nMultiple: ");sl->multipleListFraction().print();
            break;
        case 5:
            printf("Max fraction: ");
            sl->findMaxFraction()->print();
            printf("Min fraction:");
            sl->findMinFraction()->print();
            break;
        case 6:
            sl->plusListFraction();
            break;
        case 7:
            sl->printListFractionLargeY(1);
            break;
        case 8:
            Node fraction;
            printf("Nhap tu va mau: ");
            scanf("%d%d", &fraction.top, &fraction.bot);
            Node* result = sl->findNode(fraction);
            if(result == NULL){
                printf("NULL");
                break;
            }
            printf("Value: %d/%d\nNext: %X", result->top, result->bot, result->pNext);
            break;
        }
        break;
    default:
        printf("Error code");
        break;
    }
}

int main() {
    SetConsoleOutputCP(CP_UTF8);
    int position = 0, to = -1;
    SList* sl = new SList();
    SList* sl1 = new SList();
    SList* sl2 = new SList();
    if (sl == NULL) {
        printf("Memory is not enough");
        return 0;
    }
    while (1) {
        Menu(position);
        printf("Enter a number: ");
        if (position == 0) {
            scanf("%d", &position);
            continue;
        }
        else {
            scanf("%d", &to);
            if (to == 0) {
                position = 0;
                continue;
            }
            Control(sl, position, to, sl1, sl2);
        }
    }
    return 0;
}

void Menu(int position) {
    printf("\n==================\n");
    switch (position)
    {
    case 0:
        printf(
            "1. Bai 1\n"
            "2. Bai 2\n"
        );
        break;
    case 1:
        printf(
            "1. Xu???t danh s??ch\n"
            "2. Th??m ph???n t??? m???i v??o cu???i danh s??ch.\n"
            "3. Ch??n th??m ph???n t??? c?? gi?? tr??? x v??o tr?????c ph???n t??? c?? gi?? tr??? y.\n"
            "4. Vi???t h??m x??a c??c ph???n t??? l???n h??n x trong dslk\n"
            "5. Vi???t h??m x??a c??c ph???n t??? ch???n trong dslk\n"
            "6. S???p x???p dslk t??ng d???n, gi???m d???n\n"
            "7. Cho bi???t trong dslk c?? bao nhi??u s??? nguy??n t???\n"
            "8. T??nh t???ng c??c s??? ch??nh ph????ng trong dslk\n"
            "9. T??m ph???n t??? nh??? nh???t, ph???n t???  l???n nh???t trong dslk\n"
            "10. Cho bi???t trong dslk c?? bao nhi??u ph???n t??? l???n h??n g???p ????i ph???n t??? ph??a sau n??\n"
            "11. T??? sl t???o 2 danh s??ch m???i: sl1 ch???a c??c s??? ch???n, sl2 ch???a c??c s??? l???\n"
        );
        break;

    case 2:
        printf(
            "1. Xu???t danh s??ch c?? n ph??n s???\n"
            "2. Nh???p danh s??ch c?? n ph??n s???\n"
            "3. T???i gi???n c??c ph??n s???\n"
            "4. T??nh t???ng/ t??ch c??c ph??n s???\n"
            "5. Cho bi???t ph??n s??? l???n nh???t, ph??n s??? nh??? nh???t\n"
            "6. T??ng m???i ph??n s??? c???a danh s??ch l??n m???t ????n v???\n"
            "7. Xu???t c??c ph??n s??? l???n h??n 1 trong danh s??ch li??n k???t\n"
            "8. T??m ph??n s??? p tr??? v??? SNode, NULL n???u kh??ng c??\n"
        );
        break;
    default:
        printf("Error code\n");
        break;
    }
    printf("\n==================\n");
=======
#include "LinkedList.h"
#include "Helper.h"
#include <iostream>
#if _WIN32
#include <Windows.h>
#endif
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
    Node* tmp = pHead;
    while(tmp != NULL){
		if (tmp->top > x) {
            Node* tmp2 = tmp->pNext;
			deleteNode(tmp);
            tmp = tmp2;
            continue;
		}
        tmp = tmp->pNext;
    }
}
void SList::deleteEvenVal(){
	for (Node* tmp = pHead; tmp != NULL;) {
		if (tmp->top % 2 == 0) {
            Node* tmp2 = tmp->pNext;
			deleteNode(tmp);
            tmp = tmp2;
            continue;
		}
        tmp = tmp->pNext;
	}
}
void SList::sort(bool isASC){
	for (Node* x = pHead; x->pNext != NULL; x = x->pNext) {
		Data *mi = &(x->top);
		for (Node* y = x->pNext; y != NULL; y = y->pNext) {
			if ((*mi > y->top && isASC == true) || (isASC == false && *mi < y->top)) {
				mi = &(y->top);
			}
		}
		swap(*mi, x->top);
	}
}
int SList::countPrimeNumber(){
	int result = 0;
	for (Node* p = pHead; p != NULL; p = p->pNext) {
		if (isPrime(p->top) == true) {
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
			sl1->addTail(new Node(p->top));
			continue;
		}
		sl2->addTail(new Node(p->top));
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
    if(pHead == NULL){
        return Node(0);
    }
	Node result = *pHead;
	for (Node* p = pHead->pNext; p != NULL; p = p->pNext) {
        Node tmp = result.plus(p);
		result.top = tmp.top;
        result.bot = tmp.bot;
	}
	return result;
}
Node SList::multipleListFraction() {
    if(pHead == NULL){
        return Node(0);
    }
	Node result = *pHead;
	for (Node* p = pHead->pNext; p != NULL; p = p->pNext) {
        Node tmp = result.multiple(p);;
		result.top = tmp.top;
        result.bot = tmp.bot;
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
		Node tmp2 = p->plus(&tmp);
        p->top = tmp2.top;
        p->bot = tmp2.bot;
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


void Menu(int position = 0);
void Control(SList* sl, int position, int to, SList* sl1 = NULL, SList* sl2 = NULL) {
    int x = 0, y = 0;
    switch (position)
    {
    case 1:
        switch (to)
        {
        case 1:
            sl->printSList(false);
            break;
        case 2:
            printf("Enter value x: ");
            scanf("%d", &x);
            sl->addTail(new Node(x));
            break;
        case 3:
            printf("Enter value x and y: ");
            scanf("%d%d", &x, &y);
            sl->addXBeforeY(x, y);
            break;
        case 4:
            printf("Enter value x: ");
            scanf("%d", &x);
            sl->deleteNodeLargerX(x);
            break;
        case 5:
            sl->deleteEvenVal();
            break;
        case 6:
            printf("Press 0 to ASC or 1 to DESC: ");
            scanf("%d", &x);
            sl->sort(x);
            break;
        case 7:
            printf("Count prime numbers: %d\n", sl->countPrimeNumber());
            break;
        case 8:
            printf("Total square numbers: %d\n", sl->totalSquareNumber());
            break;
        case 9:
            printf("Min: %d\nMax: %d\n", sl->findMinVal()->top, sl->findMaxVal()->top);
            break;
        case 10:
            printf("Total node larger than two times behind it: ");
            printf("%d", sl->countXLarger2Y());
            break;
        case 11:
            printf("Divide even and odd numbers singly linked list\n");
            sl->divideList(sl1, sl2);
            printf("sl1: ");sl1->printSList();
            printf("\n");
            printf("sl2: ");sl2->printSList();
            break;
        default:
            break;
        }
        break;
    case 2:
        switch (to)
        {
        case 1:
            sl->printSList(true);
            break;
        case 2:
            printf("Enter n numbers: ");
            scanf("%d", &x);
            sl->getListInput(x);
            break;
        case 3:
            sl->simplifyListFraction();
            break;
        case 4:
            printf("Sum: ");sl->sumListFraction().print();
            printf("\nMultiple: ");sl->multipleListFraction().print();
            break;
        case 5:
            printf("Max fraction: ");
            sl->findMaxFraction()->print();
            printf("Min fraction:");
            sl->findMinFraction()->print();
            break;
        case 6:
            sl->plusListFraction();
            break;
        case 7:
            sl->printListFractionLargeY(1);
            break;
        case 8:
            Node fraction;
            printf("Nhap tu va mau: ");
            scanf("%d%d", &fraction.top, &fraction.bot);
            Node* result = sl->findNode(fraction);
            if(result == NULL){
                printf("NULL");
                break;
            }
            printf("Value: %d/%d\nNext: %X", result->top, result->bot, result->pNext);
            break;
        }
        break;
    default:
        printf("Error code");
        break;
    }
}

int main() {
    #if _WIN32
    SetConsoleOutputCP(CP_UTF8);
    #endif
    int position = 0, to = -1;
    SList* sl = new SList();
    SList* sl1 = new SList();
    SList* sl2 = new SList();
    if (sl == NULL) {
        printf("Memory is not enough");
        return 0;
    }
    while (1) {
        Menu(position);
        printf("Enter a number: ");
        if (position == 0) {
            scanf("%d", &position);
            continue;
        }
        else {
            scanf("%d", &to);
            if (to == 0) {
                position = 0;
                continue;
            }
            Control(sl, position, to, sl1, sl2);
        }
    }
    return 0;
}

void Menu(int position) {
    printf("\n==================\n");
    switch (position)
    {
    case 0:
        printf(
            "1. Bai 1\n"
            "2. Bai 2\n"
        );
        break;
    case 1:
        printf(
            "1. Xu???t danh s??ch\n"
            "2. Th??m ph???n t??? m???i v??o cu???i danh s??ch.\n"
            "3. Ch??n th??m ph???n t??? c?? gi?? tr??? x v??o tr?????c ph???n t??? c?? gi?? tr??? y.\n"
            "4. Vi???t h??m x??a c??c ph???n t??? l???n h??n x trong dslk\n"
            "5. Vi???t h??m x??a c??c ph???n t??? ch???n trong dslk\n"
            "6. S???p x???p dslk t??ng d???n, gi???m d???n\n"
            "7. Cho bi???t trong dslk c?? bao nhi??u s??? nguy??n t???\n"
            "8. T??nh t???ng c??c s??? ch??nh ph????ng trong dslk\n"
            "9. T??m ph???n t??? nh??? nh???t, ph???n t???  l???n nh???t trong dslk\n"
            "10. Cho bi???t trong dslk c?? bao nhi??u ph???n t??? l???n h??n g???p ????i ph???n t??? ph??a sau n??\n"
            "11. T??? sl t???o 2 danh s??ch m???i: sl1 ch???a c??c s??? ch???n, sl2 ch???a c??c s??? l???\n"
        );
        break;

    case 2:
        printf(
            "1. Xu???t danh s??ch c?? n ph??n s???\n"
            "2. Nh???p danh s??ch c?? n ph??n s???\n"
            "3. T???i gi???n c??c ph??n s???\n"
            "4. T??nh t???ng/ t??ch c??c ph??n s???\n"
            "5. Cho bi???t ph??n s??? l???n nh???t, ph??n s??? nh??? nh???t\n"
            "6. T??ng m???i ph??n s??? c???a danh s??ch l??n m???t ????n v???\n"
            "7. Xu???t c??c ph??n s??? l???n h??n 1 trong danh s??ch li??n k???t\n"
            "8. T??m ph??n s??? p tr??? v??? SNode, NULL n???u kh??ng c??\n"
        );
        break;
    default:
        printf("Error code\n");
        break;
    }
    printf("\n==================\n");
>>>>>>> 5854172727e5b18115b37e978688197f95627cef
}