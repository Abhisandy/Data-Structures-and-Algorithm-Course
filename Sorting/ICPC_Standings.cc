#include<bits/stdc++.h>
using namespace std;

int badness(vector<pair<string,int> > teams){
     int size = teams.size();
     vector<int> flag(size+1, 0);
   
   for(int i=0;i<size;i++){
       flag[teams[i].second]++;
   }
   
   int pos=1;
   int sum=0;
   for(int i=1;i<=size;i++){
       while(flag[i]){
           sum += abs(pos-i);
           flag[i]--;
           pos++;
       }
   }
       return sum;
    
}