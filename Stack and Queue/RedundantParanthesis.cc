#include<bits/stdc++.h>

using namespace std;


bool isRedundant(string input){

	stack<char> s;

	for(auto ch : input){

		if( ch != ')' ){   //characters, +, -, *, /, (

			s.push(ch);
		}
		else{     // )

			bool operator_found = false;
			while(!s.empty() and s.top() != '('){
				char top = s.top();
				if(top == '+' or top == '-' or top == '*' or top == '/'){
					operator_found = true;
				}
				s.pop();
			}
			s.pop();   // pop (

			if(operator_found == false){
				return true;
			}
		}	
	}
	return false;      // no redundancy
}



int main(){

	string input = "(a+b(c+d+(g+a)))";
	if(isRedundant(input)){
		cout<<"Redunadant !";
	}
	else{
		cout<<"Not Redundant !";
	}
	return 0;
}