#include<bits/stdc++.h>

using namespace std;

void print(int n , int mat[][20]){
	for(int i=0; i<n; i++){
		for(int j=0;j<n; j++){
			cout<<mat[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
}

bool canplace(int mat[][20], int n, int x, int y){

	//column
	for(int k=0;k<x;k++){
		if(mat[k][y]==1){
			return false;
		}
	}

	//left diagnal
	int i = x;
	int j = y;
	while(i>=0 and j>=0){
		if(mat[i][j]==1){
			return false;
		}
		i--;
		j--;
	}

	//right diagnal
	i=x;
	j=y;
	while(i>=0 and j<n){
		if(mat[i][j]==1){
			return false;
		}
		i--;
		j++;
	}

	return true;
}







bool solve(int n, int mat[][20], int i){

	if(i==n){                  //base
		print(n, mat);
		return true; 
	}

	for(int j=0;j<n;j++){

		if(canplace(mat, n, i, j)){
			mat[i][j] = 1;
			bool success = solve(n, mat, i+1);
			if(success){
				return true;
			}
			mat[i][j] = 0;
		}
	}
	return false;
}



int main(){

	int arr[20][20] = {0};
	int n = 4;
	solve(n, arr, 0);   //n, arr, i

	return 0;
}