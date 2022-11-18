#if __WIN32
#include <conio.h>
#endif
#include <iostream>
#include <stdlib.h>
#include <string>
#include "Lib/BTree.h"
#include "Lib/IntNumber.h"
#include "Fraction.h"
#include <queue>
using namespace std;


int countValueLargerXInBTree(Node<int> *root, int x){
    if(root == NULL) return 0;
    int countLeft = countValueLargerXInBTree(root->getPrev(), x),
        countRight = countValueLargerXInBTree(root->getNext(), x);
    return ((root->getInfo() > x) ? 1 : 0) + countLeft + countRight;
}

int countValueSmallerXInBTree(Node<int> *root, int x){
    if(root == NULL) return 0;
    int countLeft = countValueSmallerXInBTree(root->getPrev(), x),
        countRight = countValueSmallerXInBTree(root->getNext(), x);
    return ((root->getInfo() < x) ? 1 : 0) + countLeft + countRight;
}

int countValueXInRangeInBTree(Node<int> *root, int x, int y){
    if(root == NULL) return 0;
    int countLeft = countValueXInRangeInBTree(root->getPrev(), x, y),
        countRight = countValueXInRangeInBTree(root->getNext(), x, y);
    return ((root->getInfo() >= x && root->getInfo() <= y) ? 1 : 0) + countLeft + countRight;
}

int countTNodeIsPrime(Node<int> *root){
    if(root == NULL) return 0;
    int countLeft = countTNodeIsPrime(root->getPrev()),
        countRight = countTNodeIsPrime(root->getNext());
    return ((isPrime(root->getInfo()) == true) ? 1 : 0) + countLeft + countRight;
}

int countTNodeIsAbundant(Node<int> *root){
    if(root == NULL) return 0;
    int countLeft = countTNodeIsAbundant(root->getPrev()),
        countRight = countTNodeIsAbundant(root->getNext());
    return ((isAbundant(root->getInfo()) == true) ? 1 : 0) + countLeft + countRight;
}

bool getInputX(int &x){
    cin >> x;
    return true;
}

