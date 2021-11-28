#include<iostream>
#include<string>
#include<cstring>

using namespace std;

void Space(char *str, string r){

	int len_r = r.length();
	int count = 0;    //count space
	for(int i=0;i<strlen(str);i++){

		if(str[i]==' '){

			count += 1;
		}
	}

	int extra = (len_r-1) * count;    
	int last = strlen(str)+extra-1;
	str[last] = '\0';                       //otherwise it will print all garbage(after length)
	for(int i = strlen(str)-1;i>=0;i--){

		if(str[i]!=' '){

			str[last--] = str[i];
		}
		else if(str[i]==' '){

			str[last--] = '0';
			str[last--] = '2';
			str[last--] = '%';
		}
		
	}
}


int main(){

	char str[10000];
	cin.getline(str,1000);
	string r = "%20";
	Space(str, r);
	cout<<str;
	return 0;
}