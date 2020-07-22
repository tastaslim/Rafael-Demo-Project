#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

//Problem with this approach is T(n)=nlogn and order of elements changes
// int main(){
//     int m,n;
//     cin>>m>>n;
//     int *arr1=new int[m];
//     for(int i=0;i<m;i++)
//     {
//         cin>>arr1[i];
//     }
//     int *arr2=new int[n];
//     for(int i=0;i<n;i++)
//     {
//         cin>>arr2[i];
//     }

//     sort(arr1,arr1+m);
//     sort(arr2,arr2+n);
//     int i=0,j=0;
//     while(i<m && j<n){
//     	if(arr1[i]>arr2[j]){
//     		j++;
//     	}
//     	else if(arr1[i]<arr2[j]){
//     		i++;
//     	}
//     	else{
//     		cout<<arr1[i]<<" ";
//     		i++,j++;
//     	}
//     }

// }

int main()
{
    int m, n;
    cin >> m >> n;
    int *arr1 = new int[m];
    for (int i = 0; i < m; i++)
    {
        cin >> arr1[i];
    }
    int *arr2 = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr2[i];
    }

    //Useful when order is according to Arrray 2

    /* unordered_map<int,int> mp;
    for(int i=0;i<m;i++){
    	mp[arr1[i]]++;
    }
    for(int i=0;i<n;i++){
    	if(mp[arr2[i]]>=1){
    		cout<<arr2[i]<<" ";
    		mp[arr2[i]]--;
    	}
    }
    */

    //Useful when order is according to Arrray 1

    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        mp[arr2[i]]++;
    }
    for (int i = 0; i < m; i++)
    {
        if (mp[arr1[i]] >= 1)
        {
            cout << arr1[i] << " ";
            mp[arr1[i]]--;
        }
    }
}