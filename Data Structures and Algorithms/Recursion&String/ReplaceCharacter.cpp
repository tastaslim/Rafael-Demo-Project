#include <iostream>
#include <string>
using namespace std;
//Important---->  to make changes in String pass Reference
void ReplaceCharacter(string &s, int start, char old, char New)
{
    if (s[start] == '\0')
    {
        return;
    }
    if (s[start] == old)
    {
        s[start] = New;
    }
    ReplaceCharacter(s, start + 1, old, New);
}

//It will not make any changes in String
/*
  void ReplaceCharacter(string s, int start, char old, char New)
{
    if (s[start] == '\0')
    {
        return;
    }
    if (s[start] == old)
    {
        s[start] = New;
    }
    ReplaceCharacter(s, start + 1, old, New);
}
*/

int main()
{
    string s;
    cin >> s;
    char old, New;
    cin >> old >> New;
    ReplaceCharacter(s, 0, old, New);
    cout << s;
    return 0;
}