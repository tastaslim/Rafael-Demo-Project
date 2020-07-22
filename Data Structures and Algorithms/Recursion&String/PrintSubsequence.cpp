#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
void Subsequences(string input, string output)
{
    if (input[0] == '\0')
    {
        cout << output << endl;
        return;
    }
    string next = input.substr(1);
    Subsequences(next, output);
    Subsequences(next, output + input[0]);
}
int main()
{
    string input;
    cin >> input;
    string output;
    Subsequences(input, output);
    return 0;
}
