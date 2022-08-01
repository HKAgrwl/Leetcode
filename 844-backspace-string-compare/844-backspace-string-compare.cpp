class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> s1;
        stack<char> s2;
        for(int i=0;i<s.length();i++){
            if(s[i]=='#'){
                if(s1.empty()){
                    continue;
                }
                s1.pop();
            }else{
                s1.push(s[i]);
            }
        }
        for(int i=0;i<t.length();i++){
            if(t[i]=='#'){
                if(s2.empty()){
                    continue;
                }
                s2.pop();
            }else{
                s2.push(t[i]);
            }
        }
        if(s1.size()!=s2.size()){
            return false;
        }
        while(!s1.empty()){
            if(s1.top()!=s2.top()){
                return false;
            }
            s1.pop();
            s2.pop();
        }
        return true;
    }
};