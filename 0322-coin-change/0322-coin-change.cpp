class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = amount;
        vector<int> arr(n+1,-1);
        int ans = dp(amount,coins,arr);
        if(ans > 100000) return -1;
        return ans;
    }
    
    int dp(int amount,vector<int> &coins,vector<int> &arr){
        if(amount==0) return 0;
        if(amount < 0) return 100000;
        
        if(arr[amount]!=-1) return arr[amount];
        
        int count = INT_MAX-1;
        for(auto x : coins){
            int t = dp(amount-x,coins,arr);
            if(t!=-1) count = min(t,count);
        }
        count++;
        arr[amount] = count;
        return count;
    }
};