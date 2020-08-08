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
            if (str[i]==')')
            {
                if (s.top()=='(')
                    s.pop();
                else
                    return false;
            }
            else if (str[i]=='}')
            {
                if (s.top()=='{')
                    s.pop();
                else
                    return false;
            }
            else if (str[i]==']')
            {
                if (s.top()=='[')
                    s.pop();
                else
                    return false;
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