#include<bits/stdc++.h>
using namespace std;


vector<int> mergeKArrays(vector<vector<int> > arrays){
    //Complete this function
    int k = arrays.size();
    priority_queue< vector<int>, vector<vector<int>>, greater<vector<int>> > q; //min_heap
    
    for(int i=0;i<k;i++){
        int element = arrays[i][0];   //first element of each array
        q.push({element, i, 0});   //tuple as element, array index, index in array
    }
    
    vector<int> res;
    
    while(!q.empty()){
        
        auto top = q.top();
        q.pop();
        
        int element = top[0];
        int arr_idx = top[1];
        int ele_idx = top[2];
        
        res.push_back(element);
        
        if(ele_idx + 1 < arrays[arr_idx].size()){ //checking if that particular array is complete or not
            int next_ele = arrays[arr_idx][ele_idx+1];
            q.push({next_ele, arr_idx, ele_idx + 1});
        }
        
    }
    return res;
    
}