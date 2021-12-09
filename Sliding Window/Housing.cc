#include<iostream>
#include<vector>

using namespace std;



vector<pair<int, int>> housing(int *arr, int n, int k){

	vector<pair<int, int>> res;
	int i=0;
	int j=0;
	int cs = 0;

	while(j<n && i<=j){
		if(i==j){
			cs = arr[i];
		}

		if(cs < k){
			j++;
			cs += arr[j];
		}
		else if(cs > k){
			cs -= arr[i];
			i++;
		}

		else if(cs == k){
			res.push_back({i,j});
			j++;
			cs += arr[j];
		}
	}
	return res;

}




int main(){
	int plots[] = {1,3,2,1,4,1,3,2,1,1};       //Remember case when a number greater than K comes in array
	int n = sizeof(plots)/sizeof(int);
	int k = 8;

	auto res = housing(plots,n,k);
	for(int i=0;i<res.size();i++){
		cout<<res[i].first<<"--"<<res[i].second<<endl;
	}

	return 0;
}

