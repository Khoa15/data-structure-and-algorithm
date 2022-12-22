typedef int ItemType;
struct TNode
{
	ItemType Info;
	TNode* Left;
	TNode* Right;
};

struct BSTree
{
	TNode* Root;
};

/////////
TNode* createTNode(ItemType x);
void showTNode(TNode* p);
void deleteTNode(TNode* &p);
void initBSTree(BSTree& bst);
int isEmtpy(BSTree bst);
int insertTNode(TNode*& root, TNode* p);
void createBSTree_FromArray(BSTree& bt, ItemType a[], int na);
void createBSTree_FromFile(BSTree& bst, const char* fileName);
void traverseNLR(TNode* root);
void traverseLNR(TNode* root);
void traverseLRN(TNode* root);
void traverseRNL(TNode* root);
TNode* findTNode(TNode* root, ItemType x);
TNode* findTNodeReplace(TNode*& p);
int deleteTNodeX(TNode*& root, ItemType x);
int maxTNode(TNode* root);
void showTNodeOfLevelK(TNode* root, int k);
void showTNodeIsLeafOfLevelK(TNode* root, int k);
void showTNodeHasOneChild(TNode* root);
int countTNode(TNode* root);
int countTNodeNoRecursive(TNode* root);
int countTNodeOfLevelK(TNode* root, int k);
int countTNodeIsLeafOfLevelK(TNode* root, int k);
int countTNodeHasOneChildOfLevelK(TNode* root, int k);
void deleteTree(TNode*& root);
int minDistance(TNode* root, ItemType x);
int maxDistance(TNode* root, ItemType x);
void traverseBreadthNLR(TNode* root);
void traverseDepthNLR(TNode* root);
int countTNodeEqualX(TNode* root, ItemType x);
int countTNodeGreaterthanX(TNode* root, ItemType x);
int countTNodeLessthanX(TNode* root, ItemType x);
int countTNodeInSegment(TNode* root, ItemType x, ItemType y);
TNode* findMaxTNode(TNode* root);
TNode* findMinTNode(TNode* root);
int sumTNodePositive(TNode* root);
int sumTNode(TNode* root);
int sumTNodeNoRecursive(TNode* root);
int sumTNodeNguyenTo(TNode* root);
int sumTNodeChinhPhuong(TNode* root);
int sumTNodeHoanHao(TNode* root);
int sumTNodeThinhVuong(TNode* root);

int countTNodeNguyenTo(TNode* root);
int countTNodeChinhPhuong(TNode* root);
int countTNodeHoanHao(TNode* root);
int countTNodeThinhVuong(TNode* root);