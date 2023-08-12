class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum =0;
        for(auto x : nums){
            sum+= x;
        }
        if(sum%2) return false;
        sum = sum/2;
        // cout<<sum;
        vector<vector<bool>> dp(sum+1,vector<bool>(n+1,false));
        
        for(int j=0;j<n+1;j++){
            dp[0][j] = true;
        }
        
        for(int i=1;i<sum+1;i++){
            for(int j=1;j<n+1;j++){
                if(nums[j-1] <= i){
                    dp[i][j] = dp[i-nums[j-1]][j-1] || dp[i][j-1];
                }else{
                    dp[i][j] = dp[i][j-1];
                }
            }
        }
        
        return dp[sum][n];
    }
};