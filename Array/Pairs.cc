#include<iostream>
#include<unordered_set>
#include<vector>
using namespace std;

vector<int> Pairs(vector<int> arr ,int size, int val){	
	vector<int> res;	
	unordered_set<int> s;
	for(int x=0;x<size;x++){
		int num = val - arr[x];
		if (s.find(num)!=s.end()){
			res.push_back(num);
			res.push_back(arr[x]);
			return res;
		}

		s.insert(arr[x]);

	}
	return res;
}


int main(){
	vector<int> arr = {10,5,2,3,-6,9,11};
	vector<int> resu = Pairs(arr, 7 , 4);
	for(int x:resu){
		cout<<x<<",";
	} 
	return 0;
}