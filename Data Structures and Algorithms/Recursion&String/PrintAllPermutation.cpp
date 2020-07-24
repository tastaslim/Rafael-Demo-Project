#include <iostream>
#include <string>
using namespace std;

void printPermutations(string input, string output)
{
    if (input[0] == '\0')
    {
        cout << output << endl;
        return;
    }
    for (int i = 0; input[i] != '\0'; i++)
    {
        string m = input.substr(0, i);
        string n = input.substr(i + 1);
        printPermutations(m + n, output + input[i]);
    }
}

void printPermutations(string input)
{
    printPermutations(input, "");
}

int main()
{
    string input;
    cin >> input;
    printPermutations(input);
    return 0;
}
