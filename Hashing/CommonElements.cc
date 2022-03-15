#include<bits/stdc++.h>
using namespace std;

vector<int> commonElements(vector<int> v1, vector<int> v2){
    //Write your code here. Do not modify the function or the parameters. You can use helper function if needed.
    
    unordered_map<int, bool> map;
    
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());
    
    vector<int> res;
    for(auto x: v1){
        map[x] = true;
    }
    
    for(auto x: v2){
        if(map[x]==true){
            res.push_back(x);
        }
    }
    return res;
}