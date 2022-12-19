class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> ans(n,0);
        stack<int> tool;
        for(int i=0;i<n;i++){
            while(!tool.empty() && temperatures[tool.top()] < temperatures[i]){
                    ans[tool.top()] = i-tool.top();
                    tool.pop();   
            }
            tool.push(i);
        }
        return ans;
    }
};