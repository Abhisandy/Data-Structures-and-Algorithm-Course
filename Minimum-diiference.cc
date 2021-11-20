#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>

using namespace std;

pair<int,int> diff(vector<int> arr1, vector<int> arr2){
	pair<int, int> elements;

	int n = arr1.size();
	sort(arr1.begin(), arr1.end());
	sort(arr2.begin(), arr2.end());
	int i=0;
	int j=0;
	int res_i = 0;
	int res_j = 0;
	int Diff = INT_MAX;
	for(int k=0;k<n;k++){
		int val = abs(arr1[i]-arr2[j]);
		if(val<Diff){

			Diff = val;
			res_i = i;
			res_j = j;
		}
		if(arr1[i]<arr2[j]){

			i++;
		}
		else if(arr1[i]>arr2[j]){

			j++;
		}

	}
	elements.first = arr1[res_i];
	elements.second = arr2[res_j];

	return elements;

}


int main(){

	vector<int> arr1 = {23,5,10,15,30};
	vector<int> arr2 = {26,134,135,14,19};
	auto res = diff(arr1, arr2);
	cout<<res.first<<"--"<<res.second;
	return 0;
}