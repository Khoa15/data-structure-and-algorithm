#include <iostream>
#include "Buoi02_DSLK_DaThuc.h"
using namespace std;

PNode::PNode()
{
	a = 0;
	n = 0;
	next = NULL;
}
PNode* createPNode(int a, int n)
{
	PNode* p = new PNode;

	if (p == NULL)
	{
		cout << "Not enough memory to allocate!";
		return NULL;
	}

	p->a = a;
	p->n = n;
	p->next = NULL;

	return p;
}
void deletePNode(PNode*& p)
{
	if (p == NULL)	return;

	p->next = NULL;
	delete p;
}
void showPNode(PNode* p)
{
	if (p == NULL)
		return;
	//cơ số == 0, ko hiện
	//cơ số == 1 hay -1, ko hiện cơ số
	//cơ số < 0, hiện dấu -
	//cơ số > 0, hiện dấu +
	if (p->a < 0)
		cout << " - ";
	else if (p->a > 0)
		cout << " + ";

	if ((p->a) != 0)
	{
		if (abs(p->a) != 1)
		{
			cout << abs(p->a);
			if (p->n == 1)//Hiện số mũ
				cout << "x";
			else if (p->n > 1)
				cout << "x^" << p->n;
		}
		else//abs(p->a) == 1, cơ số bằng 1
		{
			if (p->n == 0)
				cout << abs(p->a);
			else
			{
				if (p->n == 1)//Hiện số mũ
					cout << "x";
				else if (p->n > 1)
					cout << "x^" << p->n;
			}

		}
	}
}

void init(Polynomial &poly)
{
	poly.head = NULL;
	poly.tail = NULL;
}
//Kiểm tra danh sách rỗng
bool isEmpty(Polynomial poly)
{
	return poly.head == NULL;
}
//Duyệt danh sách để xuất nội dung ra màn hình
void traverse(Polynomial poly)
{
	if (isEmpty(poly))
	{
		cout << "Polynomial is empty\n";
		return;
	}

	for (PNode* p = poly.head; p != NULL; p = p->next)
		showPNode(p);
}
void addTailPolynomial(Polynomial& poly, PNode* p)
{
	if (p == NULL) return;

	if (isEmpty(poly))
		poly.head = poly.tail = p;
	else
	{
		poly.tail->next = p;
		poly.tail = p;
	}
}
//f. Thêm đơn thức p có bậc n+1 vào sau đơn thức q có bậc n (n+1) của đa thức
void addAfterPNodePolynomial(Polynomial& poly, PNode* q, PNode* p)
{
	if (p == NULL)	return;
	else
	{
		if (q == NULL)
		{
			if (poly.head == NULL)//poly is empty
				poly.head = poly.tail = p;
			else//cannot find q in poly
				return;
		}
		else
		{
			if (q == poly.tail)
				addTailPolynomial(poly, p);
			else
			{
				p->next = q->next;
				q->next = p;
			}
		}
	}
}
void SapXepTheoBacGiamDan(Polynomial poly)
{
	for(PNode*p = poly.head; p->next != NULL; p = p->next)
		for(PNode*q = p->next; q != NULL; q = q->next)
			if (p->n < q->n)
			{
				PNode* tmp = new PNode;
				tmp->a = p->a;
				tmp->n = p->n;
				p->a = q->a;
				p->n = q->n;
				q->a = tmp->a;
				q->n = tmp->n;
			}
}
void deleteHeadPolynomial(Polynomial &poly)
{
	if (poly.head == NULL)
		return;
	else
	{
		PNode* p = poly.head;
		poly.head = p->next;
		p->next = NULL;
		delete p;
	}
}
void deleteTailPolynomial(Polynomial& poly)
{
	if (poly.head == NULL)
		return;
	else
	{
		PNode* p = poly.tail;
		PNode* q = poly.head;
		if (p == q)//list has 1 element
		{
			poly.head = poly.tail = NULL;
			delete p;
		}
		else
		{
			//find the node located right before tail
			while (q->next != poly.tail)
				q = q->next;
			poly.tail = q;
			poly.tail->next = NULL;
			delete p;
		}
	}
}
void deleteMidPolynomial(Polynomial& poly, PNode* q)
{
	if (poly.head == NULL || q == NULL || q == poly.tail)//list is empty or q is NULL or list has 1 element
		return;
	else
	{
		if (q->next == poly.tail)
			deleteTailPolynomial(poly);
		else
		{
			PNode* p = q->next;
			q->next = p->next;
			p->next = NULL;
			delete p;
		}
	}
}
//d.Xóa các đơn thức có hệ số a = 0
void deletePolynomialHasBase(Polynomial &poly, int a)
{
	if (isEmpty(poly))
		return;
	for (PNode* q = poly.head; q->next != NULL; q = q->next)
	{
		if ((q->a) == a)
		{
			deleteHeadPolynomial(poly);
			break;
		}
		else if ((q->next->a) == a)
		{
			deleteMidPolynomial(poly, q);
			break;
		}
	}
}
void RutGonDaThuc(Polynomial& poly)
{
	if(isEmpty(poly))
		return;
	for(PNode* p = poly.head; p->next != NULL; p = p->next)
		for(PNode* q = p->next; q != NULL; q = q->next)
			if (p->n == q->n)
			{
				p->a += q->a;
				q->a = 0;
			}
	deletePolynomialHasBase(poly, 0);//Xóa các đơn thức có hệ số a = 0;
}
PNode* searchPolynomial(Polynomial poly, int n)
{
	for (PNode* q = poly.head; q != NULL; q = q->next)
		if (q->n == n)
			return q;
	return NULL;
}
void deletePolynomialHasExponent(Polynomial& poly, int n)
{
	if (isEmpty(poly))
		return;
	for (PNode* q = poly.head; q->next != NULL; q = q->next)
	{
		if ((q->n) == n)
		{
			deleteHeadPolynomial(poly);
			break;
		}
		else if ((q->next->n) == n)
		{
			deleteMidPolynomial(poly, q);
			break;
		}
	}
}
int value(PNode* p, int x)
{
	int kq = 0;
	int n = 1;
	for (int i = 1; i <= p->n; i++)
		n = n * x;
	kq = (p->a) * n;
	return kq;
}
int value(Polynomial poly, int x)
{
	int kq = 0;
	for (PNode* p = poly.head; p != NULL; p = p->next)
	{
		kq += value(p, x);
	}
	return kq;
}
Polynomial Add(Polynomial poly1, Polynomial poly2)
{
	Polynomial kq;
	init(kq);
	for (PNode* p = poly1.head; p != NULL; p = p->next)
		addTailPolynomial(kq, createPNode(p->a, p->n));
	for (PNode* q = poly2.head; q != NULL; q = q->next)
		addTailPolynomial(kq, createPNode(q->a, q->n));
	RutGonDaThuc(kq);
	return kq;
}
Polynomial Multiply(Polynomial poly1, Polynomial poly2)
{
	Polynomial kq;
	init(kq);
	for (PNode* p = poly1.head; p != NULL; p = p->next)
		addTailPolynomial(kq, createPNode(p->a, p->n));
	for (PNode* p = kq.head; p != NULL; p = p->next)
		for (PNode* q = poly2.head; q != NULL; q = q->next)
		{
			/////
		}
	RutGonDaThuc(kq);
	return kq;
}