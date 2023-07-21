class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int start = -1;
        int end  = -1;
        vector<vector<int>> ans;
        sort(intervals.begin(),intervals.end());
        
        for(auto x : intervals){
            if(x[0] <= end && x[1] <=end) continue;
            else if(x[0] <= end && x[1]>end) end = x[1];
            else{
                vector<int> v = {start,end};
                ans.push_back(v);
                start = x[0];
                end = x[1];
            }
        }
        vector<int> v = {start,end};
        ans.push_back(v);        
        vector<vector<int>> finalAns;
        for(int i=1;i<ans.size();i++){
            finalAns.push_back(ans[i]);
        }
        return finalAns;
    }
};