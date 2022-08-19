class Solution {
public:
    
    vector<vector<int>> output;
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<int> nums;
        dfs(candidates,target,0,nums,0);
        return output;
    }
    
    void dfs(vector<int>& candidates,int target,int sum,vector<int>& nums,int i){
        if(sum==target){
            output.push_back(nums);
            return;
        }
        if(sum>target || i>=candidates.size()){
            return;
        }
        nums.push_back(candidates[i]);
        dfs(candidates,target,sum+candidates[i],nums,i);
        
        nums.pop_back();
        dfs(candidates,target,sum,nums,i+1);
        
    }
};