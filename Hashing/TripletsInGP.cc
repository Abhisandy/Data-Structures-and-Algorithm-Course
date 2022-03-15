#include<bits/stdc++.h>
using namespace std;





int triplets(vector<int> arr, int r){

	int n = arr.size();
	unordered_map<long, long> right, left;

	for(auto x: arr){
		right[x]++;
		left[x] = 0;
	}

	int ans=0;
	for(int i=0; i<n; i++){

		right[arr[i]]--;
		if(arr[i]%r==0){  //checking if it is dicisible by r or not (coz we need to find a/r)
			long b = arr[i];
			long a = arr[i]/r;
			long c = arr[i]*r;

			ans += left[a] * right[c];
		}
		left[arr[i]]++;
	}
	return ans;
}


int main(){
	
	vector<int> arr{1,16,4,16, 64, 16};  //ans=3
	int r = 4;
	auto res = triplets(arr, r);
	cout<<res;
 	return 0;
}