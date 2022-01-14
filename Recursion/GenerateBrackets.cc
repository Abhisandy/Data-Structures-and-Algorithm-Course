#include<bits/stdc++.h>

using namespace std;

void brac(string output, int k, int open, int close, int index){

	if(index == 2*k){
		cout<<output<<endl;
		return;
	}

	if(open<k){
		brac(output + '{', k, open+1, close, index+1);
	}
	if(close<open){
		brac(output+'}', k, open, close+1, index+1);
	}
}


int main(){
	int k = 5;
	string output;
	brac(output, k, 0, 0, 0);   //output, k, open count, close count, index
	return 0;
}