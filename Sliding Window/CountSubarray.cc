#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;


int cntSubarrays(vector<int>arr,int sum){

 	unordered_map<int,int> um;
 	int checkSum = 0;
 	int count = 0;

 	for(int i=0;i<arr.size();i++){

		checkSum+=arr[i]; 
		if(checkSum==sum){
			count++;
		}

		if(um.find(checkSum-sum)!=um.end()){
			count += um[checkSum-sum];
		}

		um[checkSum]++;
 	}
    return count;
}




int main(){
	vector<int> arr {10, 2, -2, -20, 10};
	int k = -10;
	auto res = cntSubarrays(arr, k);
	cout<<res;	
	return 0;
}
