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

int keypad(int num, string output[])
{
    if (num == 0)
    {
        output[0] = "";
        return 1;
    }
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
