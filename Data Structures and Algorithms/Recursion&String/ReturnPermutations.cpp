#include <iostream>
#include <string>
using namespace std;

int returnPermutations(string input, string output[])
{
    if (input[0] == '\0')
    {
        output[0] = "";
        return 1;
    }
    string arr[1000];
    int l = 0;
    for (int i = 0; input[i] != '\0'; i++)
    {
        string a = input.substr(0, i);
        string b = input.substr(i + 1);
        int k = returnPermutations(a + b, arr);
        for (int j = 0; j < k; j++)
        {
            output[l] = input[i] + arr[j];
            l = l + 1;
        }
    }
    return l;
}

int main()
{
    string input;
    cin >> input;
    string output[1000];
    int ans = returnPermutations(input, output);
    for (int i = 0; i < ans; i++)
    {
        cout << output[i] << endl;
    }
    return 0;
}
