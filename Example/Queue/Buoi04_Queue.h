#include <iostream>

typedef int Data;
struct QNode
{
	Data info;
	QNode* next;

	QNode();
};
QNode* createQNode(int x);
void showQNode(QNode* p);
/////////
struct Queue
{
	QNode* head;
	QNode* tail;
	Queue(QNode* head = NULL, QNode* tail = NULL);
};
void initQueue(Queue &q);
bool isEmpty(Queue q);
void pushQ(Queue& q, QNode* p);
QNode* popQ(Queue& q);
void createQueue_Automatic(Queue& q);
void showQueue(Queue q);