class Solution {
public:
    set<vector<int>> ans;
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> interim;
        int sum = 0;
        backtrack(k,sum,n,interim,1);
        vector<vector<int>> finalAns;
        for(auto x : ans){
            finalAns.push_back(x);
        }
        return finalAns;
    }
    
    void backtrack(int k,int sum,int n,vector<int> interim,int start){
            if(sum==n && interim.size()==k){
                ans.insert(interim);
                return;
            }
            if(interim.size()==k) return;
            
            for(int i=start;i<10;i++){
                interim.push_back(i);
                backtrack(k,sum+i,n,interim,i+1);
                interim.pop_back();
                backtrack(k,sum,n,interim,i+1);
            }
        }
};