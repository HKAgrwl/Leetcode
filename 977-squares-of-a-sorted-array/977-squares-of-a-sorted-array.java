class Solution {
    public int[] sortedSquares(int[] nums) {
        int len = nums.length;
        int[] arr = new int[len];
        for(int i=0;i<len;i++){
            arr[i] = nums[i]*nums[i];
        }
        for (int i = 0; i < arr.length; i++) {
            // for each step, max item will come at the last index.
            for (int j = 1; j < arr.length-i; j++) {
                // swap if item is smaller than the previous item.
                if(arr[j]<arr[j-1]){
                    // swap
                    int temp = arr[j];
                    arr[j] = arr[j-1];
                    arr[j-1] = temp;
                }
            }
        }
        return arr;
    }
}