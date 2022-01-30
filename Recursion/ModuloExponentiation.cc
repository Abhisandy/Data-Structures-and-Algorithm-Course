#include<bits/stdc++.h>
using namespace std;

long long int calc(int x, int n, long c){
    
    long long int temp;
    if(x==0){
        return 0;
    }
    if(n==0){
        return 1;
    }
    
    else if(n%2==0){
        temp = calc(x, n/2, c);
        return (temp*temp)%c;
    }
    else{
        temp = x%c;
        return (temp*calc(x, n-1, c)%c)%c;
    }
    
}

long long int powerModulo(int x, int n){

int mod = 1e9+7;  
return calc(x, n, mod);

}