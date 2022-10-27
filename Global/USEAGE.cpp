#include "Queue.h"
#include "Node.h"
int main(){
    Queue<int> q1;
    q1.push(createNode(10));
    q1.push(createNode(5));
    q1.push(createNode(4));

    while(q1.getSize() != 0){
        std::cout << q1.top()->getInfo() << endl;
        q1.pop();
    }
    return 0;
}