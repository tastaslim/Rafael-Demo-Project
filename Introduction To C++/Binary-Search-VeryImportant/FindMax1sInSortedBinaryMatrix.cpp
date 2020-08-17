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
    int max = 0;
    for (int i = 0; i < row; i++)
    {
        int start = arr[i][0], end = arr[i][col - 1];
        while (start <= end)
        {
            int mid = start + (end - start) / 2;
            if (arr[i][mid] == 1)
            {
                end = mid - 1;
            }
            else
            {
                start = mid + 1;
            }
        }
        int k = col - start;
        if (max < k)
        {
            max = k;
        }
    }
    cout << max << endl;
    return 0;
}