#define KEYSIZE 27

struct HashNode
{
	int key;
	HashNode* next;
	
	HashNode();
};
HashNode* bucket[KEYSIZE];

//////////
int HashFunction(int key);
void InitBucket();
void Push(int b, int x);
void InsertAfter(HashNode* p, int k);
void Place(int b, int k);
int IsEmptyBucket(int b);
void FreeNode(HashNode* p);
int Pop(int b);
int DeleteAfter(HashNode* p);
int Remove(int k);
void ClearBucket(int b);
void Clear();
void TraverseBucket(int b);
void Traverse();
HashNode* Search(int k);