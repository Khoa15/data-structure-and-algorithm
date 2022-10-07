/*
Nguyễn Trọng Đăng Khoa
2001215879
12DHTHTD
*/

#include <iostream>
#include <time.h>
#include <stdlib.h>
#include "LinkedList.h"

using namespace std;

// void SList::printSList(SList* sList){
//     for(Node* p = sList->pHead; p != NULL; p = p->pNext){
//         cout << p->val << " ";
//     }
// }

int main(){
    SList* sList = new SList();
    for(int i = 0; i < 10; i++){
        Node* p = new Node(random() % 100);
        sList->addHead(p);
    }

    sList->printSList();
    cout << endl;
    sList->sortSList(false);

    sList->printSList();

    // sList->deleteSList(sList->pHead);
    return 0;
}