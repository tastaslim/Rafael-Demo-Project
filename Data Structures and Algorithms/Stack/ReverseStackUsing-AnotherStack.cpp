#include<iostream>
#include<stack>
using namespace std;
void reverseStack(stack<int> &input, stack<int> &extra) {
    while (!input.empty())
    {
        int top=input.top();
        extra.push(top);
        input.pop();
    }
    input=extra;
}

int main() {
    stack<int> s1, s2;
    int size;
    cin >> size;

    int val;
    for (int i = 0; i < size; i++) {
        cin >> val;
        s1.push(val);
    }
    reverseStack(s1, s2);
    //Although output is same as input but
    //Now last element would be at top.
    while (!s1.empty()) {
        cout << s1.top() << " ";
        s1.pop();
    }
}