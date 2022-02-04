#include<bits/stdc++.h>

using namespace std;


bool isBalanced(string input){

	stack<char> s;

	for(auto ch : input){

		switch(ch){

			case '(':
			case '{':
			case '[': s.push(ch);
						break;

			case ')': if(!s.empty() and s.top() == '('){
						s.pop();
		   			  }	
		   			  else{
		   			  	return false;
		   			  }			
		   			  break;
		   	case '}': if(!s.empty() and s.top() == '{'){
						s.pop();
		   			  }	
		   			  else{
		   			  	return false;
		   			  }			
		   			  break;
		   	case ']': if(!s.empty() and s.top() == '['){
						s.pop();
		   			  }	
		   			  else{
		   			  	return false;
		   			  }			
		   			  break;	

		   	default : continue;		  	  		  
		}
	}
	if(s.empty()==true){
		return true;
	}
	return false;
}



int main(){

	string input = "(a+b+[c+d+{g+a}])";
	if(isBalanced(input)){
		cout<<"Balanced !";
	}
	else{
		cout<<"UnBalanced !";
	}
	return 0;
}