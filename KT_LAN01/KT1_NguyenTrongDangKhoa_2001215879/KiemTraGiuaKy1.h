typedef int Data;
struct Node
{
    Data info;
    Node *next;
    Node();
};
struct SList
{
    Node *head;
    Node *tail;
    int length;
};
/////////////////////
Node *createNode(int x);
void deleteNode(Node *&p);
void showNode(Node *p);
void init(SList &l);
bool isEmpty(SList l);
void traverse(SList l);
void addHeadSList(SList &l, Node *p);
void addTailSList(SList &l, Node *p);
void addAfterNodeSList(SList &l, Node *q,
                       Node *p);
Node *searchSList(SList l, int x);
void createSList(SList &l);
void createAutoSList(SList &l);
void addBeforeNodeSList(SList &l, Node *q,
                        Node *p);
void createSList(SList &l, int n);
void deleteHeadSList(SList &l);
void deleteTailList(SList &l);
void deleteMidSList(SList &l, Node *q);
//////////////////////////////////////////////

struct SNode
{
    char info[2];
    SNode *next;

    SNode();
};
struct Stack
{
    SNode *top;
    Stack();
    void push(char info[2]);
    bool pop();
    int size();
};