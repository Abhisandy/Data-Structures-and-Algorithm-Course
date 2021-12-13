#include<iostream>
#include<vector>

using namespace std;


vector<int> maxInWindow(vector<int> input,int k){
    	
   	vector<int> res; 	
    for(int i=0;i<=input.size()-k;i++){

    	int max = input[i];

    	for(int j=i+1;j<=i+k-1;j++){
    		if(input[j]>max){
    			max=input[j];
    		}
    	}
    	res.push_back(max);
    }
    return res;
}



int main(){
	vector<int> arr {1,2,3,1,4,5,2,3,6};
	int k = 3;
	auto res = maxInWindow(arr, k);
	for(int i: res){
		cout<<i<<",";
	}
	return 0;
}