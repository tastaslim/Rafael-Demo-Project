#include <bits/stdc++.h>
using namespace std;

// Normal/Brute-Force Approach

// int MinSquaresToOne(int n)
// {
//     if (n == 0)
//     {
//         return 0;
//     }
//     int ans = INT_MAX;
//     int curr = 0;
//     for (int i = 1; i * i <= n; i++)
//     {
//         curr = 1 + MinSquaresToOne(n - i * i);
//         if (curr < ans)
//         {
//             ans = curr;
//         }
//     }
//     return ans;
// }

// int main()
// {
//     int n;
//     cin >> n;
//     int ans = MinSquaresToOne(n);
//     cout << ans << endl;
//     return 0;
// }

//MemoIzation Approach O(n*(n^1/2))---> N ROOT N
/*int MinSquaresToOne(int n, int *dp)
{
    if (n == 0)
    {
        return 0;
    }
    int ans = INT_MAX;
    int curr = INT_MAX;
    for (int i = 1; i * i <= n; i++)
    {

        if (dp[n - i * i] == -1)
        {
            curr = 1 + MinSquaresToOne(n - i * i, dp);
            dp[n - i * i] = curr;
        }
        else
        {
            curr = dp[n - i * i];
        }

        if (curr <= ans)
        {
            ans = curr;
        }
    }
    return ans;
}

int main()
{
    int n;
    cin >> n;
    int *dp = new int[n + 1];
    for (int i = 0; i <= n; i++)
    {
        dp[i] = -1;
    }
    int ans = MinSquaresToOne(n, dp);
    cout << ans << endl;
    delete[] dp;
    return 0;
}
*/

int MinSquaresToOneDP(int n)
{
    if (n == 0)
        return 0;
    int *dp = new int[n + 1];
    for (int i = 0; i <= n; i++)
    {
        dp[i] = -1;
    }
    dp[0] = 0;
    for (int i = 1; i <= n; i++)
    {

        int ans = INT_MAX;
        int curr = 0;
        for (int j = 1; j * j <= i; j++)
        {
            curr = 1 + dp[i - j * j];
            if (curr < ans)
            {
                ans = curr;
            }
        }
        dp[i] = ans;
    }
    return dp[n];
}

int main()
{
    int n;
    cin >> n;
    int ans = MinSquaresToOneDP(n);
    cout << ans << endl;
    return 0;
}
