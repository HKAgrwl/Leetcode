class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans;
        int start = 0;
        int end = nums.size()-1;
        if(nums.size()==0){
            start=-1;
            end=-1;
            ans.push_back(start);
            ans.push_back(end);
            return ans;
        }
        while(nums[start] < target && start<nums.size()-1){
            start++;
        }
        while(nums[end]>target && end>0){
            end--;
        }
        if(nums[start]!=target || nums[end]!=target){
            start=-1;
            end=-1;
        }
        ans.push_back(start);
        ans.push_back(end);
        return ans;
    }
};