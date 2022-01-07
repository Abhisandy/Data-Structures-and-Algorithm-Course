#include<bits/stdc++.h>

using namespace std;


pair<int,int> search(int m, int n, vector<vector<int>> v, int k){

	int i=m-1;
	int j=0;
	pair<int, int> res;

	while(i>=0 and j<n){
		if(v[i][j]==k){
			break;
		}    	
		else if(v[i][j]<k){
			j++;
		}
		else if(v[i][j]>k){
			i--;
		}
     }
	res.first = i;
    res.second = j;
    return res;
}





int main(){

	int a;
	int b;
	cin>>a>>b;
	vector<vector<int>> arr(a, vector<int> (b));
	for(int i=0;i<a;i++){
		for(int j=0;j<b;j++){
			cin>>arr[i][j];
		}
	}

	int k = 10;
	auto res = search(a, b, arr, k);
	cout<<res.first<<"--"<<res.second;

	return 0;
}