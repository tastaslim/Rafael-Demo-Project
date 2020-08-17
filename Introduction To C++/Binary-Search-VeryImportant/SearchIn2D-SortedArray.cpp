#include <bits/stdc++.h>
using namespace std;
int main()
{
    int row, col;
    cin >> row >> col;
    int arr[row][1000];
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cin >> arr[i][j];
        }
    }
    int i = 0, j = col - 1;
    int x;
    cin >> x;
    while (i >= 0 && i < row && j >= 0 && j < col)
    {
        if (arr[i][j] < x)
        {
            i++;
        }
        else if (arr[i][j] > x)
        {
            j--;
        }
        else
        {
            cout << i << " " << j << endl;
            break;
        }
    }
    return 0;
}