class Solution {
public:
    string simplifyPath(string path) {
        int n = path.size();
        vector<string> helper;
        string str="";
        for(int i=0;i<n;i++){
            if(path[i]=='/') {
                if(str.size()!=0) helper.push_back(str);
                str="";
            }
            else{
                str+=path[i];
            }
        }
        if(str.size()!=0) helper.push_back(str);
        stack<string> st;
        for(auto x : helper){
            if(x==".") continue;
            else if(x==".."){
                if(!st.empty()) st.pop();
                if(!st.empty()) st.pop();
            }
            else{
                st.push("/");
                st.push(x);
            }
        }
        vector<string> ansV;
        while(!st.empty()){
            ansV.push_back(st.top());
            st.pop();
        }
        reverse(ansV.begin(),ansV.end());
        if(ansV.size()==0) ansV.push_back("/");
        string ans = "";
        for(auto t : ansV){
            ans+=t;
        }
        return ans;
        
    }
};