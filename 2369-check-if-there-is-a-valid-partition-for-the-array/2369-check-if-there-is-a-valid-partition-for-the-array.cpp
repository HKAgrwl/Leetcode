class Solution {
public:
    bool validPartition(vector<int>& nums) {
        int n = nums.size();
        vector<bool> dp(n+1,false);
        dp[0] = true;
        for(int i=2;i<n+1;i++){
            if((nums[i-1]==nums[i-2] && dp[i-2]) || (i>2 && nums[i-1]==nums[i-2] && nums[i-1]==nums[i-3] && dp[i-3]) || (i>2 && nums[i-1]==nums[i-2]+1 && nums[i-1]==nums[i-3]+2 && dp[i-3])){
                dp[i] = true;
            }
        }
                                                                                                       return dp[n];
    }
};