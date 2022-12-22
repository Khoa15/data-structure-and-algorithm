#include <iostream>
#include "Buoi04_Queue.h"
using namespace std;

QNode::QNode()
{
	info = 0;
	next = NULL;
}
QNode* createQNode(int x)
{
	QNode* p = new QNode;
	if (p == NULL)
	{
		cout << "Not enough memory to allocate!";
		return NULL;
	}
	p->info = x;
	p->next = NULL;
	return p;
}
void showQNode(QNode* p)
{
	if (p != NULL)
		cout << p->info;
}
///////////
Queue:: Queue(QNode* head, QNode* tail)
{
	this->head = head;
	this->tail = tail;
}
void initQueue(Queue& q)
{
	q.head = NULL;
	q.tail = NULL;
}
bool isEmpty(Queue q)
{
	return q.head == NULL;
}
void pushQ(Queue& q, QNode* p)
{
	if (p != NULL)
		if (q.head == NULL)
			q.head = q.tail = p;
		else
		{
			q.tail->next = p;
			q.tail = p;
		}
}
QNode* popQ(Queue& q)
{
	QNode* p = NULL;
	if (q.head != NULL)
	{
		p = q.head;
		q.head = q.head->next;
		p->next = NULL;
	}
	return p;
}
void createQueue_Automatic(Queue& q)
{
	int n;
	cout << "Nhập số phần tử của hàng đợi: ";
	cin >> n;
	initQueue(q);
	srand((unsigned)time(NULL));
	for (int i = 1; i <= n; i++)
	{
		int x = (rand() % 199) - 99;
		QNode* p = createQNode(x);
		pushQ(q, p);
	}
}
void showQueue(Queue q)
{
	if (isEmpty(q))
	{
		cout << "Hàng đợi rỗng\n";
		return;
	}
	for (QNode* p = q.head; p != NULL; p = p->next)
		cout << p->info << '\t';

}