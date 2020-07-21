#include <iostream>
using namespace std;
bool checkNumber(int input[], int size, int x)
{
    if (size == 0)
        return false;
    if (input[size - 1] == x)
        return true;
    bool m = checkNumber(input, size - 1, x);
    return m;
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

    int x;

    cin >> x;

    if (checkNumber(input, n, x))
    {
        cout << "true" << endl;
    }
    else
    {
        cout << "false" << endl;
    }
}