void Menu(int option){
    switch(option){
        case 0:
            cout
                << "1. Bai 1" << endl
                << "2. Bai 2" << endl
                << "3. Bai 3" << endl
                << "4. Bai 4" << endl;
            break;
        case 3:
            cout
                << "===Bai 3===" << endl
                << "a. Viet ham xuat cac so hoan thien" << endl
                << "b. Viet ham xuat cac nut tren tang thu k" << endl
                << "c. Viet ham xuat tat ca cac nut tren cay theo thu tu tu tang 0 den tang h - 1" << endl
                << "d. Dem so luong nut la ma thong tin tai nut do la gia tri chan" << endl
                << "e. Dem so luong nut co dung 1 con ma thong tin tai nut do la so nguyen to" << endl
                << "f. Dem so luong nut co dung 2 con ma thong tin tai nut do la so chinh phuong" << endl
                << "g. Dem so luong nut nam o tang thap hon tang thu k cua cay" << endl
                << "h. Dem so luong nut nam o tang cao hon tang thu k cua cay" << endl
                << "i. Tinh tong cac nut le" << endl
                << "j. Tinh tong cac nut la ma thong tin nut do la gia tri chan" << endl
                << "k. Tinh tong cac nut co dung 1 con ma thong tin tai nut do la so nguyen to" << endl
                << "l. Tinh tong cac nut co dung 2 con ma thong tin tai nut do la so chinh phuong" << endl
                << "m. Kiem tra cay nhi phan T co phai la cay  nhi phan tim kiem hay khong" << endl
                << "n. Kiem tra cay nhi phan T co phia cay tim kime hay khong" << endl
                << "o. Kiem tra cay nhi phan T co co phai la cay nhi phan can bang hoan toan hay kgon" << endl;
            break;
        case 2:
            cout 
                << "===Bai 2===" << endl
                << "a. Tao cay" << endl
                << "b. Duyet cay" << endl
                << "c. Them 1 phan so" << endl
                << "d. Tim kiem 1 phan so" << endl
                << "e. Xoa mot phan so" << endl
                << "f. Xoa nhung phan so>2" << endl
                << "g. Xoa nhung phan so co mau so la so nguyen to" << endl
                << "h. Tinh tong cac phan so" << endl
                << "i. Tim phan so nho nhat" << endl
                << "j. Tim phan so lon nhat" << endl
                << "k. Liet ke phan so co tu lon hon mau" << endl
                << "l. Liet ke cac phan so co tu nho hon mau" << endl
                << "m. Liet ke cac phan so co tu va mau dong thoi la so nguyen to" << endl
                << "o. Dem so luong phan so o muc k" << endl
                << "p. Tinh tong cac phan so o muc k" << endl
                << "q. Dem co bao nhieu phan so co ca tu so va mau so deu la cac so nguyen to" << endl
                << "r. Xoa toan bo" << endl;
            break;
        case 1:
            cout 
                << "===Bai 1===" << endl
                << "a. Tao cay" << endl
                << "b. Duyet cay: NLR, LNR, LRN, NRL, RNL, RLN" << endl
                << "c. Duyet cay theo chieu rong NLR, NRL." << endl
                << "d. Duyet cay theo chieu sau: NLR, LNR, LRN, NRL, RNL, RLN" << endl
                << "e. Them 1 nut co gia tri x." << endl
                << "f. Tim kiem 1 nut co gia tri x." << endl
                << "g. Xoa nut co gia tri x." << endl
                << "h. Xuat cac phan tu theo chieu giam dan." << endl
                << "i. Dem so gia tri lon hon x, nho hon x, co gia tri trong doan [x, y]." << endl
                << "j. Tim nut co gia tri lon nhat, nho nhat cua cay." << endl
                << "k. Xuat ra noi dung cac nut, la o muc k/ noi dung cac nut chi co 1 con o muc k." << endl
                << "l. Dem so nut, nut la, nut chi co 1 con o muc k." << endl
                << "m. Tinh tong gia tri cac nut duong/ gia tri cac nut am." << endl
                << "n. Tim phan tu co khoang cach ve gia tri gan nhat voi phan tu x." << endl
                << "o. Tim phan tu co khoang cach ve gia tri xa nhat voi phan tu x." << endl
                << "p. Dem so nut cua cay(de quy/ khu de quy)" << endl
                << "q. Dem so nut la so nguyen to, la so chinh phuong, la so hoan thien, la so thinh vuong, la so yeu cua cay." << endl
                << "r. Tinh tong gia tri cac nut cua cay (de quy/ khu de quy)." << endl
                << "s. Tinh tong gia tri cac nut la so nguyen to, la so chinh phuong, la so hoan thien, la so thinh vuong, la so yeu cua cay." << endl
                << "t. Xoa toan bo cay." << endl;
            break;
    }
    cout << "Choose your option: ";
}
void Bai1();
void Bai2();
void Bai3();
void clearScreen(){
    // #if _WIN32
    // system("cls");
    // #else
    // system("clear");
    // #endif
}
void stopScreen(){
    #if _WIN32
    getch();
    #endif
}

int main(){
    int option = 1;

    while(option != 0){
        clearScreen();
        Menu(option);
        switch(option){
            case 1:
                Bai1();
                break;
            case 2:
                Bai2();
                break;
            case 3:
                Bai3();
                break;
        }
    }

    return 0;
}

