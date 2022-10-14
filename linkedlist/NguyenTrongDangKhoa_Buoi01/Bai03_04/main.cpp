#include "LinkedList.h"
using namespace std;

void Menu(short int option);
void Bai3(SList* sl, SList* sl2);
void Bai4(SList* sl, SList* sl1, SList* sl2);

int  main() {
	short int option = 0;
	SList* sl = new SList(), *sl1 = new SList(), * sl2 = new SList();
	sl->createSList();
	sl1->createSList();
	sl2->createSList();
	while (1) {
		Menu(option);
		cin >> option;
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
			"2. Tron 2 danh sach tren theo thu tu giam dan\n"
			"3. Tron 2 danh sach thanh mot danh sach sl co thu tu giam\n"
			"4. Tron 2 danh sach thanh mot danh sach sl sao cho cac phan tu co gia tri chan tang dan, cac phan tu co gia tri le giam dan\n"
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
	cin >> option;
	switch (option) {
	case 0:
		return;
		break;
	case 1:
		sl->printList();
		break;
	case 2:
		printf("Enter value's x: ");
		scanf("%d", &x);
		sl->addNode(x);
		break;
	case 3:
		sl->printASC(sl->getHead());
		break;
	case 4:
		printf("Enter value's x: ");
		scanf("%d", &x);
		sl->connectSListAfterX(sl2, x);
		break;
	}
}

void Bai4(SList* sl, SList* sl1, SList* sl2) {
	short int option = 0;
	cin >> option;
	switch (option) {
	case 0:
		return;
		break;
	case 1:
		sl->printList();
		break;
	case 2:
		sl1->mergeASC(sl2);
		break;
	case 3:
		sl1->mergeDESC(sl2);
		break;
	case 4:
		sl1->mergeEvenASCOddDESC(sl2);
		break;
	case 5:
		sl1->mergeEvenPosASCOddPosDESC(sl2);
		break;
	}
}