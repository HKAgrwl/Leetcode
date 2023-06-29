class Solution {
public:
    unordered_map<string,int> mp;
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string,int> m;
        for(auto x : wordDict){
            m[x] = 1;
        }
        for(int i=0;i<s.size();i++){
            if(helper(s,m)) return true;
        }
        
        return false;
    }
    
    bool helper(string s,unordered_map<string,int> m){
        if(s.size() ==0) return true;
        if(mp[s]==1) return false;
        bool check = false;
        for(int i=1;i <= s.size();i++){
            string a = s.substr(0,i);
            if(m[a]==1){
                string b = s.substr(i,s.size()-i);
                check = helper(b,m);
            }else{
                mp[a] = 1;
            }
            if(check) return true;
        }
        return false;
    }
};