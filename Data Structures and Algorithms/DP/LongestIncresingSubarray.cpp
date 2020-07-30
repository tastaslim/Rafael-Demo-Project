#include <iostream>
using namespace std;
void longest(int n, int *a)
{
    int ans = 0, curr = 0, count = 1, res = 1, start = -1, end = -1;
    for (int i = 0; i < n; i++)
    {
        curr = a[i];
        start = i;
        for (int j = i + 1; j < n; j++)
        {
            if (a[j] > curr)
            {
                curr = a[j];
                count = count + 1;
            }
            else
            {
                break;
            }
        }
        if (count > res)
        {
            res = count;
            end = start + count;
        }
        count = 1;
    }
    cout << res;
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    longest(n, arr);
    return 0;
}