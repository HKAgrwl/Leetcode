class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s2.size()==0) return false;
        
        unordered_map<char,int> char_count;
        for(int i=0;i<s1.size();i++){
            char_count[s1[i]-'a']++;
        }
        
        int left = 0;
        int right = 0;
        int count = s1.size();
        
        while(right < s2.size()){
            if(char_count[s2[right++]-'a']-- >=1) count--;
            if(count==0) return true;
            
            if(right-left == s1.size() && char_count[s2[left++]-'a']++ >=0) count++;
        }
        return false;
    }
};