#include <bits/stdc++.h>

using namespace std;

// template <typename T>
int getPriority(char OP){
    // cout << OP;
    // return 3;
    if(OP == '+' || OP == '-'){
        return 1;
    }
    if(OP == '*' || OP == '/'){
        return 2;
    }
    if(OP == '^'){
        return 3;
    }
    return -1;
}

string infixToPostfix(string infix){
    string postfix;
    stack<char> stk;
    for(int i = 0; i < infix.length(); i++){
        char c = infix[i];
        if(c == ' '){
            continue;
        }
        if(c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z' || c >= '0' && c <= '9'){
            postfix.push_back(c);
        }else if( c == '('){
            stk.push(c);
        }else if(c == ')'){
            while(stk.empty() == false && stk.top() != '('){
                postfix.push_back(stk.top());
                stk.pop();
            }
            if(stk.empty() == false){
                stk.pop();
            }
        }else{
            while(stk.empty() == false && getPriority(c) <= getPriority(stk.top())){
                postfix.push_back(stk.top());
                stk.pop();
            }
            stk.push(c);
        }
    }
    while(stk.empty() == false){
        postfix.push_back(stk.top());
        stk.pop();
    }
    return postfix;
}

int calculateFromPostfix(string postfix){
    stack<char> stk;
    for(int i = 0; i < postfix.length(); i++){
        char c = postfix[i];
        if(c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z' || c >= '0' && c <= '9'){
            stk.push(c);
        }else{
            int opr1 = (int)stk.top() - '0';
            stk.pop();
            int opr2 = (int)stk.top() - '0';
            int result = 0;
            switch(c){
                case '+':
                    result = opr1 + opr2;
                break;
                case '-':
                    result = opr1 - opr2;
                break;
                case '*':
                    result = opr1 * opr2;
                break;
                case '/':
                    result = opr1 / opr2;
                break;
            }
            stk.push((char)result + '0');
        }
    }
    cout << (char)stk.top() - '0' << endl;
    return 0;
}

int main(){
    string infix = "9-1*3+(4 ^ 5*3)";
    // cin.ignore();
    // getline(cin, infix);
    // cout << infix;
    cout << endl << infixToPostfix(infix) << endl;
    return 0;
}