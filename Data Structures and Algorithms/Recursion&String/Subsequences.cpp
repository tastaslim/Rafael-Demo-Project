#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int Subsequences(string input, string output[])
{
    if (input[0] == '\0')
    {
        output[0] = "";
        return 1;
    }
    string next = input.substr(1);
    int k = Subsequences(next, output);
    for (int i = 0; i < k; i++)
    {
        output[i + k] = input[0] + output[i];
    }
    return 2 * k;
}
int Subsequences(string input)
{
    string output[10000];
    int k = Subsequences(input, output);
    return k;
}

int main()
{
    string input;
    cin >> input;
    string output[10000];
    int count = Subsequences(input, output);
    for (int i = 0; i < count && i < 10000; i++)
    {
        cout << output[i] << endl;
    }
    return 0;
}
