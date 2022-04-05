class Solution {
    public int majorityElement(int[] nums) {
        int l = nums.length;
        for (int i = 0; i < l-1; i++) {
            for (int j = i+1; j > 0; j--) {
                if(nums[j]<nums[j-1]){
                    int temp = nums[j];
                    nums[j] = nums[j-1];
                    nums[j-1] = temp;
                }else{
                    break;
                }
            }
        }
        for (int i = 0; i < l; i++) {
            if(nums[i]==nums[(l/2)+i]){
                return nums[i];
            }
        }
        return -1;
    }
}