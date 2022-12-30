#include <iostream>
#include "DirectAccessHashTable.h"
using namespace std;

HashNode::HashNode()
{
	key = 0;
	next = NULL;
}
int HashFunction(int key)
{
	return (key % KEYSIZE);
}
void InitBucket()
{
	for (int b = 0; b < KEYSIZE; b++)
		bucket[b] = NULL;
}
void Push(int b, int x)
{
	HashNode* p = new HashNode;
	p->key = x;
	p->next = bucket[b];
	bucket[b] = p;
}
void InsertAfter(HashNode* p, int k)
{
	if (p == NULL)
		cout << "Không thêm vào node mới được\n";
	else
	{
		HashNode* q = new HashNode;
		q->key = k;
		q->next = p->next;
		p->next = q;
	}
}
void Place(int b, int k)
{
	HashNode* p, * q;
	q = NULL;
	for (p = bucket[b]; p != NULL && k > p->key; p = p->next)
		q = p;
	if (q == NULL)
		Push(b, k);
	else
		InsertAfter(q, k);
}
int IsEmptyBucket(int b)
{
	return bucket[b] == NULL;
}
void FreeNode(HashNode* p)
{
	delete  p;
}
int Pop(int b)
{
	HashNode* p;
	int k;
	if (IsEmptyBucket(b))
	{
		cout << "Bucket " << b << " bị rỗng. Không xóa được\n";
		return 0;
	}
	p = bucket[b];
	k = p->key;
	bucket[b] = p->next;
	delete p;
	return k;
}
int DeleteAfter(HashNode* p)
{
	HashNode* q;
	int k;
	if (p == NULL || p->next == NULL)
	{
		cout << "Không xóa node được\n";
		return 0;
	}
	q = p->next;
	k = q->key;
	p->next = q->next;
	delete q;
	return k;
}
int Remove(int k)
{
	HashNode* p, * q;
	int b = HashFunction(k);
	p = bucket[b];
	while (p != NULL && p->key != k)
	{
		q = p;
		p = p->next;
	}
	if (p == NULL)
		cout << "Không có nút có khóa " << k << endl;
	else if (p == bucket[b])
		Pop(b);
	else
		DeleteAfter(q);
}
void ClearBucket(int b)
{
	HashNode* p, * q;
	q = NULL;
	p = bucket[b];
	while (p != NULL)
	{
		q = p;
		p = p->next;
		FreeNode(q);
	}
	bucket[b] = NULL;
}
void Clear()
{
	for (int b = 0; b < KEYSIZE; b++)
		ClearBucket(b);
}
void TraverseBucket(int b)
{
	HashNode* p = bucket[b];
	while (p != NULL)
	{
		cout << p->key << '\t';
		p = p->next;
	}
}
void Traverse()
{
	for (int b = 0; b < KEYSIZE; b++)
	{
		cout << "Bucket thứ " << b << ":" << endl;
		TraverseBucket(b);
	}
}
HashNode* Search(int k)
{
	int b = HashFunction(k);
	HashNode* p = bucket[b];
	while ((p != NULL) && (k > p->key))
		p = p->next;
	if (p == NULL || k != p->key)
		return NULL;
	return p;
}