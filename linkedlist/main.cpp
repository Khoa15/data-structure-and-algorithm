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

void Menu(int position = 0);
void Control(int position, int to, SList* sl){
    int x = 0, y = 0;
    switch (position)
    {
    case 1:
        switch (to)
        {
        case 1:
            sl->printSList();
            break;
        
        case 2:{
                printf("Enter x: ");
                scanf("%d", &x);
                Node* p = p->create(x);
                sl->addTail(p);
            break;
        }
        case 3:{
                printf("Enter x and y: ");
                scanf("%d%d", &x, &y);
                Node* p = p->create(x);
                sl->addNodeBeforeValue(p, y);
            break;
        }
        case 4:{
                printf("Enter x: ");
                scanf("%d", &x);
                sl->deleteNodeLargerValue(x);
            break;
        }
        case 5:
                sl->deleteEvenList();
            break;
        
        case 6:{
            char type[2];
            printf("Press y if you want to sort linked list ASC or n for DESC: ");
            scanf(" %c", &type);
            if(type == "y"){
                sl->sortSList(true);
                return;
            }
            sl->sortSList(false);
            return;
            break;
        }
        case 7:
                printf("Total of prime number: %d", sl->countPrime());
            break;
        
        case 8:
                printf("Total of square number: %d", sl->countSquareNumber());
            break;
        
        case 9:
                printf("Max node: %d\nMin node: %d", sl->findMaxValue(), sl->findMinValue());
            break;
        
        case 10:
                printf("Count of node larger than two times node after: %d", sl->countALarger2B());
            break;
        
        case 11:
                SList* sl1 = new SList();
                SList* sl2 = new SList();
                sl->decideOddEven(sl1, sl2);
                sl1->printSList();
                printf("\n");
                sl2->printSList();
                sl1->deleteSList(sl1->pHead);
                sl2->deleteSList(sl1->pHead);
            break;
        }        
        break;
    case 2:
        switch(to){
        case 1:

            break;
        case 2:

            break;
        case 3:

            break;
        case 4:

            break;
        case 5:

            break;
        case 6:

            break;
        case 7:

            break;
        case 8:

            break;
        }
        break;
    default:
        break;
    }
}


int main(){
    int position = 0, to = -1;
    SList* sl = new SList();
    if(sl == NULL){
        printf("Memory is not enough");
        return 0;
    }
    while(1){
        Menu(position);
        printf("Enter a number: ");
        if(position == 0){
            scanf("%d", &position);
            continue;
        }else{
            scanf("%d", &to);
            if(to == 0){
                position = 0;
                continue;
            }
            Control(position, to, sl);
        }
    }
    return 0;
}

void Menu(int position){
    printf("\n==================\n");
    switch (position)
    {
    case 0:
        printf(
            "1. Bai 1\n"
            "2. Bai 2\n"
            );
        break;
    case 1:
        printf(
            "1. Xuất danh sách\n"
            "2. Thêm phần tử mới vào cuối danh sách.\n"
            "3. Chèn thêm phần tử có giá trị x vào trước phần tử có giá trị y.\n"
            "4. Viết hàm xóa các phần tử lớn hơn x trong dslk\n"
            "5. Viết hàm xóa các phần tử chẵn trong dslk\n"
            "6. Sắp xếp dslk tăng dần, giảm dần\n"
            "7. Cho biết trong dslk có bao nhiêu số nguyên tố\n"
            "8. Tính tổng các số chính phương trong dslk\n"
            "9. Tìm phần tử nhỏ nhất, phần tử  lớn nhất trong dslk\n"
            "10. Cho biết trong dslk có bao nhiêu phần tử lớn hơn gấp đôi phần tử phía sau nó\n"
            "11. Từ sl tạo 2 danh sách mới: sl1 chứa các số chẵn, sl2 chứa các số lẻ\n"
            );
        break;

    case 2:
        printf(
            "1. Nhập danh sách có n phân số\n"
            "2. Xuất danh sách có n phân số\n"
            "3. Tối giản các phân số\n"
            "4. Tính tổng/ tích các phân số\n"
            "5. Cho biết phân số lớn nhất, phân số nhỏ nhất\n"
            "6. Tăng mỗi phân số của danh sách lên một đơn vị\n"
            "7. Xuất các phân số lớn hơn 1 trong danh sách liên kết\n"
            "8. Tìm phân số p\n"
            );
        break; 
    default:
        printf("Error code\n");
        break;
    }
    printf("\n==================\n");
}