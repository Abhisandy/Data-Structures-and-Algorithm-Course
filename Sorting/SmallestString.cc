#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

bool compare(string a, string b){
	return a+b < b+a;
}


int main(){
	string arr[] = {"a", "ab", "aba"};
	int n=3;
	sort(arr, arr+n, compare);

	for(auto s: arr){
		cout<<s;
	}

	return 0;
}