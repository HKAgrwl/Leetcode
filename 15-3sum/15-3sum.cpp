class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        for(int i=0;i<nums.size();i++){
            if(i==0 || (i>0 && nums[i]!=nums[i-1])){
                int low = i+1;
                int high = nums.size()-1;
                int sum = -nums[i];
                
                while(low<high){
                    if(nums[high]+nums[low]==sum){
                        vector<int> interim;
                        interim.push_back(nums[i]);
                        interim.push_back(nums[low]);
                        interim.push_back(nums[high]);
                        ans.push_back(interim);
                        while(low<high && nums[low]==nums[low+1]) low++;
                        while(low<high && nums[high]==nums[high-1]) high--;
                        low++;
                        high--;
                    }else if(nums[low]+nums[high]>sum){
                        high--;
                    }else{
                        low++;
                    }
                    
                }
            }
        }
        return ans;
    }
};