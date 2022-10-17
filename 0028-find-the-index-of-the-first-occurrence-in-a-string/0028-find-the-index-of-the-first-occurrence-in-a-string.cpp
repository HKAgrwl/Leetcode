class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = needle.size();
        
        if(n > haystack.size()){
            return -1;
        }
        
        for(int i = 0;i <= haystack.size() - n; i++){
            string st = haystack.substr(i, n);
            if(st == needle){
                return i;
            }
        }
        
        return -1;
    }
};