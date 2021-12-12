#include<iostream>
#include<cstring>
#include<climits>

using namespace std;

string Find_window(string s , string p){

	int FP[256] = {0};
	int FS[256] = {0};
	int count = 0;
	int start = 0;
	int window_size;
	int min_window_size_so_far = INT_MAX;
	int start_idx=-1;

	for(int i=0;i<p.length();i++){
		FP[p[i]]++;
	}

	for(int i=0;i<s.length();i++){
		char ch = s[i];
		FS[ch]++;

		if(FP[ch]!=0 and FS[ch]<=FP[ch]){
			count += 1;
		}

		if(count == p.length()){    //contraction
			while(FP[s[start]]==0 or FS[s[start]]>FP[s[start]]){
				FS[s[start]]--;
				start++;
			}
		

			window_size = i-start+1;
			if(window_size<min_window_size_so_far){
				min_window_size_so_far = window_size;
				start_idx = start;
			}
		}

	}
	if(start_idx==-1){
		return "No such window";
	}
	return s.substr(start_idx, min_window_size_so_far);



}







int main(){
	string str = "hello";
	string p = "ole";
	auto res = Find_window(str,p);
	cout<<res;
	return 0;
}