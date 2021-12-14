    #include<iostream>
    #include<vector>
    
    using namespace std;

    int merge(vector<int> &nums, int s, int e){
        int i = s;
        int m = (s+e)/2;
        int j = m+1;
        
        vector<int> temp;
        int count = 0;
        while(i<=m and j<=e){
            if(nums[i]<nums[j]){
                temp.push_back(nums[i]);
                i++;    
            }
            else{
                count += (m-i+1);
                temp.push_back(nums[j]);
                j++;
                
            }
        }
            
            while(i<=m){
                temp.push_back(nums[i]);
                i++; 
            }
            while(j<=e){
                temp.push_back(nums[j]);
                j++;
            }
        
        int k = s;
        for(int x:temp){
            nums[k] = x;
            k++;
            
        } 
        return count;
    }
    
    

    int Global(vector<int> &nums, int s, int e){
        
        if(s>=e){
            return 0;
        }
        int mid = (s+e)/2;
        
        int c1 = Global(nums, s, mid);
        int c2 = Global(nums, mid+1, e);
        int ci = merge(nums, s, e);
        
        return c1+c2+ci;
    }

     int main() {
        vector<int> nums{3,2,0,1};
        int s = 0;
        int e = nums.size()-1;
        auto g = Global(nums, s, e);
        cout<<g;
        return 0;
        }