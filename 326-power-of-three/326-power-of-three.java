class Solution {
    public boolean isPowerOfThree(int n) {
        return recursion(n);
    }
    public boolean recursion(double n){
        if(n==1){
            // System.out.println(true);
            return true;
        }
        if(n<1){
            System.out.println(false);
            return false;
        }
        return recursion(n/3);
    }
}