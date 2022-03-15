#include<bits/stdc++.h>
using namespace std;


char firstRepeatChar(string input){
    
    unordered_map<char, bool> map;
    
    for(auto x: input){
        if(map[x] == true){
            return x;
        }
        else{
            map[x] =  true;
        }
    }
    
    
}