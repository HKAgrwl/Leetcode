class Solution {
    public int[] sortArrayByParity(int[] arr) {
        for (int i = 0; i < arr.length; i++) {
            // for each step, max item will come at the last index.
            for (int j = 1; j < arr.length-i; j++) {
                // swap if item is smaller than the previous item.
                if(arr[j]%2==0 && arr[j-1]%2 !=0){
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