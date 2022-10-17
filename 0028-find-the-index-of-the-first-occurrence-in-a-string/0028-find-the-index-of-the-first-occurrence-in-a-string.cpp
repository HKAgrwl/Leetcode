class Solution {
public:
    int strStr(string haystack, string needle) {
        int left=0;
        int right = needle.length()-1;
        int flag=0;
        while(right<haystack.length()){
            for(int i=left;i<=right;i++){
                if(i==right && haystack[i]==needle[i-left]){
                    return left;
                }
                if(haystack[i]!=needle[i-left]) break;
            }
            left++;
            right++;
        }
        return -1;
    }
};