#include <iostream>
using namespace std;
double myPow(double x, int n)
{
    double ans = 0;

    if (n >= 0)
    {
        if (n == 0)
            return 1.00000;
        double rec = myPow(x, n / 2);
        if (n % 2 == 0)
            ans = rec * rec;
        else
            ans = rec * rec * x;
    }
    else
    {
        long long int m = -1.0 * n;
        if (m == 0)
            return 1;
        double rec = myPow(x, m / 2);
        if (n % 2 == 0)
            ans = (1.0 * 1) / (rec * rec);
        else
            ans = (1.0 * 1) / (x * rec * rec);
    }
    return ans;
}
int main()
{
    double x, y;
    cin >> x >> y;
}