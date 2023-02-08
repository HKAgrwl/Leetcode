class Solution {
public:
    int jump(vector<int>& nums) {
        vector<int> pathLen(nums.size(),0);
        int n = nums.size();
        for(int i=nums.size()-1;i>=0;i--){
            if(i==nums.size()-1){
                pathLen[i]=0;
                continue;
            }
            if(nums[i]==0) {
                pathLen[i] = INT_MAX;
                continue;
            }
            if(n-i <= nums[i]){
                pathLen[i]=1;
            }else{
                int min = INT_MAX-1;
                for(int x= 1;x<=nums[i];x++){
                    if(pathLen[i+x] < min) min = pathLen[i+x];
                }
                pathLen[i] = 1+min;
            }
        }
        return pathLen[0];
    }
};