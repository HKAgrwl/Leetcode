class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        int n = nums.size();
        if(n % 2 == 0) return true;
        vector<vector<int>> dp(n, vector<int>(n));
        for(int i = 0; i < n; ++i){
            dp[i][i] = nums[i];
        }
        for(int step = 1; step < n; ++step){
            for(int i = 0; i + step < n; ++i){
                int j = i + step;
                dp[i][j] = max(nums[i] - dp[i + 1][j], nums[j] - dp[i][j - 1]);
            }
        }
        return dp[0][n - 1] >= 0;
    }
}; 