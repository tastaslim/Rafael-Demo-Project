#include<iostream>
#include<stack>
using namespace std;
int main()
{
    stack<int> s;
    cout<<s.empty()<<endl;
    s.push(5);
    s.push(10);
    s.push(12);
    int top=s.top();
    cout<<top<<endl;
    cout<<s.size()<<endl;
    s.pop();
    cout<<s.size()<<endl;
    cout<<s.empty()<<endl;
    return 0;
}