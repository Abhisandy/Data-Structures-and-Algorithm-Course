#include <bits/stdc++.h>
using namespace std;

int Coins(vector<int> v, int s, int e){
    
    if((s==e) || (s==e-1)) {    //only one element or two element
         return max(v[s], v[e]);
    } 
    
    int first = v[s] + min( Coins(v, s+2, e) , Coins(v, s+1, e-1) );
    int second = v[e] + min( Coins(v, s+1, e-1) , Coins(v, s, e-2) );
    
    return max(first, second);
}

int MaxValue(int n, vector<int> v){
//Write your code here. Do not modify the function or parameters. You can use a helper function if needed.

    auto res = Coins(v, 0, n-1);
    return res;

    
}