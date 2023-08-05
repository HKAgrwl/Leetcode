class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> v;
        helper(ans,n,k,v,1);
        return ans;
        
    }
    
    void helper(vector<vector<int>> &ans,int n,int k,vector<int> &v,int i){
    if(v.size()==k){
        ans.push_back(v);
        return;
    }
    if(i>n) return;
    
    // check if i is already in v
    if(find(v.begin(), v.end(), i) == v.end()){
        // push i only if it is not in v
        v.push_back(i);
        helper(ans,n,k,v,i+1);
        // pop i after exploring its branch
        v.pop_back();
    }
    
    helper(ans,n,k,v,i+1);
    return;
}
};