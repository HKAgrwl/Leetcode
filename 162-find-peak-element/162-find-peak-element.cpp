class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int start=0;
        int end = nums.size()-1;
        while(start<end){
            int mid = (start+end)/2;
            if(mid>0 && mid<nums.size()-1 && nums[mid]>nums[mid+1] && nums[mid]>nums[mid-1]){
                return mid;
            }
            if(nums[mid]>nums[mid+1]){
                end=mid-1;
            }else{
                start=mid+1;
            }
        }
        if(end<start){
            return start;
        }
        return end;
    }
};