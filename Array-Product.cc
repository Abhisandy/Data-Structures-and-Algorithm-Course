#include<iostream>
#include<vector>

using namespace std;

vector<int> product(vector<int> arr){

	int n =  arr.size();
	vector<int> output(n,1);
	int Prod = 1;
	for(int i=0;i<n;i++){

		output[i] = Prod;
		Prod *= arr[i];
	}

	Prod = 1;
	for(int i=n-1;i>=0;i--){

		output[i] *= Prod ;
		Prod *= arr[i];

	}
	return output;
}


int main(){

	vector<int> arr = {1,2,3,4,5};
	auto res= product(arr);
	for(int i:res){
		cout<<i<<endl;
	}
	return 0;
}