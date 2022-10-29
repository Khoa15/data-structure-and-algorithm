/*********Thông tin Sinh viên (Nguyen Trong Dang Khoa - 2001215879)****************/
#include <iostream>
#ifdef _WIN32
#include <Windows.h>
#endif
#include <vector>
#include <string>
#include <istream>
#include "KiemTraGiuaKy1.h"
using namespace std;

bool isDESC(SList &l){ // Giam dan
    if(isEmpty(l)){
        // cout << "List is empty\n";
        return false;
    }
    for(Node* tmp = l.head; tmp->next != NULL; tmp = tmp->next){
        if(tmp->info < tmp->next->info) return false;
    }
    return true;
}

bool isASC(SList &l){ // Tang dan
    if(isEmpty(l)){
        // cout << "List is empty\n";
        return false;
    }
    for(Node* tmp = l.head; tmp->next != NULL; tmp = tmp->next){
        if(tmp->info > tmp->next->info) return false;
    }
    return true;
}

int getPriority(string OP){
    if(OP == "+" || OP == "-"){
        return 1;
    }
    if(OP == "*" || OP == "/"){
        return 2;
    }
    return 0;
}

// void infixToPostFix(int *OP){
//     Stack stk;
//     int postfix;
//     for(int i = 0; i < sizeof(OP[0])/sizeof(OP); i++){
//         if(
//             OP[i] == '+' ||
//             OP[i] == '-' ||
//             OP[i] == '*' ||
//             OP[i] == '/'
//         ){
//             if(stk.top == NULL){
//                 addTailSList(stk, createNode())
//             }
//             continue;
//         }
//     }
// }

void menuKiemTra()
{
    cout << "*********************" << endl;
    cout << "Kiểm tra giữa kỳ lần 1" << endl;
    cout << "*********************" << endl;
    cout << "0. Thoát" << endl;
    cout << "a. Nhập xuất danh sách sl có n phần tử số nguyên(2đ)\n";
    cout << "b. Kiểm tra danh sách sl có thứ tự tăng dần, giảm dần hay không có thứ tự(2đ)\n";
    cout << "c. Tạo 2 danh sách sl1, sl2 chứa các số nguyên.Hiển thị phần giao, hội, hiệu của 2 danh sách này(2đ)\n";
    cout << "d. Viết chương trình chuyển biểu thức dạng trung tố đơn giản sang biểu thức dạng hậu tố và tính giá trị biểu thức.Biết rằng biểu thức dạng ";
    cout << "\ntrung tố đơn giản gồm các số từ 0 đến 9 và các phép toán +, -, *, / và dấu(, )(4đ)\n";
}
/////////////////
int main()
{
    #ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);
    #endif
    char chonCau = 48;
    SList sl, sl1, sl2;
    init(sl);
    do
    {
        system("cls");
        menuKiemTra();
        cout << "\nChọn câu: ";
        cin >> chonCau;
        switch (chonCau)
        {
        case 48:
        {
            cout << "Thoát" << endl;
            break;
        }
        case 'a': // Nhập xuất danh sách sl có n phần tử số nguyên(2đ)
            {
                createSList(sl);
                break;
            }
        case 'b': // Kiểm tra danh sách sl có thứ tự tăng dần, giảm dần hay không có thứ tự(2đ)
            {
                cout << ((isDESC(sl) == true) ? "Giam dan" : ((isASC(sl) == true) ? "Tang dan" : "Khong co thu tu")) << endl;
                break;
            }
        case 'c': // Tạo 2 danh sách sl1, sl2 chứa các số nguyên.Hiển thị phần giao của 2 danh sách này(2đ)
            {
                createSList(sl1);
                createSList(sl2);
                int j = 0;
                int arr[sl1.length];
                bool flag = false;
                vector<int> HOI;
                for(Node* tmp = sl2.head; tmp != NULL; tmp = tmp->next){
                    HOI.emplace_back(tmp->info);
                }
                for(Node* tmp = sl1.head; tmp != NULL; tmp = tmp->next){
                    for(int i = 0; i < HOI.size(); i++){
                        if(HOI[i] == tmp->info){
                            flag = true;
                            break;
                        }
                    }
                    if(flag == false){
                        HOI.emplace_back(tmp->info);
                    }
                    for(Node* tmp2 = sl2.head; tmp2 != NULL; tmp2 = tmp2->next){

                        if(tmp->info == tmp2->info){
                            bool flag = false;
                            for(int k = 0; k < j; k++){
                                if(tmp->info == arr[j]){
                                    flag = true;
                                    break;
                                }
                            }
                            if(flag == false){
                                arr[j] = tmp->info;
                                j++;
                            }
                            break;
                        }
                    }
                }
                cout << "Hoi: ";
                for(auto x : HOI){
                    cout << x << " ";
                }
                cout << "\nGiao: ";
                for(int k = 0; k < j;k++){
                    cout << arr[k] << " ";
                }
                cout << "\nHieu: ";
                for(auto x : HOI){
                    bool flag = true;
                    for(int k = 0; k < j;k++){
                        if(x == arr[k]){
                            flag = false;
                            break;
                        }
                    }
                    if(flag){
                        cout << x << " ";
                    }
                }

                break;
            }
        case 'd': // Viết chương trình chuyển biểu thức dạng trung tố đơn giản sang biểu thức dạng hậu tố và tính giá trị biểu thức(4đ)
            {
                Stack stk;
                string infix, postfix;
                cout << "nhap bieu thuc trung to: ";
                cin >> infix;
                for(int i =0; i < infix.length(); i++){
                    if(infix[i] == ' ') continue;
                    char tmp[2];
                    tmp[0] = infix[i];
                    if(infix[i] == '('){
                        stk.push(tmp);
                        continue;
                    }else if(infix[i] == ')'){
                        while(stk.top->info[0] != '('){
                            postfix.push_back(stk.top->info[0]);
                            stk.pop();
                        }
                        continue;
                    }
                    if(
                        infix[i] == '+' ||
                        infix[i] == '-' ||
                        infix[i] == '*' ||
                        infix[i] == '/'
                    ){
                        if(stk.top != NULL){
                            stk.push(tmp);
                        }else{
                            while(stk.top != NULL){
                                if(getPriority(tmp) > getPriority(stk.top->info)){
                                    stk.push(tmp);
                                }else{
                                    postfix.push_back(stk.top->info[0]);
                                    cout << postfix;
                                    stk.pop();
                                }
                            }
                        }
                    }else{
                        postfix.push_back(infix[i]);
                    }
                }
                while(stk.top != NULL){
                    postfix.push_back(stk.top->info[0]);
                    cout << postfix;
                    stk.pop();
                }
                cout << endl << "Hau to: " << postfix << endl;
                break;
            }
        default:
            break;
        }
        system("pause");
    } while (chonCau != 48);
    return 1;
}