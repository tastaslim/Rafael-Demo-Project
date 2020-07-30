#include <bits/stdc++.h>
using namespace std;

//Normal Approach O(2^n)

/*int countStepsToOne(int n)
{
    if (n == 1)
        return 0;
    int ans1 = INT_MAX, ans2 = INT_MAX, ans3 = INT_MAX;
    ans1 = countStepsToOne(n - 1);
    if (n % 2 == 0)
        ans2 = countStepsToOne(n / 2);
    if (n % 3 == 0)
        ans3 = countStepsToOne(n / 3);

    int ans = 1 + min(ans1, min(ans2, ans3));
    return ans;
}*/

// Using Recursive DP --->> T(n)=O(n), S(n)=O(n)

/*int countStepsToOne(int n, int *dp)
{
    if (n == 1)
        return 0;
    int ans1 = INT_MAX, ans2 = INT_MAX, ans3 = INT_MAX;
    if (dp[n - 1] == -1)
    {
        ans1 = countStepsToOne(n - 1, dp);
        dp[n - 1] = ans1;
    }
    else
    {
        ans1 = dp[n - 1];
    }

    if (n % 2 == 0)
    {
        if (dp[n / 2] == -1)
        {
            ans3 = countStepsToOne(n / 2, dp);
            dp[n / 2] = ans3;
        }
        else
        {
            ans3 = dp[n / 2];
        }
    }
    if (n % 3 == 0)
    {
        if (dp[n / 3] == -1)
        {
            ans3 = countStepsToOne(n / 3, dp);
            dp[n / 3] = ans3;
        }
        else
        {
            ans3 = dp[n / 3];
        }
    }

    int ans = 1 + min(ans1, min(ans2, ans3));
    return ans;
}*/

/*int countStepsToOne(int n)
{
    int *dp = new int[n + 1];
    for (int i = 0; i <= n; i++)
    {
        dp[i] = -1;
    }
    int ans = countStepsToOne(n, dp);
    return ans;
}*/

// Using Iterative DP --->> T(n)=O(n), S(n)=O(n)
int countStepsToOneDPIterative(int n)
{
    int *dp = new int[n + 1];
    for (int i = 0; i <= n; i++)
    {
        dp[i] = INT_MAX;
    }
    dp[1] = 0;
    dp[2] = 1;
    dp[3] = 1;
    int b = INT_MAX, c = INT_MAX;
    for (int i = 4; i <= n; i++)
    {
        int a = INT_MAX, b = INT_MAX, c = INT_MAX;
        a = dp[i - 1];
        if (i % 2 == 0)
        {
            b = dp[i / 2];
        }
        if (i % 3 == 0)
        {
            c = dp[i / 3];
        }

        dp[i] = 1 + min(a, min(b, c));
    }
    return dp[n];
}

int main()
{
    int n;
    cin >> n;
    //int ans = countStepsToOne(n);
    int ans1 = countStepsToOneDPIterative(n);
    //cout << ans << endl;
    cout << ans1 << endl;
    return 0;
}