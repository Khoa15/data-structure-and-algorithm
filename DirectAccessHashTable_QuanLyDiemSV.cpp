#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include "DirectAccessHashTable_QuanLyDiemSV.h"
using namespace std;

////////Phương thức thiết lập các CTDL
HashNodeSV::HashNodeSV()
{
	strcpy(maSV, "");
	strcpy(hoTen, "");
	namSinh = 0;
	diem = 0;
	next = NULL;
}
int HashFunctionSV(int key)
{
	return (key % KEYSIZESV);
}
void InitBucketSV()
{
	for (int b = 0; b < KEYSIZESV; b++)
		bucketSV[b] = NULL;
}
void Push(int b, HashNodeSV sv)
{
	HashNodeSV* p = new HashNodeSV;
	strcpy(p->maSV, sv.maSV);
	strcpy(p->hoTen, sv.hoTen);
	p->namSinh = sv.namSinh;
	p->next = bucketSV[b];
	bucketSV[b] = p;
}
HashNodeSV* createHashNodeSV(HashNodeSV sv)
{
	HashNodeSV* p = new HashNodeSV;

	if (p == NULL)
	{
		cout << "Không đủ bộ nhớ để cấp phát!!!\n";
		return NULL;
	}

	strcpy(p->maSV, sv.maSV);
	strcpy(p->hoTen, sv.hoTen);
	p->namSinh = sv.namSinh;
	p->diem = sv.diem;
	p->next = NULL;

	return p;
}
void showHashNodeSV(HashNodeSV* p)
{
	cout << "/***********Thông tin sinh viên*********/" << endl;
	cout << "Mã sinh viên: " << p->maSV << endl;
	cout << "Họ tên SV: " << p->hoTen << endl;
	cout << "Năm sinh: " << p->namSinh << endl;
	cout << "Điểm kết quả học tập: " << p->diem << endl;
	cout << "/**************************************/" << endl;
}
void InsertAfter(HashNodeSV* p,  HashNodeSV sv)
{
	if (p == NULL)
		cout << "Không thêm vào node mới được\n";
	else
	{
		HashNodeSV* q = new HashNodeSV;
		strcpy(q->maSV, sv.hoTen);
		strcpy(q->hoTen, sv.hoTen);
		q->namSinh = sv.namSinh;
		q->diem = sv.diem;
		q->next = p->next;
		p->next = q;
	}
}
void Place(int b, HashNodeSV sv)
{
	HashNodeSV* p, * q;
	q = NULL;
	for (p = bucketSV[b]; p != NULL && sv.diem > p->diem; p = p->next)
		q = p;
	if (q == NULL)
		Push(b, sv);
	else
		InsertAfter(q, sv);
}
int IsEmptyBucketSV(int b)
{
	return bucketSV[b] == NULL;
}
void FreeNode(HashNodeSV* p)
{
	strcpy(p->maSV, "");
	strcpy(p->hoTen, "");
	p->namSinh = 0;
	p->diem = 0;

	delete  p;
}
HashNodeSV* Pop(int b)
{
	HashNodeSV* p;
	HashNodeSV* sv;
	if (IsEmptyBucketSV(b))
	{
		cout << "Bucket " << b << " bị rỗng. Không xóa được\n";
		return 0;
	}
	p = bucketSV[b];
	strcpy(sv->maSV, p->maSV);
	strcpy(sv->hoTen, p->hoTen);
	sv->namSinh = p->namSinh;
	sv->diem = p->diem;
	
	bucketSV[b] = p->next;
	delete p;
	return sv;
}
HashNodeSV* DeleteAfter(HashNodeSV* p)
{
	HashNodeSV* q;
	HashNodeSV* sv;
	if (p == NULL || p->next == NULL)
	{
		cout << "Không xóa node được\n";
		return 0;
	}
	q = p->next;
	
	strcpy(sv->maSV, q->maSV);
	strcpy(sv->hoTen, q->hoTen);
	sv->namSinh = q->namSinh;
	sv->diem = q->diem;

	p->next = q->next;
	delete q;
	return sv;
}