void Bai1(){

    char option;
    BTree<int> bTree;
    Node<int>   *NodeX = NULL,
                *NodeY = NULL;
    int X, Y;
    char filename[50];
    bTree.init(NULL);
    while(1){
        clearScreen();
        Menu(1);
        cin >> option;
        cin.ignore();
        cout << "Your's option: " << option << endl;
        switch (option)
        {
        case '0':
            return;
            break;
        case 'a':
            cout << "1. Tu file" << endl
                << "2. Tu ban phim" << endl
                << "3. Random" << endl
                << "Choose your option: ";
            cin >> X;
            switch(X){
                case 1:
                    cin.getline(filename, 50);
                    bTree.createBSTreeNumberFromFile(filename);
                    break;
                case 2:
                    bTree.createBTreeFromKeyboard();
                    break;
                case 3:
                    bTree.createRandomBTree();
                    break;
            }
            break;
        case 'b':
            cout << "LNR: ";
            bTree.traverseLNR(bTree.getRoot());
            cout << endl << "LRN: ";
            bTree.traverseLRN(bTree.getRoot());
            cout << endl << "NLR: ";
            bTree.traverseNLR(bTree.getRoot());
            cout << endl << "NRL: ";
            bTree.traverseNRL(bTree.getRoot());
            cout << endl << "RLN: ";
            bTree.traverseRLN(bTree.getRoot());
            cout << endl << "RLN: ";
            bTree.traverseRNL(bTree.getRoot());
            break;
        case 'c':
            bTree.traverseBreadthNLR(bTree.getRoot());
            break;
        case 'd':
            bTree.traverseDepthNLR(bTree.getRoot());
            break;
        case 'e':
            getInputX(X);
            bTree.insertTNode(createNode(X));
            break;
        case 'f':
            cout << "Tim kiem x: " << endl;
            cout << "Nhap x: ";
            getInputX(X);
            bTree.findTNode(X)->showInfo();
            break;
        case 'g':
            cout << "Xoa nut" << endl;
            cout << "Nhap x: ";
            getInputX(X);
            if(bTree.deleteTNode(X, bTree.getRoot())){
                cout << "Successfully" << endl;
            }else{
                cout << "Error!" << endl;
            }
            break;
        case 'h':
            cout << "Xuat cac phan tu theo chieu giam dan" << endl;
            bTree.traverseRNL(bTree.getRoot());
            cout << endl;
        case 'i':
            cout << "Dem so gia tri lon hon x, nho hon x, co gia tri trong doan [x, y]" << endl;
            cout << "Nhap x va y: ";
            getInputX(X);
            getInputX(Y);
            cout << "Gia tri lon hon x: " << countValueLargerXInBTree(bTree.getRoot(), X)
            << endl << "Gia tri nho hon x: " << countValueSmallerXInBTree(bTree.getRoot(), X)
            << endl << "Gia tri trong khoang [x, y]: " << countValueXInRangeInBTree(bTree.getRoot(), X, Y)
            << endl;
            break;
        case 'j':
            cout << "Gia tri lon nhat: ";
            NodeX = bTree.getRoot();
            while(NodeX->getPrev() != NULL && NodeX->getNext()){
                NodeX = NodeX->getNext();
            }
        case 'k':
            cout << "Xuat ra cac nut o muc k: " << endl;
            cout << "Nhap muc k: ";
            getInputX(X);
            bTree.showTNodeIsLeafOfLevelK(X, bTree.getRoot());
            cout << "So nut chi co 1 con o muc k: " << bTree.countTNodeOfLevelK(X, bTree.getRoot()) << endl;
            break;
        case 'm':
            cout << "Tong gia tri nut duong: " << countValueLargerXInBTree(bTree.getRoot(), 0)
            << endl << "Tong gia tri nut am: " << countValueSmallerXInBTree(bTree.getRoot(), 0);
            break;
        case 'n':
            cout << "Tim phan tu co gia tri gan nhat voi phan tu x" << endl;
            cout << "Nhập x: ";
            getInputX(X);
            bTree.findTNodeMinDistanceX(X);
            break;
        case 'o':
            cout << "Tim phan tu co gia tri xa nhat voi phan tu x" << endl;
            cout << "Nhập x: ";
            getInputX(X);
            bTree.findTNodeMaxDistanceX(X);
            break;
        case 'p':
            cout << "Dem so nut cua cay" << endl;
            cout << "So nut: " << 
            bTree.countTNode(bTree.getRoot())
            << endl;
            break;
        case 'q':
            cout << "Dem so nut la so nguyen to, la so chinh phuong, la so hoan thien" << endl;
            cout << "So nguyen to: " << countTNodeIsPrime(bTree.getRoot());
            cout << endl << "So hoan thien: " << countTNodeIsAbundant(bTree.getRoot());
            break;
        default:
            cout << "Error option!" << endl;
            break;
        }
        stopScreen();
    }
    bTree.deleteTree(bTree.getRoot());
}

