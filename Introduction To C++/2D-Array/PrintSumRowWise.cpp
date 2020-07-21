#include <iostream>
#include<algorithm>
using namespace std;
int main(){
	int row,col;
	cin>>row>>col;
	int **arr=new int*[row];
	for(int i=0;i<row;i++){
		arr[i]=new int[col];
		for(int j=0;j<col;j++){
			cin>>arr[i][j];
		}
	}
	for(int i=0;i<row;i++){
	    int sum=0;
		for(int j=0;j<col;j++){
			sum+=arr[i][j];
		}
		cout<<sum<<endl;
	}
	return 0;
}