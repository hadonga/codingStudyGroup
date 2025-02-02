//stack ~ LIFO
// push(x); pop();top();empty();size()
// stack 不能遍历

#include <iostream>
#include <stack>

using namespace std;

int main(){

    stack<int> myStack = {};
    myStack.push(1);
    myStack.push(2);
    myStack.push(3);
    myStack.push(4);
    myStack.push(5);
    int n = myStack.size();

    for (int i =0; i < n; ++i){
        cout << myStack.top() << " ;";
        myStack.pop();
    }
    cout << endl;
    return 0;
}