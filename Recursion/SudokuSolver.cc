class Solution {
    

    
public:
    bool issafe(vector<vector<char>> &board, int i, int j, char no, int n){
        
        //cout<<no<<endl;
        for(int k=0; k<n; k++){
            if(board[i][k]==no or board[k][j]==no){
                return false;
            }
        }
        
        int sx = (i/3)*3;
        int sy = (j/3)*3;
        for(int x=sx; x<sx+3; x++){
            for(int y=sy; y<sy+3; y++){
                if(board[x][y]==no){
                    return false;
                }
            }
        }
        return true;
    }
    
    
public:
    bool solveALL(vector<vector<char>> &board, int i, int j, int n){
        
        //cout<<i<<" "<<j<<endl;
        if(i==n){                           // row end
            
            // for(int i=0;i<9;i++){
            //     for(int j=0;j<9;j++){
            //         cout<<board[i][j];
            //     }
            //     cout<<endl;
            // }
            
            return true;
        }
        
        else if(j==n){                            //column end
            return solveALL(board, i+1, 0, n);
        }
        
        else if(board[i][j]!='.'){                  //entry already filled
            return solveALL(board, i, j+1, n);
        }
        
        //check each possibilties
        for(int ch=49; ch<=57;ch++){
            
            char no = ch;
            //cout<<"no : "<<no<<endl;
            //cout<<"safe : "<<issafe(board, i, j, no, n)<<endl;
            if(issafe(board, i, j, no, n)){
                board[i][j]=no;
            
            
                bool solve = solveALL(board, i, j+1, n);
                //cout<<solve<<endl;
                if(solve==true){
                    return true;
                }
            }
        }
        board[i][j]='.';
        return false;
    }
    
    
    
public:
    void solveSudoku(vector<vector<char>>& board) {
        
        int n = 9;
        solveALL(board, 0, 0, n);
    }
};