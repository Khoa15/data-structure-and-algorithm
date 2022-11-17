#include <conio.h>
#include <iostream>
#include <stdlib.h>
#include <string>
#include "Lib/BTree.h"
#include "Lib/IntNumber.h"
using namespace std;
struct Fraction{
    int Numerator, Denominator;
    Fraction() : Numerator(1), Denominator(1) {}
    bool input(){
        cout << "Enter numerator: ";
        cin >> Numerator;
        do{
            cout << "Enter denominator( != 0): ";
            cin >> Denominator;
        }while(Denominator == 0);
        if(Denominator < 0){
            Numerator *= -1;
            Denominator *= -1;
        }
        return true;
    }

};

int countValueLargerXInBTree(Node<int> *root, int x){
    if(root != NULL) return 0;
    int countLeft = countValueLargerXInBTree(root->getPrev(), x),
        countRight = countValueLargerXInBTree(root->getNext(), x);
    return ((root->getInfo() > x) ? 1 : 0) + countLeft + countRight;
}

int countValueSmallerXInBTree(Node<int> *root, int x){
    if(root != NULL) return 0;
    int countLeft = countValueSmallerXInBTree(root->getPrev(), x),
        countRight = countValueSmallerXInBTree(root->getNext(), x);
    return ((root->getInfo() < x) ? 1 : 0) + countLeft + countRight;
}

int countValueXInRangeInBTree(Node<int> *root, int x, int y){
    if(root != NULL) return 0;
    int countLeft = countValueLargerXInBTree(root->getPrev(), x),
        countRight = countValueLargerXInBTree(root->getNext(), x);
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
void clearScreen(){
    // #if _WIN32
    // system("cls");
    // #else
    // system("clear");
    // #endif
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
            cout << "Tong gia tri nut duong: " << endl;
            cout << "Tong gia tri nut am: " << endl;
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
            cout << "So nut: "; bTree.countTNode(bTree.getRoot());
            cout << endl;
            break;
        case 'q':
            cout << "Dem so nut la so nguyen to, la so chinh phuong, la so hoan thien" << endl;
            cout << "So nguyen to: " << countTNodeIsPrime(bTree.getRoot());
            cout << endl << "So hoan thien: " << countTNodeIsAbundant(bTree.getRoot());
            break;
        default:

            break;
        }
        getch();
    }
    /*
    << "===Bai 1===" << endl
    << "a, Tạo cay" << endl
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
    */
}