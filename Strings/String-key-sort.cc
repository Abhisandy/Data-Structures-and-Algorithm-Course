#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>

using namespace std;


string extractKey(string str, int key){
	char *s = strtok( (char *)(str.c_str()), " " );
	while(key>1){
		s = strtok(NULL, " ");
		key--;
	}
	return string(s);
}



int convertint(string s1){
	int ans=0;
	int p=1;
	int len = s1.length()-1;
	while(len>=0){
		ans += ((s1[len]-'0')*p);
		len--;
		p *= 10;	
	}
	return ans;
}

bool numOrder(pair<string, string> a, pair<string, string> b){
	string key1 = a.second;
	string key2 = b.second;
	return convertint(key1)<convertint(key2);
}


bool lexOrder(pair<string, string> a, pair<string, string> b){
	string key1 = a.second;
	string key2 = b.second;
	return key1<key2;
}

int main(){
	int n;
	cin>>n;
	cin.get();

	string temp;
	vector<string> s;
	for(int i=0;i<n;i++){
		getline(cin, temp);
		s.push_back(temp);
	}

	int key;
	string reversal, order;
	cin>>key >>reversal>> order;

	vector<pair<string, string>> p;
	for(int i=0;i<n;i++){
		p.push_back({ s[i], extractKey(s[i], key) });
	}

	if(order == "numeric"){
		sort(p.begin(), p.end(), numOrder);
	}
	else{
		sort(p.begin(), p.end(), lexOrder);
	}

	if(reversal == "true"){
		reverse(p.begin(), p.end());
	}


	for(int i=0;i<n;i++){
		cout<<p[i].first<<endl;
	}

	return 0;
}