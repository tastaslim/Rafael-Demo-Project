#include <iostream>
using namespace std;
void LastIndexOfNumberHelper(int input[], int n, int number, int start, int &k, int output[])
{
    if (start == n)
        return;
    if (input[start] == number)
    {
        output[k++] = start;
    }
    LastIndexOfNumberHelper(input, n, number, start + 1, k, output);
}
int LastIndexOfNumber(int input[], int n, int number, int output[])
{
    int k = 0;
    LastIndexOfNumberHelper(input, n, number, 0, k, output);
    return k;
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
    int r = LastIndexOfNumber(input, n, number, output);
    for (int i = 0; i < r; i++)
    {
        cout << output[i] << " ";
    }
    return 0;
}
