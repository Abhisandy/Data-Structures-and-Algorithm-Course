#include<iostream>
#include<vector>

using namespace std;


int Partition(vector<int> &arr, int s, int e){
	int pivot = arr[e];
	int i = s-1;
	for(int j=s; j<e; j++){
		if(arr[j]<pivot){
			i++;
			swap(arr[i], arr[j]);
		}
	}
	swap(arr[i+1], arr[e]);
	return i+1;
}



int quickselect(vector<int> &arr, int s, int e, int k){

	int p = Partition(arr, s, e);
	cout<<arr[p]<<" "<<p<<" "<<s<<" "<<e<<endl;
	if(k==p){
		return arr[p];
	}
	else if(k<p){
		cout<<"1"<<endl;
		return quickselect(arr, s, p-1, k);
	}
	else{
		cout<<"2"<<endl;
		return quickselect(arr, p+1, e, k);
	}

}




int main(){
	vector<int> arr{10,5,2,0,7,6,4};
	int k = 3;
	auto res = quickselect(arr, 0, arr.size()-1, k);
	cout<<res;
	return 0;
}