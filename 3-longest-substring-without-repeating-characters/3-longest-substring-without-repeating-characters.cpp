class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,bool> visit;
        int left=0;
        int right=0;
        int res=0;
        while(right<s.length()){
			char r = s[right];
            while(!visit[r] && right<s.length()){
                visit[r]=true;
                right++;
				r=s[right];
            }
            res = max(res,right-left);
			char l = s[left];
            while(visit[r]){
                visit[l]=false;
                left++;
				l=s[left];
            }
        }
        return res;
    }
    
};