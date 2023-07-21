class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> v(n,1);
        for(int i=1;i<n;i++){
            int max = INT_MIN;
            for(int j =i-1;j>=0;j--){
                if(nums[j] < nums[i] && v[j]>max){
                    max = v[j];
                    v[i] = 1 + v[j];
                }
            }   
        }
        sort(v.begin(),v.end());
        return v[n-1];
    }
};