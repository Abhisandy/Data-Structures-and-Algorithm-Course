#include<iostream>
#include<cstring>
#include<unordered_map>

using namespace std;

string UniqueSub(string str){
	int i = 0;
	int j = 0;
	int window_len = 0;
	int start_window = -1;
	int max_window = 0;
	unordered_map<char, int> map;

	while(j<str.length()){

		char ch = str[j];
		if(map.count(ch) && map[ch]>=i){   //when character already in map and iddx>=1,we need to start new window
			i = map[ch] + 1;
			window_len = j-1;

		}

		map[ch] = j;
		window_len++;
		j++;

		if(window_len>max_window){
			max_window = window_len;
			start_window = i;
		}

	}
	return str.substr(start_window, max_window);

}





int main(){
	string str = "abcabed";
	auto res = UniqueSub(str);
	cout<<res;
	return 0;
}