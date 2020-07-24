/*
Question-Statement
Assume that the value of a = 1, b = 2, c = 3, ... , z = 26. You are given a numeric string S. Write a program to return the list of all possible codes that can be generated from the given string.
*/
#include <iostream>
#include <string>
using namespace std;
char get(int n)
{
    if (n == 1)
        return 'a';
    else if (n == 2)
        return 'b';
    else if (n == 3)
        return 'c';
    else if (n == 4)
        return 'd';
    else if (n == 5)
        return 'e';
    else if (n == 6)
        return 'f';
    else if (n == 7)
        return 'g';
    else if (n == 8)
        return 'h';
    else if (n == 9)
        return 'i';
    else if (n == 10)
        return 'j';
    else if (n == 11)
        return 'k';
    else if (n == 12)
        return 'l';
    else if (n == 13)
        return 'm';
    else if (n == 14)
        return 'n';
    else if (n == 15)
        return 'o';
    else if (n == 16)
        return 'p';
    else if (n == 17)
        return 'q';
    else if (n == 18)
        return 'r';
    else if (n == 19)
        return 's';
    else if (n == 20)
        return 't';
    else if (n == 21)
        return 'u';
    else if (n == 22)
        return 'v';
    else if (n == 23)
        return 'w';
    else if (n == 24)
        return 'x';
    else if (n == 25)
        return 'y';
    else if (n == 26)
        return 'z';
    return ' ';
}

void getCodes(string input, string output)
{
    if (input[0] == '\0')
    {
        cout << output << endl;
        return;
    }
    int first = int(input[0] - 48);
    char helper1 = get(first);
    getCodes(input.substr(1), output + helper1);
    if (input[1] != '\0')
    {
        int second = int(input[1] - 48);
        char helper2 = get(first * 10 + second);
        if (first * 10 + second >= 10 && first * 10 + second <= 26)
        {
            getCodes(input.substr(2), output + helper2);
        }
    }
}

int main()
{

    string input;
    cin >> input;
    getCodes(input, "");
    return 0;
}
