#include <iostream>
#include <Windows.h>
#include "Buoi04_Queue.h"
using namespace std;

void main()
{
	SetConsoleOutputCP(CP_UTF8);

	Queue q;
	initQueue(q);
	createQueue_Automatic(q);
	cout << "Nội dung hàng đợi:\n";
	showQueue(q);
	cout << endl;
	
	for (int i = 1; i < 5; i++)
		pushQ(q, createQNode(i));
	cout << "Hàng đợi sau khi thêm phần tử:\n";
	showQueue(q);
	cout << endl;
	
	cout << "Lấy các phần tử sau trong hàng đợi:\n";
	for (int i = 1; i < 3; i++)
	{
		QNode* p = popQ(q);
		showQNode(p);
		cout << '\t';
	}
	cout << endl;

	cout << "Hàng đợi sau khi lấy phần tử:\n";
	showQueue(q);
	cout << endl;
}