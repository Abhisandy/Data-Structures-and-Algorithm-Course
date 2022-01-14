#include<bits/stdc++.h>
using namespace std;

vector<string> res;

void Permutations(char *inp, int i){
    if(inp[i] == '\0'){
        string str = inp;
        res.push_back(str);
        return;
    }
    for(int j=i; inp[j]!='\0'; j++){
        swap(inp[i], inp[j]);
        Permutations(inp, i+1);
        swap(inp[i], inp[j]);
    }

}


vector<string> findSortedPermutations(string s){

    int n = s.length();
    char inp[n+1];
    for(int i=0;i<n;i++){
        inp[i] = s[i];
    }
    inp[n] = '\0';
    Permutations(inp, 0);  

    sort(res.begin(), res.end()); //sort permutations

    set<string> st;    //to remove duplicate permuatations Eg: when input "aa"
                                                        //output "aa", "aa"
    for(int i=0;i<res.size();i++){
        st.insert(res[i]);
    }
    res.clear();
    for(auto a: st){
        res.push_back(a);
    }

    return res; 
}



int main(){

    string input = "abc";
    auto res = findSortedPermutations(input);
    for(string i: res){
        cout<<i<<endl;
    }
    return 0;
}