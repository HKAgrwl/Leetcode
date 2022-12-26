class Solution {
public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int n = grid1.size();
        int m = grid1[0].size();
        int ans = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid1[i][j]==1 && grid2[i][j]==1){
                    bool check = true;
                    dfs(i,j,n,m,grid1,grid2,check);
                    if(check) ans++;
                }
            }
        }
        return ans;
    }
    
    void dfs(int i, int j, int n,int m, vector<vector<int>>& grid1,vector<vector<int>>& grid2,bool &check){
        if(i<0 || i>=n || j<0 || j>=m || grid2[i][j]==0) return;
        if(grid2[i][j]==1 && grid1[i][j]==0){
            check=false;
            return;
        }
        grid2[i][j] = 0;
        dfs(i-1,j,n,m,grid1,grid2,check);
        dfs(i,j-1,n,m,grid1,grid2,check);
        dfs(i+1,j,n,m,grid1,grid2,check);
        dfs(i,j+1,n,m,grid1,grid2,check);
    }
};