#include <iostream>
#include "test.h"
#include "Foo.h"
using namespace std;
int main()
{
    Num n(35);
    cout << n.getNum() << endl;
    Foo f;
    cout << f.n.getNum() << endl;
    return 0;
}