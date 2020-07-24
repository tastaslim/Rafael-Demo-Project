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
        string a = input.substr(0, i);
        string b = input.substr(i + 1);
        printPermutations(a + b, output + input[i]);
    }
}

int main()
{
    string input;
    cin >> input;
    printPermutations(input, "");
    return 0;
}
