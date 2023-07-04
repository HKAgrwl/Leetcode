class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n+1,vector<int> (n+1,10000));
        
        dp[1][1] = triangle[0][0];
        
        for(int i=2;i<n+1;i++){
            for(int j = 1;j<=i;j++){
                dp[i][j] = min(triangle[i-1][j-1] + dp[i-1][j-1], triangle[i-1][j-1] + dp[i-1]                     [j]);
            }
        }
        
        int min_number = INT_MAX;
        for(auto x : dp[n]){
            if(x < min_number) min_number = x;
        }
        
        return min_number;
    }
};