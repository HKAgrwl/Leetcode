class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        vector<vector<int>> v = obstacleGrid;
        int m = v.size();
        int n = v[0].size();
        
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        
        for(int i=0;i<m+1;i++){
            dp[i][0] = 0;
        }
        for(int j=0;j<n+1;j++){
            dp[0][j] = 0;
        }
        
        
        for(int i=1;i<m+1;i++){
            for(int j=1;j<n+1;j++){
                if(v[i-1][j-1]!=1){
                    if(i==1 && j==1 ){
                        dp[i][j] = 1;
                        continue;
                    }
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];
                }else{
                    dp[i][j] = 0;
                }
            }
        }
        
        return dp[m][n];
    }
};