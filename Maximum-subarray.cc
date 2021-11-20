#include<iostream>
#include<vector>

using namespace std;

int max_sum(vector<int> arr){

	int n = arr.size();
	int sum = 0;
	int sum_till_now = 0;
	for(int i=0;i<n;i++){

		sum = sum + arr[i];
		if(sum_till_now < sum){

			sum_till_now = sum;
		}
		else if(sum<0){

			sum = 0;
		}
	}
	return sum_till_now;
}



int main(){

	vector<int> arr = {-1,2,3,4,-8,6,-8,3};
	auto res = max_sum(arr);
	cout<<res;
}