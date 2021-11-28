#include<iostream>
#include<vector>
using namespace std;

int Mountain(vector<int> arr){

    int i=1;
    int max=0;
    int size = arr.size();
	while(i<=size-2){

		int len = 0;
		if( (arr[i]>arr[i-1]) && (arr[i]>arr[i+1]) ) {

			//cout<<"peak"<<arr[i]<<endl;
			int j=i;
			while((arr[j]>arr[j-1]) && (j>0))  {

				len++;
				j = j-1;
			}
			j=i;
			while((arr[j]>arr[j+1])&&(j<size-1)){

				len++;
				j=j+1;
			}

			len++;   //add 1 for peak
			//cout<<len<<endl;
			i=j+1;

			if(len>max){

			max=len;
		}

		}

		else{

			i++;
		}

	}
	return max;
}

int main(){
	vector<int> arr {5,6,1,2,3,4,5,4,3,2,0,1,2,3,-2,4};
	int res = Mountain(arr);
	cout<<res;
	return 0;
}