#include<bits/stdc++.h>

using namespace std;

void maxSubarry(vector<int> arr, int k){

	deque<int> Q(k);   //K size DeQue
	int i =0;
	for(i=0;i<k;i++){   //first k elements

		while(!Q.empty() and arr[i] > arr[Q.back()]){  //storing indexes in Deque not values

			Q.pop_back();
		}
		Q.push_back(i);
	}

	for(;i<arr.size();i++){  //next elements(after first k)

		cout<<arr[Q.front()]<<" ";

		//checking if left element is out of window
		while(!Q.empty() and Q.front() <= i-k){
			Q.pop_front();
		}
		while(!Q.empty() and arr[i] > arr[Q.back()]){
			Q.pop_back();
		}
		//Always
		Q.push_back(i);
	}
}







int main(){


	vector<int> arr {1, 2, 3, 1, 4, 5, 2, 3, 5};
	int k = 3;
	maxSubarry(arr, k);
}