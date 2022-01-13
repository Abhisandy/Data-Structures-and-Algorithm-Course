#include<bits/stdc++.h>

using namespace std;

int Ways(int n){

	if(n==0){
		return 1;
	}
	else if(n<0){
		return 0;
	}
	else{
		return Ways(n-1) + Ways(n-2) + Ways(n-3);
	}
}

int main(){
	int k = 4;
	cout<<Ways(k);
}

