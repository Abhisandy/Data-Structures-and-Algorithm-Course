#include<vector>
using namespace std;


vector<int> sortBalls(vector<int> balls){
   
    int j = 0; //0 to j-1 => 0's area
    int i = 0; //j to i-1 => 1's area
    int k = balls.size()-1;   // k+1 to end => 2's area
     // i to k => unknown area
     
    while(i<=k){
        if(balls[i]==0){
            int temp = balls[i];
            balls[i] = balls[j];
            balls[j] = temp;
            
            i++;
            j++;
        }
        else if(balls[i]==1){
            i++;
            
        }
        else if(balls[i]==2){
            int temp = balls[i];
            balls[i] = balls[k];
            balls[k] = temp;
            
            k--;
        }
    }     
     
    
    return balls;
}