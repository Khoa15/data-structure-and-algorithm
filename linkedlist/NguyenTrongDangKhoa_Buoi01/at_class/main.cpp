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
void Control(SList* sl, int position, int to, SList* sl1 = NULL, SList* sl2 = NULL) {
    int x = 0, y = 0;
    switch (position)
    {
    case 1:
        switch (to)
        {
        case 1:
            sl->printSList(false);
            break;
        case 2:
            printf("Enter value x: ");
            scanf_s("%d", &x);
            sl->addTail(new Node(x));
            break;
        case 3:
            printf("Enter value x and y: ");
            scanf_s("%d%d", &x, &y);
            sl->addXBeforeY(x, y);
            break;
        case 4:
            printf("Enter value x: ");
            scanf_s("%d", &x);
            sl->deleteNodeLargerX(x);
            break;
        case 5:
            sl->deleteEvenVal();
            break;
        case 6:
            printf("Press 0 to ASC or 1 to DESC: ");
            scanf_s("%d", &x);
            sl->sort(x);
            break;
        case 7:
            printf("Total node larger than two times behind it: ");
            printf("%d", sl->countXLarger2Y());
            break;
        case 8:
            printf("Divide even and odd numbers singly linked list: ");
            sl->divideList(sl1, sl2);
            break;
        default:
            break;
        }
        break;
    case 2:
        switch (to)
        {
        case 1:
            sl->printSList(true);
            break;
        case 2:
            printf("Enter n numbers: ");
            scanf_s("%d", &x);
            sl->getListInput(x);
            break;
        case 3:
            sl->simplifyListFraction();
            break;
        case 4:
            printf("Press 0 to sum or 1 to multiple all fractions: ");
            scanf_s("%d", &x);
            switch (x)
            {
            case 0:
                sl->sumListFraction().print();
                break;
            case 1:
                sl->multipleListFraction().print();
                break;
            default:
                break;
            }
        case 5:
            printf("Max fraction: ");
            sl->findMaxFraction()->print();
            printf("Min fraction:");
            sl->findMinFraction()->print();
            break;
        case 6:
            sl->printListFractionLargeY(1);
            break;
        case 7:
            sl->plusListFraction();
            break;
        case 8:
            printf("Can't visualize this option.");
            break;
        default:
            break;
        }
        break;
    default:
        printf("Error code");
        break;
    }
}

int main() {
    int position = 0, to = -1;
    SList* sl = new SList();
    SList* sl1 = new SList();
    SList* sl2 = new SList();
    if (sl == NULL) {
        printf("Memory is not enough");
        return 0;
    }
    while (1) {
        Menu(position);
        printf("Enter a number: ");
        if (position == 0) {
            scanf_s("%d", &position);
            continue;
        }
        else {
            scanf_s("%d", &to);
            if (to == 0) {
                position = 0;
                continue;
            }
        }
    }
    return 0;
}

void Menu(int position) {
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
            "1. Xuất danh sách có n phân số\n"
            "2. Nhập danh sách có n phân số\n"
            "3. Tối giản các phân số\n"
            "4. Tính tổng/ tích các phân số\n"
            "5. Cho biết phân số lớn nhất, phân số nhỏ nhất\n"
            "6. Tăng mỗi phân số của danh sách lên một đơn vị\n"
            "7. Xuất các phân số lớn hơn 1 trong danh sách liên kết\n"
            "8. Tìm phân số p trả về SNode, NULL nếu không có\n"
        );
        break;
    default:
        printf("Error code\n");
        break;
    }
    printf("\n==================\n");
}