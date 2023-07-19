class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size();
        int n = board[0].size();
        
        vector<vector<int>> v(m,vector<int>(n,1));
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int count = 0;
                if(i > 0 && board[i-1][j]==1) count++;
                if(i < m-1 && board[i+1][j]==1) count++;
                if(j > 0 && board[i][j-1]==1) count++;
                if(j < n-1 && board[i][j+1]==1) count++;
                if(i > 0 && j>0 && board[i-1][j-1]==1) count++;
                if(i <m-1 && j < n-1 && board[i+1][j+1]==1) count++;
                if(i > 0 && j<n-1 && board[i-1][j+1]==1) count++;
                if(i < m-1 && j>0 && board[i+1][j-1]==1) count++;
                
                // cout<<count<<" "<<i<<" "<<j<<endl;
                
                if(board[i][j]==1){
                    if(count < 2) v[i][j] = 0;
                    if(count > 3) v[i][j] = 0;
                }
                else if(board[i][j]==0 && count != 3) v[i][j] = 0;
            }
        }
        
        for(int a=0;a<m;a++){
            for(int b=0;b<n;b++){
                board[a][b] = v[a][b];
            }
        }
        
    }
};