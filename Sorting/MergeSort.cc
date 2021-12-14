class Solution {
    
public:
    void merge(vector<int> &arr, int s, int e){
        
        int i = s;
        int m = (s+e)/2;
        int j = m+1;
        vector<int> res;
        
        while(i<=m and j<= e){
            if(arr[i]<arr[j]){
                res.push_back(arr[i]);
                i++;
            }
            else{
                res.push_back(arr[j]);
                j++;
            }
        }
        
        while(i<=m){
            res.push_back(arr[i]);
            i++;
        }
        while(j<=e){
            res.push_back(arr[j]);
            j++;
        }
        int k=s;
        for(int x: res){
            arr[k]=x;
            k++;
        }
    }

public:
    void mergesort(vector<int> &arr, int s, int e){
        
        if(s>=e){
            return ;
        }
    
        int mid = (s+e)/2;
        mergesort(arr, s, mid);
        mergesort(arr, mid+1, e);
        merge(arr, s, e);
}
    
public:
    vector<int> sortArray(vector<int>& nums) {
        mergesort(nums, 0, nums.size()-1);   
        return nums;
    }
};