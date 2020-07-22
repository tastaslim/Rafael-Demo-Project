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
        return " ";
        break;
    }
}
//Approach 1. It requires an Extra Space---> Space Complexity==> O(n)
/*int keypad(int num, string output[])
{
    if (num == 0)
    {
        output[0] = "";
        return 1;
    }
    int last = num % 10;
    string lastStr = helper(last);
    int len = lastStr.length();
    string extra[1000];
    int k = keypad(num / 10, extra);
    int l = 0;
    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < len; j++)
        {
            output[l++] = extra[i] + lastStr[j];
        }
    }
    return l;
}*/

//Approach 2 Without any Extra Space
int keypad(int num, string output[])
{
    if (num == 0)
    {
        output[0] = "";
        return 1;
    }
    int last = num % 10;
    string lastString = helper(last);
    // cout << lastString;
    int recursionPart = num / 10;
    int recursionOutput = keypad(recursionPart, output);
    int l = recursionOutput;
    // Make lastString.length()-1 copies of output coming from recursion.
    // Because we have already One copy which is output of recursion itself
    for (int i = 0; i < lastString.length() - 1; i++)
    {
        for (int j = 0; j < recursionOutput; j++)
        {
            output[l++] = output[j];
        }
    }
    int k = 0;

    for (int i = 0; i < lastString.length(); i++)
    {
        for (int j = 0; j < recursionOutput; j++)
        {
            output[k] = output[k] + lastString[j];
            k++;
        }
    }
    return k;
}
int main()
{
    int num;
    cin >> num;

    string output[10000];
    int count = keypad(num, output);
    for (int i = 0; i < count && i < 10000; i++)
    {
        cout << output[i] << endl;
    }
    return 0;
}
