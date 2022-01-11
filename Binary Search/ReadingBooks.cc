#include<bits/stdc++.h>

using namespace std;


bool ifpossible(int mid, vector<int> books, int m){

	int cs = 0;
	int k = 1;   //allocate students

	for(int i=0;i<books.size();i++){

		if(cs + books[i] > mid){
			k++;
			cs=books[i];
			if(k>m){
				return false;
			}
			
		}
		else{
			cs += books[i];
		}
	}
	return true;
}


int minPages(vector<int> books, int m){

	int s = *max_element(books.begin(), books.end());
	int e = accumulate(books.begin(), books.end(), 0);
	//cout<<s<<endl;
	//cout<<e<<endl;

	int result = INT_MAX;;
	while(s<=e){

		int mid = (s+e)/2;
		//cout<<"mid "<<mid<<endl;
		//cout<<ifpossible(mid, books, m)<<endl;
		if(ifpossible(mid, books, m)){
			result = min(mid, result);
			e = mid - 1;
		}
		else{
			s = mid + 1;
		}
	}
	return result;
}



int main(){
	vector<int> books {10, 20, 30, 15};
	int k = 2;
	auto res = minPages(books, k);
	cout<<res;
	return 0;
}