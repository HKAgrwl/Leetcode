class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m+1,vector<int> (n+1,1000));
        
        dp[1][1] = grid[0][0];
        
        for(int j=2;j<=n;j++){
            dp[1][j] = dp[1][j-1] + grid[0][j-1];
        }
        
        for(int i=2;i<=m;i++){
            for(int j = 1;j<=n;j++){
                dp[i][j] = min(grid[i-1][j-1] + dp[i][j-1], grid[i-1][j-1] + dp[i-1]                     [j]);
            }
        }
        
        return dp[m][n];
    }
};