class Solution {
private:
    void dfs(int i, int j, int n,int m, vector<vector<int>>& grid, vector<vector<int>>& vis,bool & check){
        if(i==0 || i==n-1 || j==0 || j==m-1) check = false;
        vis[i][j] = 1;
        if(i-1 >=0 && i-1 < n && j>=0 && j<m && vis[i-1][j]==0 && grid[i-1][j]==0){
            dfs(i-1,j,n,m,grid,vis,check);
        }
        if(i >=0 && i < n && j-1 >=0 && j-1 <m && vis[i][j-1]==0 && grid[i][j-1]==0){
            dfs(i,j-1,n,m,grid,vis,check);
        }
        if(i+1 >=0 && i+1 < n && j>=0 && j<m && vis[i+1][j]==0 && grid[i+1][j]==0){
            dfs(i+1,j,n,m,grid,vis,check);
        }
        if(i >=0 && i < n && j+1>=0 && j+1<m && vis[i][j+1]==0 && grid[i][j+1]==0){
            dfs(i,j+1,n,m,grid,vis,check);
        }
    }
public:
    int closedIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        int ans = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid[i][j]==0){
                    bool check = true;
                    dfs(i,j,n,m,grid,vis,check);
                    if(check) ans++;
                }
            }
        }
        return ans;
    }
};