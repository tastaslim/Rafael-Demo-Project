// Question Statement
/*
Suppose you have a string, S, made up of only 'a's and 'b's. Write a recursive function that checks if the string was generated using the following rules:

a. The string begins with an 'a'
b. Each 'a' is followed by nothing or an 'a' or "bb"
c. Each "bb" is followed by nothing or an 'a'

If all the rules are followed by the given string, return true otherwise return false.
*/

#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
bool checkAB(char *input)
{
    if (input[0] == '\0')
        return true;
    if (input[0] != 'a')
        return false;
    if (input[1] != '\0' && input[2] != '\0')
    {
        if (input[1] == 'b' && input[2] == 'b')
        {
            return checkAB(input + 3);
        }
    }
    return checkAB(input + 1);
}
int main()
{
    char input[1000000];
    cin >> input;
    bool m = checkAB(input);
    if (m)
    {
        cout << "Follows Given Condition";
    }
    else
    {
        cout << "Do not Follow Given Condition";
    }
}