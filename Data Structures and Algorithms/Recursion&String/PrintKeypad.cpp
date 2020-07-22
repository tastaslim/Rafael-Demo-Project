#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string helper(int n)
{
    switch (n)
    {
    case 2:
        return "abc";
        break;
    case 3:
        return "def";
        break;
    case 4:
        return "ghi";
        break;
    case 5:
        return "jkl";
        break;
    case 6:
        return "mno";
        break;
    case 7:
        return "pqrs";
        break;
    case 8:
        return "tuv";
        break;
    case 9:
        return "wxyz";
        break;
    default:
        return "";
        break;
    }
}

void keypad(int num, string output)
{
    if (num == 0)
    {
        cout << output << endl;
        return;
    }
    int last = num % 10;

    string lastStr = helper(last);
    int len = lastStr.length();
    for (int i = 0; i < len; i++)
    {
        keypad(num / 10, lastStr[i] + output);
    }
}

int main()
{
    int num;
    cin >> num;
    string output;
    keypad(num, output);
    return 0;
}
