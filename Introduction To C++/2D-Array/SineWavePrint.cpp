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
	bool m=true;
	for(int i=0;i<col;i++){
		for(int j=0;j<row;j++){
			if(m){
				cout<<arr[j][i]<<" ";
				m=false;
			}
			else{
				cout<<arr[row-1-j][i]<<" ";
				m=true;
			}

		}
	}
	return 0;
}