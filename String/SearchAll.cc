#include<iostream>
#include<vector>
#include<string>

using namespace std;

vector<int> stringSearch(string big,string small){
    vector<int> result = {};

    int index = big.find(small);

    while(index!=-1){

    	result.push_back(index);
    	index = big.find(small, index+1);
    }
    return result;
}

int main(){

	string big = "I liked the movie, acting in movie was great movie";
	string small = "movie";
	auto res = stringSearch(big, small);
	for(int a: res){

		cout<<a<<"--";
	}
	return 0;
}