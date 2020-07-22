#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
//Important---->  to make changes in String pass Reference
void RemoveConsecutiveDuplicates(string &s, int start)
{
    if (s[start] == '\0')
    {
        return;
    }
    if (s[start] == s[start + 1])
    {

        for (int i = start; i < s.length(); i++)
        {
            s[i] = s[i + 1];
        }
        start = start - 1;
    }
    RemoveConsecutiveDuplicates(s, start + 1);
}

//It will not make any changes in String

/*
void RemoveConsecutiveDuplicates(string s, int start)
{
    if (s[start] == '\0')
    {
        return;
    }
    if (s[start] == s[start + 1])
    {

        for (int i = start; i < s.length(); i++)
        {
            s[i] = s[i + 1];
        }
        start = start - 1;
    }
    RemoveConsecutiveDuplicates(s, start + 1);
}
*/

int main()
{
    string s;
    cin >> s;
    RemoveConsecutiveDuplicates(s, 0);
    cout << s;
    return 0;
}