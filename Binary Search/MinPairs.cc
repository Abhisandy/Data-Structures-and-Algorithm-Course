#include<bits/stdc++.h>

using namespace std;

void minPairs(vector<int> a1, vector<int> a2){

	sort(a2.begin(), a2.end());
	int diff = INT_MAX;
	int p1;
	int p2;

	for(int i=0;i<a1.size();i++){
		int lb = lower_bound(a2.begin(), a2.end(), a1[i]) - a2.begin(); //- a2.begin()=> it will give index of that element

		if(lb>0 and a1[i]-a2[lb-1] < diff){
			diff = a1[i] - a2[lb-1];
			p1 = a1[i];
			p2 = a2[lb-1];
		}

		if(lb!=a2.size() and a2[lb]-a1[i] < diff){
			diff = a2[lb] - a1[i];
			p1 = a1[i];
			p2 = a2[lb];
		}
	}
	cout<<p1<<" and "<<p2<<endl;
}


int main(){
	vector<int> a1{-1, 5, 10, 20, 3};
	vector<int> a2{26, 134, 135, 15, 17};
	minPairs(a1, a2);
	return 0;
}