#include<bits/stdc++.h>

using namespace std;



bool canplaceBirds(vector<int> nest, int n, int birds, int diff){

	int b = 1;   //birds in nest
	int location = nest[0];

	for(int i=1;i<n;i++){
		int current_location = nest[i];
		if(current_location - location >= diff){
			b++;
			location = current_location;

			if(b==birds){
				return true;
			}
		}
	}
	return false;

}


int main(){

	vector<int> nest {1,2,4,8,9};
	int birds = 3;
	sort(nest.begin(), nest.end());
	int n = nest.size();
	int ans = -1;

	//search space
	int s = 0;
	int e = nest[n-1] - nest[0];

	while(s<=e){

		int mid = (s+e)/2;

		bool canplace = canplaceBirds(nest, n, birds, mid);

		if(canplace){
			ans = mid;
			s = mid+1;
		}
		else{
			e = mid-1;
		}
	}

	cout<<ans;

	return 0;
}