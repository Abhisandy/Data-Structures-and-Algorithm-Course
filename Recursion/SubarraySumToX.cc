class Solution {

public:
    int subsum(vector<int> nums, int n, int pos, int sum){
        
        if(pos==n){
            if(sum==0){
                return 1;
            }
            return 0;
        }
        int inc = subsum(nums, n, pos+1, sum-nums[pos]);
        int exc = subsum(nums, n, pos+1, sum);
        return inc + exc;
    }
    
public:
    int subarraySum(vector<int>& nums, int k) {
        
        int pos = 0;
        int n = nums.size();
        int sum = k;
        auto res =  subsum(nums, n, pos, sum);
        return res;
        
    }
};