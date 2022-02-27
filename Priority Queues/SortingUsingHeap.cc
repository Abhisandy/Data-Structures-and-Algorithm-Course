#include<bits/stdc++.h>

using namespace std;

void Heap(int *arr, int n){
	priority_queue<int> heap;        // Gives Decending Order
//    for min heap use priority_queue<int, vector<int>, greater<int>> heap;                         
	for(int x=0; x<n; x++){
		heap.push(arr[x]);
	}

	while(!heap.empty()){
		cout<<heap.top()<<endl;
		heap.pop();
	}
}

int main(){

	int arr[] = {1,2,3,4,5,6,7,8};
	int n = sizeof(arr)/sizeof(int);
	Heap(arr, n);

	return 0;
}