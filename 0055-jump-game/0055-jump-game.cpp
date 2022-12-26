class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        if(helper(n-1,nums)) return true;
        return false;
        
    }
    
    int helper(int x,vector<int> &nums){
        if(x==0) return true;
        for(int i=x-1;i>=0;i--){
            if(x-i <= nums[i]) return helper(i,nums);
        }
        return false;
    }
};