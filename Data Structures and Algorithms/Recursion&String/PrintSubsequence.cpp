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
    string helper = input.substr(1);
    Subsequences(helper, output);
    Subsequences(helper, output + input[0]);
}
int main()
{
    string input;
    cin >> input;
    string output;
    Subsequences(input, output);
    return 0;
}
