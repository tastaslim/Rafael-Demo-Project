#include <iostream>
using namespace std;
int LastIndexOfNumber(int input[], int n, int number)
{
    if (n == 0)
        return -1;
    if (input[n - 1] == number)
    {
        return n - 1;
    }
    return LastIndexOfNumber(input, n - 1, number);
}
int main()
{
    int n;
    cin >> n;

    int *input = new int[n];

    for (int i = 0; i < n; i++)
    {
        cin >> input[i];
    }
    int number;
    cin >> number;
    cout << LastIndexOfNumber(input, n, number) << endl;
}