void Bai2(){
    char option;
    int k = 0;
    BTree<Fraction> bTree;
    bTree.init(NULL);
    Node<Fraction>  *NodeX = NULL,
                    *NodeY = NULL;
    while(1){
        Menu(2);
        cin >> option;
        switch (option)
        {
        case '0':
            return;
            break;
        case 'a':
            // bTree.createRandomBTree();
            break;
        case 'b':
            cout << "LNR: ";
            traverseTreeFracLNR(bTree.getRoot());
            cout << endl << "LRN: ";
            traverseTreeFracLRN(bTree.getRoot());
            cout << endl << "NLR: ";
            traverseTreeFracNLR(bTree.getRoot());
            cout << endl << "NRL: ";
            traverseTreeFracNRL(bTree.getRoot());
            cout << endl << "RLN: ";
            traverseTreeFracRLN(bTree.getRoot());
            cout << endl << "RLN: ";
            traverseTreeFracRNL(bTree.getRoot());
            break;
        case 'c':
            NodeX = new Node<Fraction>();
            if(NodeX != NULL){
                NodeX->getInfo().input();
                bTree.insertTNode(NodeX);
            }
            break;
        case 'd':
            NodeX = new Node<Fraction>();
            if(NodeX != NULL){
                NodeX->getInfo().input();
                cout << (bTree.findTNode(NodeX) == true) ? "Yes" : "No" << endl;
                delete NodeX;
            }
            break;
        case 'e':
            cout << "Processing..." << endl;
            NodeX = new Node<Fraction>();
            if(NodeX != NULL){
                NodeX->getInfo().input();
                cout << (bTree.deleteTNode((bTree.findTNode(NodeX)) == true) ?"Successfully!" : "Error!!" << endl;
                delete NodeX;
            }

            cout << "Successfully" << endl;
            break;

        case 'f':
            NodeX = new Node<Fraction>(2);
            while(1){
                NodeY = findTNodeLargerThanX(bTree.getRoot(), NodeX->getInfo());
                if(NodeY == NULL) break;
                bTree.deleteTNode(NodeY->getInfo(), bTree.getRoot());
            }
            delete NodeX;
        case 'g':
            cout << "Progessing..." << endl;
            while(1){
                NodeX = findTNodeHasDenominatorIsPrime(bTree.getRoot());
                if(NodeX == NULL) break;
                bTree.deleteTNode(NodeX->getinfo(), bTree.getRoot());
            }
            cout << "Successfully" << endl;
            break;
        case 'h':
            cout << "Tong phan so: " << totalFraction(bTree.getRoot()) << endl;
            break;
        case 'i':
            cout << "Tim phan so nho nhat: " << endl;
            findMinFraction(bTree.getRoot())->getInfo().show();
            cout << endl;
        case 'j':
            cout << "Tim phan so lon nhat:  " << endl;
            findMaxFraction(bTree.getRoot())->getInfo().show();
            cout << endl;
            break;
        case 'k':
            cout << "Cac phan so co tu so lon hon mau so: " << endl;
            showNumeratorLargerThanDenominator(bTree.getRoot());
            cout << endl;
            break;
        case 'l':
            cout << "Cac phan so co tu so nho hon mau so: " << endl;
            showNumeratorSmallerThanDenominator(bTree.getRoot());
            cout << endl;
            break;
        case 'm':
            cout << "Liet ke cac phan so co tu so va mau so dong thoi la so nguyen to: "<< endl;
            showFractionHasNumeAndDenoIsPrime(bTree.getRoot());
            cout << endl;
            break;
        case 'n':
            do{
                cout << "Nhap k: ";
                cin >> k;
            }while(k < 0);
            cout << "Liet ke cac phan so o muc k" << endl ;
            showFractionAtK(bTree.getRoot(), k);
            break;

        case 'o':
            do{
                cout << "Nhap k: ";
                cin >> k;
            }while(k < 0);
            cout << "Dem so luong phan so o muc k" << countFractionAtK(bTree.getRoot(), k) << endl;
            break;
        case 'p':
            cout << "Tinh tong cac phan so co ca tu va mau deu la so nguyen to" << countFracHasNumAndDenoisPrime(bTree.getRoot(), k) << endl;
            break;
        case 'r':
            bTree.deleteTree(bTree.getRoot());
        default:
            break;
        }
    }
}

void Bai3(){
    BTree<int> bTree(NULL);
    bTree.createRandomBTree();
    char option;
    int k = 0, c = 0;
    queue<Node<int> *> q;
    Node<int> *NodeX = NULL,
            *NodeY = NULL;
    while(1){
        Menu(3);
        cin >> option;
        switch (option)
        {
        case '0':
            return;
            break;
        case 'a':
            cin >> k;
            q.push(bTree.getRoot());
            while(q.empty() == false){
                NodeX = q.front();
                q.pop();
                NodeX->showInfo();

                if(NodeX->getNext() != NULL) q.push(NodeX->getNext());
                if(NodeX->getPrev() != NULL) q.push(NodeX->getPrev());
            }
            break;
        case 'b':
            do{
                cout << "Nhap k: ";
                cin >> k;
            }while(k < 0);
            bTree.showTNodeIsLeafOfLevelK(k, bTree.getRoot());
            cout << endl;
            break;
        case 'c':
            bTree.showTNodeAtLevelK(bTree.getHeight(bTree.getRoot()), bTree.getRoot());
            cout << endl;
            break;
        case 'd':
            q.push(bTree.getRoot());
            k = 0;
            while(q.empty() == false){
                NodeX = q.front();
                q.pop();
                if(NodeX->getInfo() % 2== 0 && NodeX->getNext() == NULL && NodeX->getPrev() == NULL) k += 1;
                if(NodeX->getNext() != NULL) q.push(NodeX->getNext());
                if(NodeX->getPrev() != NULL) q.push(NodeX->getPrev());
            }
            cout << "So luong nut la co gia tri chan: " << k << endl;
            break;
        case 'e':
            q.push(bTree.getRoot());
            k = 0;
            while(q.empty() == false){
                NodeX = q.front();
                q.pop();
                if(isPrime(NodeX->getInfo()) == true && (NodeX->getNext() == NULL || NodeX->getPrev() == NULL)) k += 1;
                if(NodeX->getNext() != NULL) q.push(NodeX->getNext());
                if(NodeX->getPrev() != NULL) q.push(NodeX->getPrev());
            }
            cout << "So nut co 1 con ma la gia tri nguyen to: " << k;
            break;
        case 'f':
            q.push(bTree.getRoot());
            k = 0;
            while(q.empty() == false){
                NodeX = q.front();
                q.pop();
                if(isSquare(NodeX->getInfo()) == true && NodeX->getNext() != NULL && NodeX->getPrev() != NULL) k += 1;
                if(NodeX->getNext() != NULL) q.push(NodeX->getNext());
                if(NodeX->getPrev() != NULL) q.push(NodeX->getPrev());
            }
            cout << "So luong nut co 2 con ma thong tin tai nut do la so chinh phuong: " << k << endl;
            break;
        case 'g':
            q.push(bTree.getRoot());
            do{
                cout << "Nhap k: ";
                cin >> k;
            }while(k < 0);
            c = 0;
            while(q.empty() == false){
                NodeX = q.front();
                q.pop();
                if(k >= 0){
                    c += 1;
                }
                k -= 1;
                if(isSquare(NodeX->getInfo()) == true && NodeX->getNext() != NULL && NodeX->getPrev() != NULL) k += 1;
                if(NodeX->getNext() != NULL) q.push(NodeX->getNext());
                if(NodeX->getPrev() != NULL) q.push(NodeX->getPrev());
            }
            cout << "Dem so luong nut nam o tang thap hon tang thu k: " << c;
            break;
        case 'h':
            q.push(bTree.getRoot());
            do{
                cout << "Nhap k: ";
                cin >> k;
            }while(k < 0);
            c = 0;
            while(q.empty() == false){
                NodeX = q.front();
                q.pop();
                if(k < 0){
                    c += 1;
                }
                k -= 1;
                if(isSquare(NodeX->getInfo()) == true && NodeX->getNext() != NULL && NodeX->getPrev() != NULL) k += 1;
                if(NodeX->getNext() != NULL) q.push(NodeX->getNext());
                if(NodeX->getPrev() != NULL) q.push(NodeX->getPrev());
            }
            cout << "Dem so luong nut nam o tang cao hon tang thu k: " << c;
            break;
        case 'i':

            q.push(bTree.getRoot());
            c = 0;
            while(q.empty() == false){
                NodeX = q.front();
                q.pop();
                if(NodeX->getInfo() % 2 != 0){
                    c += NodeX->getInfo();
                }
                if(isSquare(NodeX->getInfo()) == true && NodeX->getNext() != NULL && NodeX->getPrev() != NULL) k += 1;
                if(NodeX->getNext() != NULL) q.push(NodeX->getNext());
                if(NodeX->getPrev() != NULL) q.push(NodeX->getPrev());
            }
            cout << "Tong cac nut le: " << c; 
            break;
        case 'j':
            q.push(bTree.getRoot());
            c = 0;
            while(q.empty() == false){
                NodeX = q.front();
                q.pop();
                if(NodeX->getInfo() % 2 == 0){
                    c += NodeX->getInfo();
                }
                if(isSquare(NodeX->getInfo()) == true && NodeX->getNext() != NULL && NodeX->getPrev() != NULL) k += 1;
                if(NodeX->getNext() != NULL) q.push(NodeX->getNext());
                if(NodeX->getPrev() != NULL) q.push(NodeX->getPrev());
            }
            cout << "Tinh tong cac nut la ma thong tin tai nut do la gia tri chan: ";
            break;
        case 'k':
            q.push(bTree.getRoot());
            c = 0;
            while(q.empty() == false){
                NodeX = q.front();
                q.pop();
                if(isPrime(NodeX->getInfo()) == true){
                    if(
                        (NodeX->getNext() != NULL && NodeX->getPrev() == NULL)
                        ||
                        (NodeX->getNext() == NULL && NodeX->getPrev() != NULL)){
                        c += NodeX->getInfo();
                    }
                }
                if(isSquare(NodeX->getInfo()) == true && NodeX->getNext() != NULL && NodeX->getPrev() != NULL) k += 1;
                if(NodeX->getNext() != NULL) q.push(NodeX->getNext());
                if(NodeX->getPrev() != NULL) q.push(NodeX->getPrev());
            }
            cout << "Tong cac nut co 1 con la so nguyen to: " << c;
            break;
        case 'l':
            q.push(bTree.getRoot());
            c = 0;
            while(q.empty() == false){
                NodeX = q.front();
                q.pop();
                if(isSquare(NodeX->getInfo()) == true){
                    if(NodeX->getNext() != NULL && NodeX->getPrev() != NULL){
                        c += NodeX->getInfo();
                    }
                }
                if(isSquare(NodeX->getInfo()) == true && NodeX->getNext() != NULL && NodeX->getPrev() != NULL) k += 1;
                if(NodeX->getNext() != NULL) q.push(NodeX->getNext());
                if(NodeX->getPrev() != NULL) q.push(NodeX->getPrev());
            }
            cout << "Tong cac nut co dung 2 con ma nut do la so chinh phuong: " << c << endl;
            break;
        case 'm':
            cout << (bTree.isBTree(bTree.getRoot()) == true) ? "La cay nhi phan tim kiem" : "Khong phai la cay nhi phan tim kiem";
            break;
        case 'n':
            cout << ((bTree.isAVL(bTree.getRoot()) == true) ? "is AVL" : "isn't AVL") << endl;
        default:
            break;
        }
    }
}





