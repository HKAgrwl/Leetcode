class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        vector<int> v;
        unordered_map<int,int> m;
        for(auto x : nums){
            if(!m[x]){
                m[x]++;
                v.push_back(x);
            }
        }
        int n = v.size();
        if(n==0) return 0;
        sort(v.begin(),v.end());
        int count = 1;
        int ans = 0;
        for(int i=1;i<n;i++){
            if(v[i]==v[i-1]+1) count++;
            else{
                ans = max(ans,count);
                count=1;
            }
        }
        return max(ans,count);
    }
};