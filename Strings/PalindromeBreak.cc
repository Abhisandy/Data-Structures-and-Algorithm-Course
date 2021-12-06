#include<iostream>
#include<vector>
using namespace std;


string breakPalindrome(string palindrome){
	string res = palindrome;
	int n = palindrome.length();
	vector<vector<int>> count(26);
	int non_a = -1;

	if(n==1){
		return "";
	}

	for(int i=0;i<n;i++){
		count[res[i]-'a'].push_back(i);
		cout<<res[i]-'a'<<endl;

		if(non_a==-1 && res[i]!='a'){
			non_a = i;
		}
	}
	
	if(count[0].size()==n-1){      //case: we have n-1 a's replace last a with b
		res[count[0].back()] = 'b';
	}
	else{
		res[non_a] = 'a';
	}
	return res;
}




int main(){
	string palindrome = "awccwa";
	auto res = breakPalindrome(palindrome);
	cout<<res;
	return 0;
}