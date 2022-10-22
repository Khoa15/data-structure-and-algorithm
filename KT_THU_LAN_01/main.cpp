#include "TEST01_LIB.h"
string infixToPrefix(string infix);
void Menu1(){
    cout    << "3. Xuat thong tin danh sach cac cuon sach" << endl
            << "4. Dem so cuon sach co so trang lon hon 500 va xuat ban truoc nam 2018" << endl
            << "5. Xoa tat ca cac cuon sach co gia ban lon hon 100000" << endl
            << "6. Them cuon sach truoc cuon sach co gia nho hon 50000" << endl
            << "==================================" << endl
            << "7. Convert Infix to Prefix" << endl
            << "============================" << endl;
}
// void Menu2(){

// }

void Control(int &option, ListBook *SBook = NULL){
    NBook* book = new NBook();
    switch (option)
    {
    case 3:
        SBook->showList();
        break;
    case 4:
        cout << SBook->countBookPagesLargerXyearIsY();
        break;
    case 5:
        SBook->deleteAllBooksPriceLargeX();
        break;
    case 6:
        book->getInfo().getData();
        SBook->addBookBeforeBookHavePriceSmallerX(book, 50000);
        break;
    case 7:
        string infix = "Q + T * V/U/W * ) P^O(+ N*M - L + K";
        // getline(cin, infix);
        cout << infixToPrefix(infix);
        break;
    }
}

int main(){
    int option = 7;
    ListBook* SBook = new ListBook();
    SBook->getFile("books");
    do{
        Menu1();
        cin >> option;
        Control(option, SBook);

   }while(option != 0);
    return 0;
}

string infixToPrefix(string infix){
    string result;
    string stk;
    string operate = "+-*/,";
    for(int i = 0; i < infix.length(); i++){
        if(infix[i] == ' ') continue;
        bool flag = false;
        for(int j = 0; j < operate.length(); j++){
            if(infix[i] == operate[j]){
                if(stk.length() > 0){
                    result.push_back(stk.back());
                    stk.pop_back();
                }
                stk.push_back(infix[i]);
                flag = true;
                break;
            }
        }
        if(flag == false){
            result.push_back(infix[i]);
        }
    }
    return result;
}