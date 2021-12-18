class Solution {
    
public:
    int Partition(vector<int> &arr, int s, int e){
        
        int pivot = arr[e];
        int i = s-1;
        for(int j=s; j<e; j++){  //<j coz last element(i.e., eth element) is pivot
            
            if(arr[j]<pivot){
                i++;
                swap(arr[i], arr[j]);
            }
        }
        swap(arr[i+1], arr[e]);
        cout<<i+1<<endl;
        return i+1;
        
      
    }

public:
    void quicksort(vector<int> &arr, int s, int e){
        
        if(s>=e){
            return;
        }

        int p = Partition(arr, s, e);
        quicksort(arr, s, p-1);
        quicksort(arr, p+1, e);
}
    
public:
    vector<int> sortArray(vector<int>& nums) {
        quicksort(nums, 0, nums.size()-1);   
        return nums;
    }
};