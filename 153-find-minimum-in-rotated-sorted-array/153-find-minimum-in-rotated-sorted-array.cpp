class Solution {
public:
    int findMin(vector<int>& nums) {
        int start=0;
        int end = nums.size()-1;
        while(end>=start){
            int mid = start + (end-start)/2;
            if(mid>0 && nums[mid]<nums[mid-1]){
                return nums[mid];
            }
            if(mid < nums.size()-1 && nums[mid] > nums[mid+1]){
                return nums[mid+1];
            }
            if(nums[start]>=nums[mid]){
                end = mid-1;
            }
            else{
                start = mid+1;
            }
        }
        if(end<start){
            return nums[0];
        }
        return nums[end];
    }
};