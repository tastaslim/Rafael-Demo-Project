#include <iostream>
using namespace std;
int LastIndexOfNumber(int input[], int n, int number, int start, int &k, int output[])
{
    if (start == n)
        return -1;
    if (input[start] == number)
    {
        output[k++] = start;
    }
    return LastIndexOfNumber(input, n, number, start + 1, k, output);
}
int main()
{
    int n;
    cin >> n;

    int *input = new int[n];
    int *output = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> input[i];
    }
    int number;
    cin >> number;
    int k = 0;
    int r = LastIndexOfNumber(input, n, number, 0, k, output);
    for (int i = 0; i < k; i++)
    {
        cout << output[i] << " ";
    }
    return 0;
}
