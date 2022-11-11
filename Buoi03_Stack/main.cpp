#include <bits/stdc++.h>
#include "Lib/Stack.h"
using namespace std;

string convertDecimalToHexa(int n){
    string const HEX = "0123456789ABCDEF";
    string result = "";
    while(n){
        result.push_back(HEX[n%16]);
        n /= 16;
    }

    return result;
}

void Menu2(){
    cout    << "1. Do, 2. Undo, 3. Redo\n";
    cout    << "1. delete char\n"
            << "2. delete selected words\n"
            << "3. typing char\n"
            << "4. bold\n"
            << "5. italic\n"
            << "6. underline\n";
}

void Bai2(){
    Stack<int> *Stack1 = new Stack<int>,
                *Stack2 = new Stack<int>;
    int n;
    char option[6][22] = {"Delete char", "Delete selected words", "Typing char", "Bold", "Italic", "Underline"};
    while(1){
        cout    << "1. Do, 2. Undo, 3. Redo\n";
        cin >> n;
        if(n == 2){
            if(Stack1->isEmpty() == false){
                Stack2->push(createNode(Stack1->top()->getInfo()));
                Stack1->pop();
            }
        }else if(n == 1){
            do{
                cout    << "1. delete char\n"
                        << "2. delete selected words\n"
                        << "3. typing char\n"
                        << "4. bold\n"
                        << "5. italic\n"
                        << "6. underline\n";
                cin >> n;
            }while(n < 1 || n > 6);
            Stack1->push(createNode(n));
        }else if(n == 3){
            if(Stack2->isEmpty() == false){
                Stack1->push(createNode(Stack2->top()->getInfo()));
                Stack2->pop();
            }
        }
            cout << "\nStack 1: ";
            Stack1->showList();
            cout << "\nStack 2: ";
            Stack2->showList();
            cout << endl;
    }
    Stack1->cleanList();
    Stack2->cleanList();
}
void Bai3(){
    Stack<char> stk;
    string n;
    bool flag = true;
    cin >> n;
    for(int i = 0; i < n.length(); i++){
        if(n[i] == ' ') continue;
        //(), {}, []
        if((n[i] == '}' || n[i] == ')' || n[i] == ']') && stk.isEmpty() == true){
            cout << "Sai\n";
            break;
        }else if(
            stk.isEmpty() == false &&
            (
            (n[i] == '}' && stk.top()->getInfo() != '{')
            ||
            (n[i] == ']' && stk.top()->getInfo() != '[')
            ||
            (n[i] == ')' && stk.top()->getInfo() != '(')
            )){
                flag = false;
                break;
            }else{
                if(
                (n[i] == '}' && stk.top()->getInfo() == '{')
                ||
                (n[i] == ']' && stk.top()->getInfo() == '[')
                ||
                (n[i] == ')' && stk.top()->getInfo() == '(')
                ){
                    stk.pop();
                    continue;
                }
                stk.push(createNode(n[i]));
            }
    }
    if(flag == true){
        cout << "Đúng\n";
    }else{
        cout << "Sai\n";
    }
    stk.cleanList();
}
int main(){
    
    return 0;
}