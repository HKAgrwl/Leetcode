class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int ans=0;
        int x = strs.size();
        int len = strs[0].size();
        for(int i=0;i<len;i++){
            int max = INT_MIN;
            for(int j=0;j<x;j++){
                if(int(strs[j][i]) < max ){
                    cout<<strs[j][i]<<endl;
                    ans++;
                    break;
                }
                max = int(strs[j][i]);
            }
        }
        return ans;
    }
};