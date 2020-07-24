#include <iostream>
#include <string>
using namespace std;

int printPermutations(string input, string output[])
{
    if (input[0] == '\0')
    {
        output[0] = "";
        return 1;
    }
    int k = 0;
    string output1[1000];
    for (int i = 0; input[i] != '\0'; i++)
    {
        string m = input.substr(0, i);
        string n = input.substr(i + 1);
        int ans = printPermutations(m + n, output1);
        for (int j = 0; j < ans; j++)
        {
            output[k++] = input[i] + output1[j];
        }
    }
    return k;
}

int main()
{
    string input;
    cin >> input;
    string output[1000];
    int ans = printPermutations(input, output);
    for (int i = 0; i < ans; i++)
    {
        cout << output[i] << endl;
    }
    return 0;
}
