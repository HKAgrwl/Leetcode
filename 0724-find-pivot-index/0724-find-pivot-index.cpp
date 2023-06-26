class Solution {
public:
    int pivotIndex(vector<int>& nums) {
      int leftSum = 0;
      int rightSum = 0;
      for(int i=1;i<nums.size();i++){
          rightSum += nums[i];
      }
      int t = 0;
      while(t < nums.size()){
          if(leftSum==rightSum) return t;
          if(t==nums.size()-1) return -1;
          leftSum += nums[t];
          rightSum -= nums[t+1];
          t++;
      }
        
      return -1;
    }
};