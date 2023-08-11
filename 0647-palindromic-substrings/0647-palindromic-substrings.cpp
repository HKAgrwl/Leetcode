class Solution {
public:
    int countSubstrings(string s) {
        int count =0 ;
        int l;
        int r;
        for(int i=0;i<s.size();i++){
//             odd size
            l = i;
            r= i;
            while(l>=0 && r<s.size() && s[l]==s[r]){
                count++;
                l--;
                r++;
            }
            //             even size
            l = i;
            r= i+1;
            while(l>=0 && r<s.size() && s[l]==s[r]){
                count++;
                l--;
                r++;
            }
            
        }
        return count;
    }
};