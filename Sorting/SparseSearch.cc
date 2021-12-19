#include<iostream>

using namespace std;

int Sparse(string arr[], int n, string f){
	int s = 0;
	int e = n-1;
	while(s<=e){
		int mid = (s+e)/2;
		int left = mid-1;
		int right = mid +1;
		 if(arr[mid] == ""){
		 	while(1){
		 		if(left<s and right>e){
		 			return -1;
		 		}
		 		else if(left>=s and arr[left]!=""){
		 			mid = left;
		 			break;
		 		}
		 		else if(right<=e and arr[right]!=""){
		 			mid = right;
		 			break;
		 		}
		 		left--;
		 		right++;
		 	}
		 }
		 if(arr[mid]==f){
		 	return mid;
		 }
		 else if(arr[mid]>f){
		 	e = mid-1;
		 }
		 else{
		 	s = mid+1;
		 }
	}
	return -1;
}






int main(){
	string arr[] = {"ai", "", "","bat", "","","car","cat","","","dog",""};
	int n=12;
	string f = "cat";
	cout<<Sparse(arr, n, f);
	return 0;
}