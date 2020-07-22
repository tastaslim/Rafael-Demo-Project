#include <iostream>
using namespace std;
// Using XOR Operator
int FindUnique(int arr[], int size)
{
   int num = 0;
   for (int i = 0; i < size; i++)
   {
      num = num ^ arr[i];
   }
   return num;
}
int main()
{
   int size;
   cin >> size;
   int *arr = new int[size];
   for (int i = 0; i < size; i++)
   {
      cin >> arr[i];
   }
   int ans = FindUnique(arr, size);
   cout << ans << endl;
   return 0;
}
