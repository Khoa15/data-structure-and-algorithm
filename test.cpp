#include <iostream>
using namespace std;

template<class T>
void excha(T& a, T& b){
    T tmp = a;
    a = b;
    b = tmp;
}
inline int getA(){
    return 10;
}
int main(){
    int a = getA(), b = 5;
    excha(a, b);
    cout << a << " " << b;
    return 0;
}