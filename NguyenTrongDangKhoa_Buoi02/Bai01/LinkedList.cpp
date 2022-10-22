#include "LinkedList.h"

void SList::addTail(int x) {
    Node* p = new Node(x);
	if (pHead == NULL) {
		pHead = p;
		pTail = p;
		return;
	}
	Node* tmp = pHead;
	while (tmp->pNext != NULL) {
		tmp = tmp->pNext;
	}
	tmp->pNext = p;
	pTail = p;
}

void SList::getFile(char* _filename){
    FILE *f = fopen(_filename, "r");
    if( f == NULL){
        printf("File not found\n");
        return;
    }
    int x = 0;
    while(fscanf(f, "%d", &x)){
        addTail(x);
    }
}

void SList::deleteHead(){
    deleteNode(pHead); 
}

void SList::deleteNodeAfterX(int x){
    for(Node* tmp = pHead; tmp != NULL; tmp = tmp->pNext){
        if(tmp->val == x){
            deleteNode(tmp->pNext);
        }
    }
}

void SList::deleteNode(Node* p){
    if(pHead == p){
        Node* tmp = pHead;
        pHead = pHead->pNext;
        delete tmp;
        return;
    }
    Node* tmp = pHead;
    while(tmp->pNext != NULL){
        if(tmp->pNext == p){
            tmp->pNext = p->pNext;
            delete p;
            return;
        }
    }
}

void SList::deleteNodeValEqualX(int x){
    for(Node* tmp = pHead; tmp->pNext != NULL; tmp = tmp->pNext){
        if(tmp->pNext->val == x){
            tmp->pNext = tmp->pNext->pNext;
            delete tmp->pNext;
        }
    }
}

void SList::deleteList(){
    delete[] pHead;
}

void SList::deleteEvenNode(){
    for(Node* tmp = pHead; tmp != NULL; tmp = tmp->pNext){
        if(tmp->pNext->val % 2 == 0){
            tmp->pNext = tmp->pNext->pNext;
            delete tmp->pNext;
        }
    }
}
#include <string>
void Menu();

int main(){
    SList *sl = new SList();
    int option = 0, x = 0;
    char filename[100];
    while(1){
        Menu();
        printf("Choose option: ");
        scanf("%d", &option);
        switch(option){
        case 1:
            sl->printList();
            break;
        case 2:
            printf("Enter filename:");
            scanf("%s", filename);
            sl->getFile(filename);
            break;
        case 3:
            sl->deleteHead();
            break;
        case 4:
            printf("Enter a value: ");
            scanf("%d", &x);
            sl->deleteNodeAfterX(x);
            break;
        case 5:
            printf("Enter a value: ");
            scanf("%d", &x);
            sl->deleteNodeValEqualX(x);
            break;
        case 6:
            sl->deleteList();
            break;
        case 7:
            sl->deleteEvenNode();
            break;
        case 0:
            return 0;
        }
    }

    return 0;
}

void Menu(){
    printf(
        "1. In danh sach\n"
        "2. Nhap danh sach lien ket don tu file\n"
        "3. Xoa phan tu dau\n"
        "4. Xoa phan tu sau mot phan tu da cho\n"
        "5. Xoa cac phan tu co gia tri bang x\n"
        "6. Xoa toan bo danh sach\n"
        "7. Xoa cac phan tu chan trong danh sach lien ket\n"
        );
}