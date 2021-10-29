#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> Triplets(vector<int> arr, int sum){
	
	vector<int> res;

	sort(arr.begin(),arr.end());
	int size =  arr.size();
	for(int i=0;i<=size-3;i++){

		int ele = arr[i];
		int rem = sum - arr[i];
		int start = i+1;
		int end = size-1;
		while(start<end){

			if(arr[start]+arr[end]==rem){

				//cout<<arr[i]<<","<<arr[start]<<","<<arr[end]<<endl;
				res.push_back(arr[i]);
				res.push_back(arr[start]);
				res.push_back(arr[end]);
				start++;
				end--;
			}
			else if(arr[start]+arr[end]<rem){

				start++;
			}
			else if(arr[start]+arr[end]>rem){

				end--;
			}

		}
	}
	return res;

}

int main(){
	vector<int> a  {15,2,3,4,5,6,7,8,9,1};
	int sum = 18;
	vector<int> resu = Triplets(a, sum);
	for(int i=0;i<resu.size();i=i+3){

		cout<<resu[i]<<","<<resu[i+1]<<","<<resu[i+2]<<endl;
	}
	return 0;
}