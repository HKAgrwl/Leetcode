class Solution {
public:
    bool detectCapitalUse(string word) {
        bool pat1,pat2,pat3;
        pat1=pat2=pat3=true;
        if(int(word[0])<97){
            pat2=false;
        }else{
            pat1=pat3=false;
        }
        for(int i=1;i<word.size();i++){
            if(int(word[i])<97){
                pat3=false;
                if(pat2) pat2=false;
            }else{
                pat1=false;
            }
            
        }
        if(pat1 || pat2 || pat3) return true;
        return false;
    }
};