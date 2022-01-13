#include<bits/stdc++.h>

using namespace std;

void greed(vector<int> arr, int k){

	int n = arr.size(); 
	int s = 0;   //search space
	int e = accumulate(arr.begin(), arr.end(), 0);
	int ans = -1;

	while(s<=e){

		int mid = (s+e)/2;
		int num = k;
		int sum = 0;

		for(int i=0;i<n;i++){
			sum += arr[i];

			if(sum>=mid){
				num--;
				sum = 0;
			}
		}

		if(num<=0){
			s = mid+1;
			ans = mid;
		}
		else{
			e = mid - 1;
		}

	}
	cout<<ans;
}







int main(){
	vector<int> arr{1,2,3,4};
	int k = 3;
	greed(arr, k);
	return 0;
}