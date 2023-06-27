class Solution {
public:
    string removeStars(string s) {
        stack<char> st;
        for(auto ch : s){
            if(ch=='*' && !st.empty()){
                st.pop();
                continue;
            }
            st.push(ch);
        }
        stack<int> st2;
        while(!st.empty()){
            char x = st.top();
            st2.push(x);
            st.pop();
        }
        
        string finalAns = "";
        
        while(!st2.empty()){
            finalAns += st2.top();
            st2.pop();
        }
        
        return finalAns;
    }
};