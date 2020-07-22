#include <iostream>
using namespace std;
void towerOfHanoi(int n, char start, char middle, char end)
{
    if (n == 0)
        return;
    towerOfHanoi(n - 1, start, end, middle);
    cout << start << " " << end << endl;
    towerOfHanoi(n - 1, middle, start, end);
}
int main()
{
    int n;
    cin >> n;
    towerOfHanoi(n, 'a', 'b', 'c');
}
