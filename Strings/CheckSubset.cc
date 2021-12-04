#include<iostream>

using namespace std;


string Subset(string s1, string s2){
	int len = s1.length();
	int i=0;
	int j=0;
	int count = 0;   //To check wheather length of match same as string s2 or not
	while(i<len){
		if(s1[i]==s2[j]){
			i++;
			j++;
			count++;
		}
		else{
			i++;
		}
	}
	if(count==s2.length()){
		return "Yes";
	}
	else{
		return "No";
	}
}



int main(){
	string s1 = "codingminutes";
	string s2 = "cines";
	auto res = Subset(s1, s2);
	cout<<res;
	return 0;
}