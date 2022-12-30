#define KEYSIZESV 100

struct HashNodeSV
{
	char maSV [11];
	char hoTen[50];
	int namSinh;
	int diem;//key

	HashNodeSV* next;
	HashNodeSV();
};
HashNodeSV* bucketSV[KEYSIZESV];

int HashFunctionSV(int key);
void InitBucketSV();
void Push(int b, HashNodeSV sv);
HashNodeSV* createHashNodeSV(HashNodeSV sv);
void showHashNodeSV(HashNodeSV* p);
void InsertAfter(HashNodeSV* p, HashNodeSV sv);
void Place(int b, HashNodeSV sv);
int IsEmptyBucketSV(int b);
void FreeNode(HashNodeSV* p);
HashNodeSV* Pop(int b);
HashNodeSV* DeleteAfter(HashNodeSV* p);
