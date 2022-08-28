class Solution {
public:
    bool isValid(string s) {
        stack<char> valid;
        for(int i=0;i<s.length();i++){
            if(valid.empty()){
                valid.push(s[i]);
            }else{
                if((s[i]==')'&& valid.top()=='(')|| (s[i]==']'&& valid.top()=='[')|| (s[i]=='}'&& valid.top()=='{')){
                    valid.pop();
                }else{
                    valid.push(s[i]);
                }
            }
            
        }
        if(valid.empty()){
            return true;
        }
        return false;
    }
};