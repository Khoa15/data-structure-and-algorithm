#include <iostream>
#include <stdlib.h>
#include "Lib/BTree.h"
#ifdef _WIN32
#include <Windows.h>
#endif
using namespace std;

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
    #elif __linux__
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
        case '1':

            return;
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