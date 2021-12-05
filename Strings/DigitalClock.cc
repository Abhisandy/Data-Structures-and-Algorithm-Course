#include<iostream>
#include<string>
#include<cmath>
using namespace std;


string convert(int min){
	int h = floor(min/60);
	string hours = to_string(h);
	int m = min%60;
	string minutes = m < 10 ? '0' + to_string(m) : to_string(m);
	return hours + ":" + minutes; 
}




int main(){
	int min;
	cin>>min;
	auto res = convert(min);
	cout<<res;
	return 0;
}