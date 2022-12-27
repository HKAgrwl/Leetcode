class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        vector<int> space;
        for(int i=0;i<capacity.size();i++){
            space.push_back(capacity[i]-rocks[i]);
        }
        sort(space.begin(),space.end());
        int k=0;
        int ans=0;
        while(additionalRocks > 0 && k<space.size()){
            additionalRocks-= space[k];
            k++;
            if(additionalRocks >= 0) ans++;
        }
        return ans;
    }
};