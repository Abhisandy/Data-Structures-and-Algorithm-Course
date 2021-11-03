#include<iostream>
#include<vector>
using namespace std;

int Rain(vector<int> arr){

	int size = arr.size();
	int left[size];
	int right[size];
	int max = 0;
	for(int i=0;i<size;i++){

		if(arr[i]>max){

			max=arr[i];
			left[i]=max;
		}
		else{

			left[i]=max;
		}
	}
	max = 0;
	for(int i=size-1;i>=0;i--){

		if(arr[i]>max){

			max = arr[i];
			right[i]=max;
		}
		else{

			right[i]=max;
		}
	}
	int fill = 0;
	for(int i=0;i<size;i++){

		fill += min(left[i],right[i])-arr[i];
	}
	return fill;
}

int main(){

	vector<int> arr  {0,1,0,2,1,0,1,3,2,1,2,1};
	int res = Rain(arr);
	cout<<res;
	return 0;
}