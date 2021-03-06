#include<bits/stdc++.h>
using namespace std;

pair<bool, int> Path(int m , int n, int i, int j, vector<vector<int>> v, bool mat[][100]){
    
    if(i==m-1 && j==n-1){
        pair<bool, int> p = {true, 0};
        return p;
    }
     if(i>=m || i<0 || j<0 || j>=n){
         pair<bool, int> p = {false, -1};
         return p;
     }
     
     else{
         mat[i][j] = true;
         pair<bool, int> res = {false, -1};
         
         if(i+1<m && v[i+1][j]==1 && mat[i+1][j]==false){
             pair<bool, int> p1 = Path(m, n, i+1, j, v, mat);
             if(p1.first){
                 res.first = true;
                 res.second = max(res.second, p1.second);
             }
             
         }
         if(j+1<n && v[i][j+1]==1 && mat[i][j+1]==false){
             pair<bool, int> p2 = Path(m, n, i, j+1, v, mat);
             if(p2.first){
                 res.first = true;
                 res.second = max(res.second, p2.second);
             }
             
         }
         if(i>0 && v[i-1][j]==1 && mat[i-1][j]==false){
             pair<bool, int> p3 = Path(m, n, i-1, j, v, mat);
             if(p3.first){
                 res.first = true;
                 res.second = max(res.second, p3.second);
             }
             
         }
         if(j>0 && v[i][j-1]==1 && mat[i][j-1]==false){
             pair<bool, int> p4 = Path(m, n, i, j-1, v, mat);
             if(p4.first){
                 res.first = true;
                 res.second = max(res.second, p4.second);
             }
             
         }
         mat[i][j] = false;                                
         res.second += 1;
         return res;
     }
    
}


int findLongestPath(int m, int n, vector<vector<int>> v){
    
    bool mat[100][100] = {{0}};                           // boolean matrix to check flags
    pair<bool, int> result = Path(m, n, 0, 0, v, mat);    // m , n, i, j, v, mat
    return result.second;
}
