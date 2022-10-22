#include "LinkedList.h"
#include <string>
void Menu();

int main(){
    SList *sl;
    int option = 0, x = 0;
    char* filename = "linkedlist.txt";
    while(1){
        Menu();
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