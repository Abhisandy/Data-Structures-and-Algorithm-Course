#include<bits/stdc++.h>

using namespace std;

string key[] = {"", "", "ABC", "DEF", "GHI", "JKL", "MNO", "PQRS", "TUV", "WXYZ"};

void keypad(string input, string output = "", int i = 0){

	if(input[i] == '\0'){
		cout<<output<<endl;
		return;
	}

	int current = input[i] - '0';
	if(current == 0 or current == 1){
		keypad(input, output, i+1);
	}

	for(int k = 0; k<key[current].size();k++){
		keypad(input, output + key[current][k], i+1);
	}
	return;
}

int main(){
	string input = "23";
	keypad(input);
}