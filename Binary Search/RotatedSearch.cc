#include<bits/stdc++.h>

using namespace std;


int RotatedSearch(vector<int> arr, int key){
	int n = arr.size();
	int s = 0;
	int e = n-1;

	while(s<=e){
		int mid = (s+e)/2;

		if(arr[mid]==key){
			return mid;
		}

		else if(arr[s]<=arr[mid]){

			if(arr[s]<=key and key<=arr[mid]){
				e = mid-1;
			}
			else{
				s = mid+1;
			}
		}

		else if(arr[mid]<=arr[e]){

			if(arr[mid]<=key and key<=arr[e]){
				s = mid+1;
			}
			else{
				e = mid-1;
			}
		}
	}
	return -1;
}



int main(){
	vector<int> arr{4,5,6,7,0,1,2,3};
	int k = 6;
	cout<<RotatedSearch(arr, k);
	return 0;
}