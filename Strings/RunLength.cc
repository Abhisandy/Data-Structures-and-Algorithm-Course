#include<iostream>
#include<vector>
#include<string>
using namespace std;


string compressString(const string &str){
	int i = 0;
	int count = 1;      //First letter already counted here
	char a = str[i];
	string res;
	res += a;
	int flag =0;       //Flag to check if all counts are 1 or not, if all are one means not possible to compress.
	while(i<str.length()){
		if(str[i+1] == a){
			count++;
			i++;
		}
		else{
			a = str[i+1];
			res = res + to_string(count);
			res = res + a;

			if(count>1){
				flag=1;
			}
			count = 0;
		}
	}
	if(flag==0){
		return str;
	}
	else{
		return res;
	}
}




int main(){
	string str = "aabbbccccxxxxxeeeeee";
	auto res = compressString(str);
	cout<<res;
	return 0;
}