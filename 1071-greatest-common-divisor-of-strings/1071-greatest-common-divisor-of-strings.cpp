class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        string ans = "";
        int head=0;
        string interim = "";
        while(head < str1.size() && head < str2.size()){
            interim+= str1[head];
            // cout<<interim<<endl;
            if(isGood(str1,interim) && isGood(str2,interim)){
                ans=interim;
            }
            head++;
        }
        return ans;
    }
    
    bool isGood(string str,string x){
        if(x==str) return true;
        if(x.size() > str.size()) return false;
        if(x.size() == str.size() & x!=str) return false;
        string y = x;
        while(x.size() < str.size()){
            x+=y;
            // cout<<"-"<<x<<endl;
        }
        return isGood(str,x);
    }
};