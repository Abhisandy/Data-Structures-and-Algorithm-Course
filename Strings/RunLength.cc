#include<iostream>
#include<vector>
#include<string>
using namespace std;


string compressString(const string &str){
	int n = str.length();
	string res;       
	for(int i=0;i<n;i++){
		int count = 1;
		while(str[i]==str[i+1] && i<n-1){
			count++;
			i++;
		}

		res += str[i];
		res += to_string(count);
	}
	if(res.length()>str.length()){
		return str;
	}
	else{
		return res;
	}
}




int main(){
	string str = "aaaabbcdeee";
	auto res = compressString(str);
	cout<<res;
	return 0;
}