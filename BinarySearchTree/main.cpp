#include <iostream>
#include <stdlib.h>
#include "Lib/BTree.h"
#include "Lib/IntNumber.h"
#ifdef _WIN32
#include <Windows.h>
#endif
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
}

void Menu(int option){
    switch(option){
        case 0:
            cout
                << "1. Bài 1" << endl
                << "2. Bài 2" << endl
                << "3. Bài 3" << endl
                << "4. Bài 4" << endl;
            break;
        case 1:
            cout 
                << "===Bài 1===" << endl
                << "a, Tạo cây" << endl
                << "b. Duyệt cây: NLR, LNR, LRN, NRL, RNL, RLN" << endl
                << "c. Duyệt cây theo chiều rộng NLR, NRL." << endl
                << "d. Duyệt cây theo chiều sâu: NLR, LNR, LRN, NRL, RNL, RLN" << endl
                << "e. Thêm 1 nút có giá trị x." << endl
                << "f. Tìm kiếm 1 nút có giá trị x." << endl
                << "g. Xóa nút có giá trị x." << endl
                << "h. Xuất các phần tử theo chiều giảm dần." << endl
                << "i. Đếm số giá trị lớn hơn x, nhỏ hơn x, có giá trị trong đoạn [x, y]." << endl
                << "j. Tìm nút có giá trị lớn nhất, nhỏ nhất của cây." << endl
                << "k. Xuất ra nội dung các nút, lá ở mức k/ nội dung các nút chỉ có 1 con ở mức k." << endl
                << "l. Đếm số nút, nút lá, nút chỉ có 1 con ở mức k." << endl
                << "m. Tính tổng giá trị các nút dương/ giá trị các nút âm." << endl
                << "n. Tìm phần tử có khoảng cách về giá trị gần nhất với phần tử x." << endl
                << "o. Tìm phần tử có khoảng cách về giá trị xa nhất với phần tử x." << endl
                << "p. Đếm số nút của cây(đệ quy/ khử đệ quy)" << endl
                << "q. Đếm số nút là số nguyên tố, là số chính phương, là số hoàn thiện, là số thịnh vượng, là số yếu của cây." << endl
                << "r. Tính tổng giá trị các nút của cây (đệ quy/ khử đệ quy)." << endl
                << "s. Tính tổng giá trị các nút là số nguyên tố, là số chính phương, là số hoàn thiện, là số thịnh vượng, là số yếu của cây." << endl
                << "t. Xóa toàn bộ cây." << endl;
            break;
    }
}
void Bai1();
int main(){
    #if _WIN32
    SetConsoleOutputCP(65001);
    system("cls");
    #else
    system("clear");
    #endif
    int option = 1;

    while(option != 0){
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
    bTree.init(NULL);
    while(1){
        Menu(1);
        cin.ignore();
        cin >> option;
        switch (option)
        {
        case '0':
            return;
            break;
        case 'b':
            cout << "LNR: ";
            bTree.traverseLNR();
            cout << endl << "LRN: ";
            bTree.traverseLRN();
            cout << endl << "NLR: ";
            bTree.traverseNLR();
            cout << endl << "NRL: ";
            bTree.traverseNRL();
            cout << endl << "RLN: ";
            bTree.traverseRLN();
            cout << endl << "RLN: ";
            bTree.traverseRNL();
            break;
        case 'c':
            bTree.traverseBreadthNLR();
            break;
        case 'd':
            bTree.traverseDepthNLR();
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
            if(bTree.deleteTNode(X)){
                cout << "Successfully" << endl;
            }else{
                cout << "Error!" << endl;
            }
            break;
        case 'h':
            cout << "Xuat cac phan tu theo chieu giam dan" << endl;
            bTree.traverseRNL();
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
            bTree.showTNodeIsLeafOfLevelK(X);
            cout << "So nut chi co 1 con o muc k: " << bTree.countTNodeOfLevelK(X) << endl;
            break;
        case 'm':
            cout << "Tong gia tri nut duong: " << endl;
            cout << "Tong gia tri nut am: " << endl;
            break;
        case 'n':
            cout << "Tìm phần tử có giá trị gần nhất với phần tử x" << endl;
            cout << "Nhập x: ";
            getInputX(X);
            bTree.findTNodeMinDistanceX(X);
            break;
        case 'o':
            cout << "Tìm phần tử có giá trị xa nhất với phần tử x" << endl;
            cout << "Nhập x: ";
            getInputX(X);
            bTree.findTNodeMaxDistanceX(X);
            break;
        case 'p':
            cout << "Đếm số nút của cây" << endl;
            break;
        case 'q':
            cout << "Đếm số nút là số nguyên tố, là số chính phương, là số hoàn thiện";

            break;
        default:

            break;
        }
}
    /*
    << "===Bài 1===" << endl
    << "a, Tạo cây" << endl
    << "b. Duyệt cây: NLR, LNR, LRN, NRL, RNL, RLN" << endl
    << "c. Duyệt cây theo chiều rộng NLR, NRL." << endl
    << "d. Duyệt cây theo chiều sâu: NLR, LNR, LRN, NRL, RNL, RLN" << endl
    << "e. Thêm 1 nút có giá trị x." << endl
    << "f. Tìm kiếm 1 nút có giá trị x." << endl
    << "g. Xóa nút có giá trị x." << endl
    << "h. Xuất các phần tử theo chiều giảm dần." << endl
    << "i. Đếm số giá trị lớn hơn x, nhỏ hơn x, có giá trị trong đoạn [x, y]." << endl
    << "j. Tìm nút có giá trị lớn nhất, nhỏ nhất của cây." << endl
    << "k. Xuất ra nội dung các nút, lá ở mức k/ nội dung các nút chỉ có 1 con ở mức k." << endl
    << "l. Đếm số nút, nút lá, nút chỉ có 1 con ở mức k." << endl
    << "m. Tính tổng giá trị các nút dương/ giá trị các nút âm." << endl
    << "n. Tìm phần tử có khoảng cách về giá trị gần nhất với phần tử x." << endl
    << "o. Tìm phần tử có khoảng cách về giá trị xa nhất với phần tử x." << endl
    << "p. Đếm số nút của cây(đệ quy/ khử đệ quy)" << endl
    << "q. Đếm số nút là số nguyên tố, là số chính phương, là số hoàn thiện, là số thịnh vượng, là số yếu của cây." << endl
    << "r. Tính tổng giá trị các nút của cây (đệ quy/ khử đệ quy)." << endl
    << "s. Tính tổng giá trị các nút là số nguyên tố, là số chính phương, là số hoàn thiện, là số thịnh vượng, là số yếu của cây." << endl
    << "t. Xóa toàn bộ cây." << endl;
    */
}