#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;

bool comp(pair<int, int> a, pair<int, int> b){

    return a.second < b.second;
}

int countActivites(vector<pair<int,int>> v){

    sort(v.begin(), v.end(), comp);
    int count = 1;
    int end = v[0].second;

    for(int i=1;i<v.size();i++){

        if(v[i].first>=end){

            count++;
            end = v[i].second;
        }
    }
    return count;
}

int main(){

    vector<pair<int,int>> arr = {{7,9}, {0,10}, {4,5}, {8,9}, {4,10}, {5,7}};
    auto res = countActivites(arr);
    cout<<res;
    return 0;
}