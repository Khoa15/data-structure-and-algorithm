struct PNode
{
	int a;
	int n;
	PNode* next;
	PNode();
};
struct Polynomial
{
	PNode* head;
	PNode* tail;
};
PNode* createPNode(int a, int n);
void deletePNode(PNode*& p);
void showPNode(PNode* p);
void init(Polynomial& p);

void addTailPolynomial(Polynomial& poly, PNode* p);
void addAfterPNodePolynomial(Polynomial& poly, PNode* q, PNode* p);
void traverse(Polynomial poly);
void SapXepTheoBacGiamDan(Polynomial poly);
void deleteTailPolynomial(Polynomial& poly);
void RutGonDaThuc(Polynomial &poly);
void deleteHeadPolynomial(Polynomial& poly);
void deleteTailPolynomial(Polynomial& poly);
void deleteMidPolynomial(Polynomial& poly, PNode* q);
void deletePolynomialHasBase(Polynomial& poly, int a);
PNode* searchPolynomial(Polynomial poly, int n);
void deletePolynomialHasExponent(Polynomial& poly, int n);
int value(PNode* p, int x);
int value(Polynomial poly, int x);
Polynomial Add(Polynomial poly1, Polynomial poly2);