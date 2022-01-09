#include<bits/stdc++.h>

using namespace std;


int lower(vector<int> arr, int k){
	int s = 0;
	int ans = -1;
	int e =  arr.size()-1;
	while(s<=e){
		int mid = (s+e)/2;

		if(arr[mid]==k){
			ans = mid;
			e = mid-1;
		}
		else if(arr[mid]<k){
			s = mid+1;
		}
		else{
			e = mid-1;
		}
	}
	return ans;
}

int upper(vector<int> arr, int k){
	int s = 0;
	int ans = -1;
	int e =  arr.size()-1;
	while(s<=e){
		int mid = (s+e)/2;

		if(arr[mid]==k){
			ans = mid;
			s = mid+1;
		}
		else if(arr[mid]<k){
			s = mid+1;
		}
		else{
			e = mid-1;
		}
	}
	return ans;
}




int main(){
	vector<int> arr{0,1,1,2,3,3,3,3,3,4,5,5,5,10};
	auto res = upper(arr,3)-lower(arr, 3) + 1;
	cout<<res;
	return 0;
}