#include <iostream>
using namespace std;
int FirstIndexOfNumberHelper(int input[], int n, int start, int number)
{
    if (start == n)
        return -1;
    if (input[start] == number)
    {
        return start;
    }
    return FirstIndexOfNumberHelper(input, n, start + 1, number);
}
int FirstIndexOfNumber(int input[], int n, int number)
{
    return FirstIndexOfNumberHelper(input, n, 0, number);
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
    cout << FirstIndexOfNumber(input, n, number) << endl;
}
