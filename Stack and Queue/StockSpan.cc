#include<bits/stdc++.h>
using namespace std;
vector<int> stockSpan(vector<int> v) {
//Write your code here. Do not modify the function or parameters.

    vector<int> span (v.size(),1);
    stack<int> s;
    
    s.push(0);
    span[0] = 1;
    
    for(int i=1;i<v.size();i++){
        
       int curr_price = v[i];
       while(!s.empty() and v[s.top()] <= curr_price){
           s.pop();
       }
       
       if(!s.empty()){
           int prev_high = s.top();
           span[i] = i - prev_high;
       }
       else{
           span[i] = i+1;
       }
       s.push(i);
       
    }
    
return span;
    
}