#include<bits/stdc++.h>

using namespace std;


float SqR(int num, int P){
	int s = 0;
	int e = num;
	float ans = 0;
	while(s<=e){
		int mid = (s+e)/2;

		if(mid*mid == num){
			return mid;
		}

		else if(mid*mid < num){
			ans = mid;
			s = mid+1;
		}
		else if(mid*mid > num){
			e = mid-1;
		}
	}
	
	float inc = 0.1;
	for(int p=1;p<=P;p++){

		while(ans*ans<num){
			ans += inc;
		}
		ans = ans - inc;
		inc = inc/10.0;
	}

	return ans;
}





int main(){
	int num = 10;
	int P = 3;
	auto res = SqR(num, P);
	cout<<res;
	return 0;
}