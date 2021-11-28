#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

int LargestBand(vector<int> arr){

	int maxi = 0;
	unordered_set<int> ele(arr.begin(), arr.end());
	for(int i:ele){

		int len = 0;
		if(ele.find(i-1)!=ele.end()){   //previous element found in unordered set

			continue;
		}
		else{                           //this is the starting of Band
		        
			int j=i;
			while(ele.find(j+1)!=ele.end()){
				len++;
				j++;
			}
		}
		maxi = max(maxi,len);
	}

	return maxi+1;                      //+1 for the starting(not included in while)
}

int main(){

	vector<int> arr {1,9,3,0,18,5,2,4,10,7,12,6};
	int res  = LargestBand(arr);
	cout<<res;
	return 0;
}