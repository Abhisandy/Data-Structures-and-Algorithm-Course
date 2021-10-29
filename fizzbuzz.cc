#include<vector>
#include<iostream>
#include<string>
using namespace std;

vector<string> fizzbuzz(int n){
    vector<string> res;
    for(int i=1;i<=n;i++){

        if(i%3==0){
            if(i%5==0){
                res.push_back("FizzBuzz");
            }
            else
                 res.push_back("Fizz");       
        
        }

        else if(i%5==0){
            res.push_back("Buzz");
        } 
        
        else{
            res.push_back(to_string(i));
        }
    }
 
 return res;   
}

int main(){
    vector<string> a = fizzbuzz(15);
    for(string x : a){
        cout<<x<<",";
    }
}