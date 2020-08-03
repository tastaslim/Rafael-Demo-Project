#include <iostream>
using namespace std;
int main()
{

    //These techniques are very useful do remember these.
    int test;
    cin >> test;
    while (test--)
    {
        int n;
        cin >> n;
        int *arr = new int[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        // Takes Extra space
        /*int b[n];
    int start=0,end=n-1;

    for(int i=0;i<n;i++){
        if(arr[i]==1){
            b[end--]=1;
        }
        else{
            b[start++]=0;
        }
    }

    for(int i=0;i<n;i++){
        cout<<b[i]<<" ";
    }
    */

        // Without any extra space
        int k = 0;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] == 0)
            {
                swap(arr[k++], arr[i]);
            }
        }

        for (int i = 0; i < n; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    return 0;
}
