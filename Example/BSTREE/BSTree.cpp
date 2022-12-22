#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <stack>
#include "BSTree.h"

using namespace std;

TNode* createTNode(ItemType x)
{
	TNode* p = new TNode;
	if (p == NULL)
	{
		cout << "Không đủ bộ nhớ cấp phát!!!";
		return NULL;
	}
	p->Info = x;
	p->Left = NULL;
	p->Right = NULL;
	return p;
}
void showTNode(TNode* p)
{
	cout << p->Info << '\t';
}
void deleteTNode(TNode*& p)
{
	if (p == NULL)
		return;
	delete p;
}
void initBSTree(BSTree& bst)
{
	bst.Root = NULL;
}
int isEmtpy(BSTree bst)
{
	return bst.Root == NULL;
}
int insertTNode(TNode*& root, TNode* p)
{
	if (p == NULL)
		return 0;
	if (root == NULL)
	{
		root = p;
		return 1;
	}
	if (root->Info == p->Info)
		return 0;
	if (p->Info < root->Info)
		insertTNode(root->Left, p);
	else
		insertTNode(root->Right, p);
	return 1;
}
void createBSTree_FromArray(BSTree& bt, ItemType a[], int na)
{
	for (int i = 0; i < na; i++)
		insertTNode(bt.Root, createTNode(a[i]));
}
void createBSTree_FromFile(BSTree& bst, const char* fileName)
{
	FILE* f;
	f = fopen(fileName, "rt");
	if (!f)
		return;
	int n;
	fscanf (f, "%d", &n);
	ItemType x;
	initBSTree(bst);
	for (int i = 1; i <= n; i++)
	{
		fscanf(f, "%d", &x);
		TNode* p = createTNode(x);
		insertTNode(bst.Root, p);
	}
	fclose(f);
}
void traverseNLR(TNode* root)
{
	if (root == NULL)
		return;
	showTNode(root);
	traverseNLR(root->Left);
	traverseNLR(root->Right);
}
void traverseLNR(TNode* root)
{
	if (root == NULL)
		return;
	
	traverseLNR(root->Left);
	showTNode(root);
	traverseLNR(root->Right);
}
void traverseLRN(TNode* root)
{
	if (root == NULL)
		return;
	traverseLRN(root->Left);
	traverseLRN(root->Right);
	showTNode(root);
}
void traverseRNL(TNode* root)
{
	if (root == NULL)
		return;
	
	traverseRNL(root->Right);
	showTNode(root);
	traverseRNL(root->Left);
}
TNode* findTNode(TNode* root, ItemType x)
{
	if (root == NULL)
		return NULL;
	if (root->Info == x)
		return root;
	else if (x < root->Info)
		return findTNode(root->Left, x);
	else
		return findTNode(root->Right, x);
}
TNode* findTNodeReplace(TNode*& p)
{
	////Hàm tìm nút q thế mạng cho nút p, f là nút cha của nút q.
	TNode* f = p;
	TNode* q = p->Right;
	while (q->Left != NULL)
	{
		f = q;//lưu nút cha của q
		q = q->Left;//q qua bên trái
	}
	p->Info = q->Info;
	//Tìm được phần tử thế mạng cho p là q
	if (f == p)//Nếu cha của q là p
		f->Right = q->Right;
	else
		f->Left = q->Right;
	return q;//trả về nút q là nút thế mạng cho p
}
int deleteTNodeX(TNode*& root, ItemType x)
{
	if (root == NULL)
		return 0;
	if (root->Info > x)
		return deleteTNodeX(root->Left, x);
	else if (root->Info < x)
		return deleteTNodeX(root->Right, x);
	else
	{
		//root->Info = x, tìm nút thế mạng cho root
		TNode* p = root;
		if (root->Left == NULL)//khi cây con không có nhánh trái
		{
			root = root->Right;
			delete p;
		}
		else if (root->Right == NULL)//khi cây con không có nhánh phải
		{
			root = root->Left;
			delete p;
		}
		else/* khi cây con có cả 2 nhánh, chọn min của nhánh phải để thế mạng */
		{
			TNode* q = findTNodeReplace(p);
			delete q;//Xóa nút q là nút thế mạng cho p
		}
		return 1;
	}
}
void deleteTree(TNode*& root)
{
	if (!root)
		return;

	deleteTree(root->Left);
	deleteTree(root->Right);
	delete root;
	root = NULL;/////
}
int maxTNode(TNode* root)
{
	TNode* p = root;
	while (p->Right != NULL)
		p = p->Right;
	return p->Info;
}
void showTNodeOfLevelK(TNode* root, int k)
{
	if (root == NULL)
		return;
	if (k == 0)
		cout << root->Info << '\t';
	k--;
	showTNodeOfLevelK(root->Left, k);
	showTNodeOfLevelK(root->Right, k);
}
void showTNodeIsLeafOfLevelK(TNode* root, int k)
{
	if (root == NULL)
		return;
	if ((k == 0) && (root->Left == NULL) && (root->Right == NULL))
		cout << root->Info << '\t';
	k--;
	showTNodeIsLeafOfLevelK(root->Left, k);
	showTNodeIsLeafOfLevelK(root->Right, k);
}
void showTNodeHasOneChild(TNode* root)
{
	if (root == NULL)
		return;
	if (((root->Left != NULL) && (root->Right == NULL)) || ((root->Left == NULL) && (root->Right != NULL)))
		cout << root->Info << '\t';

	showTNodeHasOneChild(root->Left);
	showTNodeHasOneChild(root->Right);
}
int countTNodeOfLevelK(TNode* root, int k)
{
	if (root == NULL)
		return 0;
	if (k == 0)
		return 1;
	k--;
	int cnl = countTNodeOfLevelK(root->Left, k);
	int cnr = countTNodeOfLevelK(root->Right, k);
	return cnl + cnr;
}
int countTNodeIsLeafOfLevelK(TNode* root, int k)
{
	if (root == NULL)
		return 0;
	if ((k == 0) && (root->Left == NULL) && (root->Right == NULL))
		return 1;
	k--;
	countTNodeIsLeafOfLevelK(root->Left, k);
	countTNodeIsLeafOfLevelK(root->Right, k);
}
int countTNodeHasOneChildOfLevelK(TNode* root, int k)
{
	if (root == NULL)
		return 0;
	int n = 0;
	if ((k == 0) && ((root->Left != NULL) && (root->Right == NULL)) || ((root->Left == NULL) && (root->Right != NULL)))
		n++;
	k--;
	int cnl = countTNodeHasOneChildOfLevelK(root->Left, k);
	int cnr = countTNodeHasOneChildOfLevelK(root->Right, k);
	return n + cnl + cnr;
}
int minDistance(TNode* root, ItemType x)
{
	if (root == NULL)
		return -1;
	/////////kiểm tra phần tử x có trong cây ko?
	TNode* p = findTNode(root, x);
	if (p == NULL)
	{
		cout << "Không có phần tử x trong cây\n";
		return -1;
	}

	int min = root->Info;
	int mindis = abs(x - min);
	while (root != NULL)
	{
		//nếu xét khoảng cách nhỏ nhất từ gốc tới x
		if (root->Info == x)
			//return x;//file ghi
			break;
		if (mindis > abs(x - root->Info))
			{
				min = root->Info;
				mindis = abs(x - min);
			}

			if (x > root->Info)
				root = root->Right;
			else
				root = root->Left;
		
		//Nếu xét khoảng cách tất cả nút có đường đi tới x
		/*if (x != root->Info)
		{
			if (mindis > abs(x - root->Info))
			{
				min = root->Info;
				mindis = abs(x - min);
			}
		
			if (x > root->Info)
				root = root->Right;
			else
				root = root->Left;
		}
		else
		{
			if (root->Left == NULL)
				root = root->Right;
			else if (root->Right == NULL)
				root = root->Left;
			else
			{
				if (abs(x - root->Left->Info) < abs(x - root->Right->Info))
					root = root->Left;
				else
					root = root->Right;
			}
		}*/
	}
	return min;
}
int maxDistance(TNode* root, ItemType x)
{
	if (root == NULL)
		return -1;
	TNode* minLeft = root;
	while (minLeft->Left != NULL)
		minLeft = minLeft->Left;
	TNode* maxRight = root;
	while (maxRight->Right != NULL)
		maxRight = maxRight->Right;
	int dis1 = abs(x - minLeft->Info);
	int dis2 = abs(x - maxRight->Info);
	if (dis1 > dis2)
		return minLeft->Info;
	else
		return maxRight->Info;
}
void traverseBreadthNLR(TNode* root)
{
	if (root == NULL)
		return;
	
	queue <TNode*> q;
	q.push(root);

	while (!q.empty())
	{
		TNode* p;
		p = q.front();
		q.pop();
		showTNode(p);
		if (p->Left != NULL)
			q.push(p->Left);
		if (p->Right != NULL)
			q.push(p->Right);
	}
}
void traverseDepthNLR(TNode* root)
{
	if (root == NULL)
		return;
	stack <TNode*> s;
	s.push(root);

	while (!s.empty())
	{
		TNode* p;
		p = s.top();
		s.pop();
		showTNode(p);

		if (p->Right != NULL)//do Stack vào trước ra sau nên thực hiện bên phải trước
			s.push(p->Right);
		if (p->Left != NULL)
			s.push(p->Left);
	}
}
int countTNode(TNode* root)
{
	if (!root)
		return 0;
	int nl = countTNode(root->Left);
	int nr = countTNode(root->Right);
	return (1 + nl + nr);
}
int countTNodeNoRecursive(TNode* root)
{
	if (root == NULL)
		return 0;

	queue <TNode*> q;
	int n = 0;
	q.push(root);

	while (!q.empty())
	{
		TNode* p;
		p = q.front();
		q.pop();
		n++;
		if (p->Left != NULL)
			q.push(p->Left);
		if (p->Right != NULL)
			q.push(p->Right);
	}
	return n;
}
int countTNodeGreaterthanX(TNode* root, ItemType x)
{
	if (root == NULL)
		return 0;
	int n = 0;
	if (root->Info > x)
		n++;
	int cnl = countTNodeGreaterthanX(root->Left, x);
	int cnr = countTNodeGreaterthanX(root->Right, x);
	return n + cnl + cnr;
}
int countTNodeLessthanX(TNode* root, ItemType x)
{
	if (root == NULL)
		return 0;
	int n = 0;
	if (root->Info <  x)
		n++;
	int cnl = countTNodeLessthanX(root->Left, x);
	int cnr = countTNodeLessthanX(root->Right, x);
	return n + cnl + cnr;
}
int countTNodeInSegment(TNode* root, ItemType x, ItemType y)
{
	if (root == NULL)
		return 0;
	int n = 0;
	if ((root->Info >= x) && (root->Info <= y))
		n++;
	int cnl = countTNodeInSegment(root->Left, x, y);
	int cnr = countTNodeInSegment(root->Right, x, y);
	return n + cnl + cnr;
}
TNode* findMaxTNode(TNode* root)
{
	if (root == NULL)
		return NULL;
	TNode* p = root;
	while (p->Right != NULL)
		p = p->Right;
	return p;
}
TNode* findMinTNode(TNode* root)
{
	if (root == NULL)
		return NULL;
	TNode* p = root;
	while (p->Left != NULL)
		p = p->Left;
	return p;
}
int sumTNodePositive(TNode* root)
{
	if (root == NULL)
		return 0;
	int sum = 0;
	if (root->Info > 0)
		sum += root->Info;
	int sl = sumTNodePositive(root->Left);
	int sr = sumTNodePositive(root->Right);
	return sum + sl + sr;
}
int sumTNode(TNode* root)
{
	if (!root)
		return 0;

	int nl = sumTNode(root->Left);
	int nr = sumTNode(root->Right);
	return (root->Info + nl + nr);
}
int sumTNodeNoRecursive(TNode* root)
{
	if (root == NULL)
		return 0;

	queue <TNode*> q;
	int n = 0;
	q.push(root);

	while (!q.empty())
	{
		TNode* p;
		p = q.front();
		q.pop();
		n = n + p->Info;
		if (p->Left != NULL)
			q.push(p->Left);
		if (p->Right != NULL)
			q.push(p->Right);
	}
	return n;
}
bool laSoNguyenTo(int n)
{
	if (n < 2)
		return false;

	for (int i = 2; i <= sqrt((float)n); i++)
	{
		if (n % i == 0)
		{
			return false;
		}
	}
	return true;
}
bool laSoChinhPhuong(int n) {
	int i = 0;
	while (i * i <= n) {
		if (i * i == n) {
			return true;
		}
		++i;
	}
	return false;
}
bool laSoHoanHao(int n)
{
	int sum = 0;
	for (int i = 1;i <= n / 2;i++)
	{ //tạo vòng lặp for để tìm ước số của n
		if (n % i == 0)
			sum += i; //tổng các ước số của n
	}
	if (sum == n) return true;
	return false;
}
bool laSoThinhVuong(int n)
{
	int sum = 0;
	for (int i = 1;i <= n / 2;i++)
	{ //tạo vòng lặp for để tìm ước số của n
		if (n % i == 0)
			sum += i; //tổng các ước số của n
	}
	if (sum > n) return true;
	return false;
}
int sumTNodeNguyenTo(TNode* root)
{
	if (root == NULL)
		return 0;
	int sum = 0;
	if ( laSoNguyenTo(root->Info))
		sum += root->Info;
	int sl = sumTNodeNguyenTo(root->Left);
	int sr = sumTNodeNguyenTo(root->Right);
	return sum + sl + sr;
}
int sumTNodeChinhPhuong(TNode* root)
{
	if (root == NULL)
		return 0;
	int sum = 0;
	if (laSoChinhPhuong(root->Info))
		sum += root->Info;
	int sl = sumTNodeChinhPhuong(root->Left);
	int sr = sumTNodeChinhPhuong(root->Right);
	return sum + sl + sr;
}
int sumTNodeHoanHao(TNode* root)
{
	if (root == NULL)
		return 0;
	int sum = 0;
	if (laSoHoanHao(root->Info))
		sum += root->Info;
	int sl = sumTNodeHoanHao(root->Left);
	int sr = sumTNodeHoanHao(root->Right);
	return sum + sl + sr;
}
int sumTNodeThinhVuong(TNode* root)
{
	if (root == NULL)
		return 0;
	int sum = 0;
	if (laSoThinhVuong(root->Info))
		sum += root->Info;
	int sl = sumTNodeThinhVuong(root->Left);
	int sr = sumTNodeThinhVuong(root->Right);
	return sum + sl + sr;
}
int countTNodeNguyenTo(TNode* root)
{
	if (root == NULL)
		return 0;
	int count = 0;
	if (laSoNguyenTo(root->Info))
		count++;
	int sl = countTNodeNguyenTo(root->Left);
	int sr = countTNodeNguyenTo(root->Right);
	return count + sl + sr;
}
int countTNodeChinhPhuong(TNode* root)
{
	if (root == NULL)
		return 0;
	int count = 0;
	if (laSoChinhPhuong(root->Info))
		count ++;
	int sl = countTNodeChinhPhuong(root->Left);
	int sr = countTNodeChinhPhuong(root->Right);
	return count + sl + sr;
}
int countTNodeHoanHao(TNode* root)
{
	if (root == NULL)
		return 0;
	int count = 0;
	if (laSoHoanHao(root->Info))
		count ++;
	int sl = countTNodeHoanHao(root->Left);
	int sr = countTNodeHoanHao(root->Right);
	return count + sl + sr;
}
int countTNodeThinhVuong(TNode* root)
{
	if (root == NULL)
		return 0;
	int count = 0;
	if (laSoThinhVuong(root->Info))
		count ++;
	int sl = countTNodeThinhVuong(root->Left);
	int sr = countTNodeThinhVuong(root->Right);
	return count + sl + sr;
}
