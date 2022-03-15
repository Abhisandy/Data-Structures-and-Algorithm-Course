#include<bits/stdc++.h>

using namespace std;



int main(){

	priority_queue<int> left_heap;  //max_heap
	priority_queue<int, vector<int>, greater<int>> right_heap; //min_heap

	int d;
	cin>>d;

	left_heap.push(d);   //push first element

	float med = d;
	cout<<med<<" ";


	cin>>d;   //second element rest all inside while
	while(d!=-1){   //-1 to stop

		if(left_heap.size() > right_heap.size()){

			if(d<med){
				right_heap.push(left_heap.top());
				left_heap.pop();
				left_heap.push(d);
			}
			else{
				right_heap.push(d);
			}
			med = (left_heap.top() + right_heap.top())/2.0;
		}
		else if(left_heap.size() < right_heap.size()){

			if(d < med){
				left_heap.push(d);
			}
			else{
				left_heap.push(right_heap.top());
				right_heap.pop();
				right_heap.push(d);
			}
			med = (left_heap.top() + right_heap.top())/2.0;
		}
		else{
			if(d<med){
				left_heap.push(d);
				med = left_heap.top();
			}
			else{
				right_heap.push(d);
				med = right_heap.top();
			}
		}
		cout<<med<<" ";
		cin>>d;
	}
	return 0
;
}


//input: 10 5 2 3 0 12 18 20 22
