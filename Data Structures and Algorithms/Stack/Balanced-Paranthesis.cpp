#include<iostream>
#include<stack>
using namespace std;
bool isbalanced(string str)
{
    stack<char> s;
    for (int i=0;i<str.length();i++)
    {
        if (str[i]=='[' || str[i]=='{' || str[i]=='(')
        {
            s.push(str[i]);
        }
        else if (str[i]==')' || str[i]=='}' || str[i]==']')
        {
            if (s.empty())
            {
                return false;
            }
            if (s.top()=='(' && str[i]==')')
            {
                s.pop();
            }
            else if (str[i]=='}' && s.top()=='{')
            {
                s.pop();
            }
            else if (str[i]==']' && s.top()=='[')
            {
                s.pop();
            }
        }
    }

    if (s.empty())
        return true;
    return false;
}
int main()
{
    stack<char> s;
    string str;
    cin>>str;
    bool m=isbalanced(str);
    if (m) {
        cout<<"Expression is balanced";
    }
    else {
        cout<<"Expression not balanced";
    }

    return 0;
}