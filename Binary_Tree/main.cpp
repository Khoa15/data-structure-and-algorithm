#include <bits/stdc++.h>
#include "Lib/Node.h"
#include "Lib/Tree.h"
using namespace std;

int random(int mi, int ma){
    return rand() %( ma - mi + 1 )+ mi;
}

void Menu(int option){
    switch (option)
    {
    case 1:
        cout    << "=====Bai 1=====\n"
                << "a. Tao cay( mảng, nhập, tạo ngẫu nhiên)\n"
                << "b. Duyệt cây: NLR, LNR, LRN, NRL, RNL, RLN\n"
                << "c. Thêm nút giá trị x làm con trái của nút có giá trị y\n"
                << "d. Thêm nút giá trị x làm con phải của nút có giá trị y\n"
                << "e. Đếm số nút trên cây\n"
                << "f. Tìm kiếm 1 nút có giá trị x\n"
                << "g. Liệt kê các nút có giá trị lớn hơn x\n"
                << "h. Đếm số nút trên cây, số nút lá, số nút có 1 con, số nút có 2 con, ... Tính tổng các nút trên cây, tổng nút lá, tổng nút có 1 con, tổng nút có 2 con, tính chiều cao.\n"
                << "==============\n";
        break;
    default:
    cout    << "=====Bai 1=====\n"
            << "=====Bai 2=====\n"
            << "=====Bai 3=====\n"
            << "=====Bai 4=====\n"
            << "Enter a number: ";
        break;
    }
    
}

void Bai1();

int main(){
    int option = -1;
    while(1){
        Menu(option);
        cin >> option;
        if(option == 0) break;
        switch (option)
        {
        case 1:
            Bai1();
            break;
        
        default:
            break;
        }
    }

    return 0;
}

void Bai1(){
    char choose;
    int n = 0,
        tmp = 0,
        x = 0,
        y = 0;
    Tree<int> *BTree = new Tree<int>();
    Node<int>   *NodeX = NULL,
                *NodeY = NULL;
    while(1){
        Menu(1);
        cin.ignore();
        cin >> choose;
        if(choose == '0') return;
        switch (choose)
        {
        case 'a':
            cout << "Create a Tree\n"
                << "a. Mảng\n"
                << "b. Nhập bàn phím\n"
                << "c. Auto\n"
                << "Choose your option: ";
            cin >> choose;
            switch(choose){
                case 'a':
                    cout << "Enter n: ";
                    cin >> n;
                    for(int i = 0; i < n;i++){
                        cout << "Phan tu thu " << i << ": ";
                        cin >> tmp;
                        BTree->insertTNode(createNode(tmp));
                    }
                    break;
                case 'c':
                    srand(time(NULL));
                    n = random(5, 10);
                    for(;n>=0;n--){
                        BTree->insertTNode(createNode(random(-99,99)));
                    }
                    break;
            }
            break;
        case 'b':
            cout << "Traverse Tree" << endl;
            cout << "LNR: ";
            BTree->traverseLNR(BTree->getRoot());
            cout << "\nLRN: ";
            BTree->traverseLRN(BTree->getRoot());
            cout << "\nNLR: ";
            BTree->traverseNLR(BTree->getRoot());
            cout << "\nNRL: ";
            BTree->traverseNRL(BTree->getRoot());
            cout << "\nRNL: ";
            BTree->traverseRNL(BTree->getRoot());
            cout << "\nRLN: ";
            BTree->traverseRLN(BTree->getRoot());
            cout << "\n";
            break;
        case 'c':
            cout << "Nhap giá trị x cho nút: ";
            cin >> x;
            cout << "Nhập giá trị y của nút để thêm x vào bên trái: ";
            cin >> y;
            
            NodeY = BTree->findNode(y);
            if(NodeY == NULL){
                cout << "Không tìm thấy!";
                break;
            }else{
                NodeX = createNode(x);
                if(NodeY->getPrev() != NULL){
                    if(NodeY->getPrev()->getInfo() < x){
                        NodeX->setNext(NodeY->getPrev());
                    }else{
                        NodeX->setPrev(NodeY->getPrev());
                    }
                }
                NodeY->setPrev(NodeX);
            }
            break;
        case 'd':
            cout << "Nhap giá trị x cho nút: ";
            cin >> x;
            cout << "Nhập giá trị y của nút để thêm x vào bên phải: ";
            cin >> y;
            
            NodeY = BTree->findNode(y);
            if(NodeY == NULL){
                cout << "Không tìm thấy!";
            }else{
                NodeX = createNode(x);
                if(NodeY->getNext() != NULL){
                    if(NodeY->getNext()->getInfo() < x){
                        NodeX->setNext(NodeY->getNext());
                    }else{
                        NodeX->setPrev(NodeY->getNext());
                    }
                }
                NodeY->setNext(NodeX);
            }
            break;
        case 'e':
            cout << "Số nút trên cây: " << BTree->countTNode(BTree->getRoot()) << endl;
            break;
        case 'f':
            cout << "Nhập x để kiểm tra tồn tại: ";
            cin >> x;
            if(BTree->findNode(x) != NULL){
                cout << "Có tồn tại" << endl;
            }else{
                cout << "Không tồn tại" << endl;
            }
            break;
        case 'g':
            cout << "Nhập x để liệt kê các nút có giá trị lớn hơn: ";
            cin >> x;
            BTree->listNodeLargerThanX(BTree->getRoot(), x);
            cout << endl;
            break;
        case 'h':
            cout << "Số nút trên cây: "
                << BTree->countTNode(BTree->getRoot())
                << "\nSố nút lá: "
                << BTree->countTNodeIsLeaf(BTree->getRoot())
                << "\nSố nút có 1 con: "
                << BTree->countTNodeHaveOneChild(BTree->getRoot())
                << "\nSố nút có 2 con: "
                << BTree->countTNodeHaveTwoChild(BTree->getRoot())
                << "\nChiều cao: "
                << BTree->getHeight(BTree->getRoot())
                << endl;
            break;
        default:
            break;
        }

    }
}