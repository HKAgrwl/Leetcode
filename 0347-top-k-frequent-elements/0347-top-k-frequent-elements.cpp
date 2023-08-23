class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int maxFreq = 0;
        unordered_map<int,int> m;
        for(auto x : nums){
            m[x]+=1;
            if(m[x] > maxFreq) maxFreq = m[x];
        }
        vector<vector<int>> v(maxFreq+1);
        for(auto x : m){
            int freq = x.second;
            // cout<<freq<<endl;
            v[freq].push_back(x.first);
        }
        vector<int> ans;
        reverse(v.begin(),v.end());
        int i=0;
        while (i<maxFreq+1 && k>0){
            if(v[i].size()){
                for(auto x : v[i]){
                    ans.push_back(x);
                    k--;
                }
                
            }
            i++;
        }
        return ans;
    }
};