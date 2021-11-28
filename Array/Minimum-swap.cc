#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int Swaps(vector<int> arr){
	int n=arr.size();
	int swaps = 0;
	pair<int,int> ap[n];
	for(int i=0;i<n;i++){

		ap[i].first = arr[i];
		ap[i].second = i;
	}
	sort(ap,ap+n);


	vector<bool> flag(n, false);
	for(int i=0;i<n;i++){

		if(flag[i]==true or ap[i].second==i){

			continue;
		}
		int count = 0;
		int node = i;

		while(flag[node]==false){

			flag[node]=true;
			int next = ap[i].first;
			node = ap[node].second;
			count = count + 1;
		}
		
		swaps += (count-1);
	}
	return swaps;

}

int main(){

	vector<int> arr = {5,4,3,2,1};
	auto res = Swaps(arr);
	cout<<res;
	return 0;
}