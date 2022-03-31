class Solution {
    public int missingNumber(int[] arr) {
        int i  = 0;
        while(i<arr.length){
            int correct = arr[i];
            if(arr[i] < arr.length && arr[i] != arr[correct]){
                int temp = arr[i];
                arr[i] = arr[correct];
                arr[correct] = temp;
            }else{
                i++;
            }
        }
        for (int j = 0; j < arr.length; j++) {
            if(arr[j]!= j){
                return j;
            }
        }
        return arr.length;
    }
}