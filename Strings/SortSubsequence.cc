#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>

using namespace std;

void Check(string s, string output, vector<string> &res){
	if(s.length()==0){
		res.push_back(output);
		return;
	}

	char letter = s[0];
	string reduced = s.substr(1);
	Check(reduced, output, res);
	Check(reduced, output+letter, res);
}

bool compare(string s1, string s2){
	if(s1.length()==s2.length()){
		return s1<s2;
	}
	else{
		return s1.length()<s2.length();
	}
}





int main(){
	string s = "abcd";
	vector<string> res;
	string output = "";
	Check(s, output, res);

	sort(res.begin(), res.end(), compare);

	for(auto i: res){
		cout<<i<<"--";
	}

	return 0;
}