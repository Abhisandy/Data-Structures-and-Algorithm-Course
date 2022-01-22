#include<bits/stdc++.h>
using namespace std;


bool issafe(vector<vector<int>> &board, int i, int j, int n, int no){
    
    for(int k=0;k<n;k++){
        
        if(board[i][k]==no or board[k][j]==no){
            return false;
        }
    }
    
    int sx=(i/3)*3;
    int sy=(j/3)*3;
    for(int x=sx; x<sx+3; x++){
        for(int y=sy; y<sy+3; y++){
            if(board[x][y]==no){
                return false;
            }
        }
    }
    return true;
}



bool solveAll(vector<vector<int>> &board, int i, int j, int n){
    
    if(i==n){
        return true;
    }
    else if(j==n){
        return solveAll(board, i+1, 0, n);
    }
    else if(board[i][j]!=0){
        return solveAll(board, i, j+1, n);
    }
    for(int no=1;no<=9;no++){
        
        if(issafe(board, i, j, n, no)){
            
            board[i][j]=no;
            bool solve = solveAll(board, i, j+1, n);
            if(solve==true){
                return true;
            }
        }
    }
    board[i][j]=0;
    return false;
    
}


vector<vector<int> > solveSudoku(vector<vector<int> > input){
    
    int n = 9;
    vector<vector<int>> board (n , vector<int> (n, 0));
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            board[i][j] = input[i][j];
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<board[i][j];
        }
        cout<<endl;
    }
    
	solveAll(board, 0, 0, n);

	for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<board[i][j];
        }
        cout<<endl;
    }

	return board;
    
}



int main(){
	vector<vector<int>> input {{0,3,0,0,0,0,9,0,0},
								{0,0,6,0,0,0,0,0,0},
								{0,0,0,2,4,1,0,3,0},
								{0,0,0,9,0,0,7,0,0},
								{0,0,0,0,0,2,0,0,4},
								{0,8,0,0,7,0,0,2,0},
								{8,5,0,0,0,0,0,0,0},
								{0,9,0,7,0,4,0,0,0},
								{0,0,0,0,0,6,0,0,1}};
	solveSudoku(input);
	return 0;
}