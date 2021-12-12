#include<iostream>
#include<cstring>
#include<unordered_set>
#include<climits>

using namespace std;


string smallestWindow(string str){

	unordered_set<char> set;

	for(int i=0;i<str.length();i++){
		if(set.find(str[i]) == set.end()){   //not found in set
			set.insert(str[i]);
		} 
	}

	int FP[256] = {0};
	int FS[256] = {0};
	int count = 0;
	int start = 0;
	int window_size;
	int min_window_size_so_far = INT_MAX;
	int start_idx = -1;

	unordered_set<char> :: iterator itr;

	for(itr = set.begin(); itr!=set.end();itr++){
		FP[*itr]++;
	}


	for(int i=0;i<str.length();i++){
		char ch = str[i];
		FS[ch]++;

		if(FP[ch]!=0 and FS[ch]<=FP[ch]){
			count += 1;
		}

		if(count==set.size()){
			while(FP[str[start]]==0 or FS[str[start]]>FP[str[start]]){
				FS[str[start]]--;
				start++;
			}

			window_size = i-start+1;
			if(window_size<min_window_size_so_far){
				min_window_size_so_far = window_size;
				start_idx = start;
			}

		}


	}
	if(start_idx==-1){       //No such substring
		return "";  
	}
	return str.substr(start_idx, min_window_size_so_far);

}




int main(){
	string str = "aabcbcdbcaaad";
	auto res = smallestWindow(str);
	cout<<res;
	return 0;
}