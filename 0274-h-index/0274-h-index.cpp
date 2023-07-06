class Solution {
public:
    int hIndex(vector<int>& citations) {
        int max = INT_MIN;
        for(auto x : citations){
            if(x > max) max = x;
        }
        vector<int> v(max+1,0);
        
        for(auto x : citations){
            for(int i=0;i <= x;i++) v[i]++;
        }
        
        for(int i=v.size()-1;i>=0;i--){
            if(v[i] >= i) return i;
        }
        
        return -1;
    }
};