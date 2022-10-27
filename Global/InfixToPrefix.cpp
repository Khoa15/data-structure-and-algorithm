#include "Stack.h"
#include <string>

int getPriority(string OP){
    if(OP == "+" || OP == "-") return 1;
    if(OP == "*" || OP == "/") return 
}

int main(){
    string str = "Q+T*V/U/W*)P^O(+N*M-L+K";
    string check = "+*/-()^";
    Stack<char> stk;

    for(int i = 0; i < str.length(); i++){
        if(str[i] == ' ') continue;
        if(str[i] == ')'){
            if()
            stk.pop();
            continue;
        }
        if(
            str[i] == '+' ||
            str[i] == '-' ||
            str[i] == '*' ||
            str[i] == '/' ||
            str[i] == '('
        ){
            stk.push(createNode(str[i]));
            continue;
        }
        cout << str[i];
    }

    return 0;
}