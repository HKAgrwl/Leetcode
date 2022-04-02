class Solution {
    public int rob(int[] houses) {
        if (houses.length==0) return 0;
        int[] dp = new int[houses.length];
        dp[0] = houses[0];
        if(houses.length == 1) return dp[0];
        dp[1] = Math.max(houses[0], houses[1]);
        for (int i = 2; i < houses.length; i++) {
            dp[i]  =Math.max(dp[i-1],dp[i-2]+houses[i]);
        }
        return dp[houses.length-1];
        
    }
}