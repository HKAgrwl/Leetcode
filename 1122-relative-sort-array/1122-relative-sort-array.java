class Solution {
    public int[] relativeSortArray(int[] arr1, int[] arr2) {
        int i =0;
        int j = 0;
        int[] ans  = new int[arr1.length];
        for(int x:arr2){
            for(int k=0;k<arr1.length;k++){
                if(arr1[k]==x){
                    ans[i]=arr1[k];
                    arr1[k]=-1;
                    i++;
                }
            }
        }
        Arrays.sort(arr1);
        for(int k=0;k<arr1.length;k++){
            if(arr1[k]!=-1){
                ans[i]=arr1[k];
                i++;
            }
        }
        return ans;
       
    }
}