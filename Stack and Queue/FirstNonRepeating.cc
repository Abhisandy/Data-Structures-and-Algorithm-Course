#include<bits/stdc++.h>

using namespace std;



int main(){

	char ch;
	cin>>ch;

	queue<char> q;
	int frequency[26] = {0};

	while(ch != '.'){

		q.push(ch);
		frequency[ch - 'a']++;

		while(!q.empty()){

			int index = q.front() - 'a';
			if(frequency[index] > 1){
				q.pop();
			}
			else{
				cout<<q.front()<<endl;
				break;                      //otherwise loop continues, ans will
                                            //not be first in queue       
			}
		}

		if(q.empty()){
			cout<<"-1"<<endl;
		}
		cin>>ch;
	}

	return 0;
}