#include<iostream>
#include <algorithm>
using namespace std;
void sumOfTwoArrays(int a[], int n, int b[], int m, int output[])
{
    int resultant;
    if(m>=n)
		resultant=m;
	else
	   resultant=n;
	int s=n-1,t=m-1;
	int k=resultant;
	int sum;
	int carry=0;
	while(k>=0)
 {
    sum=0;
    if(s<0 && t<0)
       sum=carry;
	else if(s<0)
	   sum=b[t--]+carry;
	else if(t<0)
	   sum=a[s--]+carry;
	else
	sum=a[s--]+b[t--]+carry;
	if(sum>9)
	{
	output[k--]=sum%10;
	carry=1;	
	}
	else
	{
		output[k--]=sum;
		carry=0;
	}	
 }
}
int main()
{
	int t;
	cin >> t;

	while (t--)
	{
		int size1;
		cin >> size1;

		int *input1 = new int[size1];

		for (int i = 0; i < size1; ++i)
		{
			cin >> input1[i];
		}

		int size2;
		cin >> size2;

		int *input2 = new int[size2];

		for (int i = 0; i < size2; ++i)
		{
			cin >> input2[i];
		}

		int outsize = 1 + max(size1, size2);

		int *output = new int[outsize];

		sumOfTwoArrays(input1, size1, input2, size2, output);

		for (int i = 0; i < outsize; ++i)
		{
			cout << output[i] << " ";
		}

		delete[] input1;
		delete[] input2;
		delete[] output;
		cout << endl;
	}

	return 0;
}