class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(n+1,-1);
        int ans= solve(0,n,dp);
        return ans;
    }
    
    int solve(int i,int len,vector<int> &dp){
        if(i>len) return 0;
        if(dp[i]!=-1) return dp[i];
        if(i==len){
            return 1;
        }
        dp[i] = solve(i+1,len,dp) + solve(i+2,len,dp);
        return dp[i];
    }
};