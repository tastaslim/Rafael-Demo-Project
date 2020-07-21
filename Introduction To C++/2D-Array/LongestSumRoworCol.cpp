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
	int Rowsum=0,Colsum=0,Rowno=0,Colno=0;
   
   //Row Wise Sum

	for(int i=0;i<row;i++){
	    int sum=0;
		for(int j=0;j<col;j++){
			sum+=arr[i][j];
		}
		if(sum>Rowsum){
			Rowsum=sum;
			Rowno=i;
		}
	}
	

   //Column Wise Sum
   
   for(int i=0;i<col;i++){
	    int sum=0;
		for(int j=0;j<row;j++){
			sum+=arr[j][i];
		}
		if(sum>Colsum){
			Colsum=sum;
			Colno=i;
		}
	}

    //Checks whether row or column is Zero and makes Sum to -INT_MIN
    if(row==0 || col==0){
        Rowsum=INT_MIN;
        Colsum=INT_MIN;
    }


	if(Rowsum>=Colsum){
		cout<<"Row "<<Rowno<<" "<<Rowsum<<endl;
	}
	else{
		cout<<"Col "<<Colno<<" "<<Colsum<<endl;
	}
	
	return 0;
}