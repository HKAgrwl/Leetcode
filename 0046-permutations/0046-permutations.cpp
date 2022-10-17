class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> interim;
        permutations(ans,nums,interim);
        return ans;
    }
    void permutations(vector<vector<int>>& ans,vector<int>& nums,vector<int> interim){
        if(interim.size()>=nums.size()){
            ans.push_back(interim);
            return;
        }
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=-999) {
               interim.push_back(nums[i]);
               int k = nums[i];
               nums[i]=-999;
               permutations(ans,nums,interim);
                nums[i]=k;
               interim.pop_back();
            }
        }
    }
};