#include <bits/stdc++.h>
using namespace std;
#define ll long long int
// O(2^n) Approach
ll fibo(int n)
{
    if (n <= 1)
    {
        return n;
    }
    return fibo(n - 1) + fibo(n - 2);
}

// T(n)= O(n) && S(n)=O(n) Approach
//Recursive
ll fibo1(int n, int *dp)
{
    if (n <= 1)
        return n;
    int ans1 = 0, ans2 = 0;
    if (dp[n - 1] == -1)
    {
        ans1 = fibo1(n - 1, dp);
        dp[n - 1] = ans1;
    }
    else
    {
        ans1 = dp[n - 1];
    }

    if (dp[n - 2] == -1)
    {
        ans2 = fibo1(n - 2, dp);
        dp[n - 2] = ans2;
    }
    else
    {
        ans2 = dp[n - 2];
    }

    return ans1 + ans2;
}

ll fiboAns(int n)
{
    int *dp = new int[n + 1];
    for (int i = 0; i <= n; i++)
    {
        dp[i] = -1;
    }
    int ans = fibo1(n, dp);
    return ans;
}
// O(n) Iterative

ll IterativeFibo(int n)
{
    int *dp = new int[n + 1];
    dp[0] = 0, dp[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}
int main()
{
    int n;
    cin >> n;
    ll ans = fiboAns(n);
    ll ans1 = IterativeFibo(n);
    cout << ans1 << endl;
    cout << ans << endl;
    ll ans2 = fibo(n);
    cout << ans2 << endl;
    return 0;
}
