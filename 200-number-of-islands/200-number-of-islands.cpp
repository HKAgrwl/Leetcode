class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int count=0;
        int n= grid.size();
        int m = grid[0].size(); 
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1'){
                    count++;
                    callBFS(grid,i,j);
                }
            }
        }
        return count;
    }
    
    void callBFS(vector<vector<char>>& grid,int i,int j){
        if(i<0 || i>=grid.size()|| j<0 || j>=grid[i].size() || grid[i][j]=='0') return;
        grid[i][j]='0';
        callBFS(grid, i+1, j);
        callBFS(grid, i, j+1);
        callBFS(grid, i-1, j);
        callBFS(grid, i, j-1);
    }
};