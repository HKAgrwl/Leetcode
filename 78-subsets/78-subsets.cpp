class Solution {
public:
    
    vector<vector<int>> output;
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> interim;
        helperSubsets(nums,0,interim);
        return output;
        
    }
    
    void helperSubsets(vector<int>& nums,int k,vector<int> interim){
        if(k==nums.size()){
            output.push_back(interim);
            return;
        }
        helperSubsets(nums,k+1,interim);
        interim.push_back(nums[k]);
        helperSubsets(nums,k+1,interim);
    }
};