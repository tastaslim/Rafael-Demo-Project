#include <iostream>
using namespace std;
void countZeroHelper(int n, int &k)
{
    if (n == 0)
    {
        return;
    }
    if (n % 10 == 0)
    {
        k++;
    }
    countZeroHelper(n / 10, k);
}
int countZero(int n)
{
    int k = 0;
    if (n == 0)
    {
        return 1;
    }
    else
    {
        countZeroHelper(n, k);
    }
    return k;
}
int main()
{
    int n;
    cin >> n;
    int ans = countZero(n);
    cout << ans << endl;
    return 0;
}
