#include<iostream>
#include<vector>
#include<climits>
using namespace std;

pair<int, int> subarray(vector<int> arr){

	int smallest = INT_MAX;
	int largest = INT_MIN;
	int size = arr.size();
	for(int i=0;i<size;i++){

		if(i==0){

			if(arr[i]>arr[i+1]){

				smallest = min(smallest,arr[i]);
			}
		}
		if(i==size-1){

			if(arr[i]<arr[i-1]){

				largest = max(largest,arr[i]);
			}
		}
		else{

			if((arr[i-1]>arr[i]) or (arr[i]>arr[i+1])){

				smallest = min(smallest, arr[i]);
				largest = max(largest, arr[i]);
			}
		}
		
	}
	//cout<<smallest<<"--"<<largest<<endl;

	int j=0;
	int left=0;
	int right = size-1;;
	while(smallest>arr[j]){

		left++;
		j++;
	}
	j=size-1;
	while(largest<arr[j]){

		right--;
		j--;
	}      //to find correct place of smallest and largest

	return {left,right};
}

int main(){

	vector<int> arr {1,2,3,4,5,8,6,7,9,10,11};
	auto p = subarray(arr);
	cout<<p.first<<"--"<<p.second;
}