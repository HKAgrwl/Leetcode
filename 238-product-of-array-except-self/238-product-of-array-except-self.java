class Solution {
    public int[] productExceptSelf(int[] nums) {
        int[] result = new int[nums.length];
        int initial = 1;
        
        for (int i = 0; i < nums.length; i++) {
            result[i] = initial;
            initial *= nums[i];
        }
        initial = 1;
        for (int i = nums.length - 1; i >= 0; i--) {
            result[i] *= initial;
            initial *= nums[i];
        }
        return result;
    }
}