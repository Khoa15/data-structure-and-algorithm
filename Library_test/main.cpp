#include <bits/stdc++.h>
using namespace std;

struct Node{
    int val;
    Node* Left;
    Node* Right;
    Node() : val(0), Left(NULL), Right(NULL) {}
    Node(int x) : val(x), Left(NULL), Right(NULL) {}
    ~Node(){
        delete this;
    }
};

struct Tree{
    Node* Root;

    Tree() : Root(NULL) {}
    Tree(Node* root) : Root(root) {}

    int height(Node* root){
        if(root == NULL) return 0;
        return max(height(root->Left), height(root->Right))  + 1;
    }

    void insertNode(Node* p){
        if(p == NULL) return;
        if(Root == NULL){
            Root = p;
            return;
        }
        Node* tmp = Root;
        while(tmp != NULL){
            if(tmp->val == p->val){
                return;
            }
            if(tmp->val > p->val){
                // Left
                if(tmp->Left == NULL){
                    tmp->Left = p;
                    return;
                }
                tmp = tmp->Left;
            }else{
                if(tmp->Right == NULL){
                    tmp->Right = p;
                    return;
                }
                tmp = tmp->Right;
            }
        }
    }

    void traverseNLR(Node* root){
        if(root == NULL) return;
        cout << root->val << "\t";
        traverseNLR(root->Left);
        traverseNLR(root->Right);
    }

    int balFactor(Node* root){
        if(root == NULL) return 0;
        return height(root->Left) - height(root->Right);
    }

    void rotateRight(Node* root){
        if(root == NULL) return;
        Node* q = root,
            *p = q->Left;
        if(p == NULL) return;
        q->Left = p->Right;
        p->Right = q;
        Root = p;
    }

    void rotateLeft(Node* root){
        if(root == NULL) return;
        Node *p = root,
            *q = root->Right;
        if(q == NULL) return;
        p->Right = q->Left;
        q->Left = p;
        Root = q;
    }

    void AVL(Node* root){
        if(root == NULL) return;
        bool flag = false;
        while(1){
            if(balFactor(root) > 1) {
                rotateRight(root);
                flag = true;
            }else if(balFactor(root) < -1 ){
                rotateLeft(root);
                flag = true;
            }else{
                break;
            }
        }
        if(flag == true){
            AVL(this->Root->Left);
            AVL(this->Root->Right);
        }else{
            AVL(root->Left);
            AVL(root->Right);
        }
    }
};

int main(){
    Tree* tree = new Tree();
    tree->insertNode(new Node(32));
    tree->insertNode(new Node(14));
    tree->insertNode(new Node(13));
    tree->insertNode(new Node(19));
    tree->insertNode(new Node(11));
    tree->insertNode(new Node(52));
    tree->insertNode(new Node(62));
    tree->insertNode(new Node(12));

    /*
         9
        / \
        5 10
       / 
      3  
       \
       4
    */
    cout << 
    tree->height(tree->Root->Left->Left->Left) << " " << 
    tree->height(tree->Root->Left->Left->Right) << endl;
    cout << endl;
    tree->traverseNLR(tree->Root);
    cout << endl;
    tree->AVL(tree->Root);
    tree->traverseNLR(tree->Root);
    cout << endl;
    return 0;
}