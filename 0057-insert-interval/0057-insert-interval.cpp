class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        if(intervals.size()==0){
            intervals.push_back(newInterval);
            return intervals;
        }
        vector<vector<int>> vc;
        int flag = 0;
        for(auto x : intervals){
            if(x[0] >= newInterval[1]){
                flag = 1;
                vc.push_back(newInterval);
                vc.push_back(x);
            }
            else vc.push_back(x);
        }
        if(!flag) vc.push_back(newInterval);
        return merge(vc);
    }
    
    vector<vector<int>> merge(vector<vector<int>> intervals) {
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> merged;
        for (auto interval : intervals) {
            // if the list of merged intervals is empty or if the current
            // interval does not overlap with the previous, simply append it.
            if (merged.empty() || merged.back()[1] < interval[0]) {
                merged.push_back(interval);
            }
            // otherwise, there is overlap, so we merge the current and previous
            // intervals.
            else {
                merged.back()[1] = max(merged.back()[1], interval[1]);
            }
        }
        return merged;
    }
};