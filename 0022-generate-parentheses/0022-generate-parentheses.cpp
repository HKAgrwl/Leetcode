class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> answer;
        string curr;
        combinationGen(answer,curr,0,0,n);
        return answer;
        
    }
    
    void combinationGen(vector<string>& answer,string curr,int open,int close,int max){
        if(curr.size()==max*2){
            answer.push_back(curr);
            return;
        }
        if(open<max){
            curr+='(';
            combinationGen(answer,curr,open+1,close,max);
            curr.erase(curr.size()-1);
        }
        if(close<open){
            curr+=')';
            combinationGen(answer,curr,open,close+1,max);
            curr.erase(curr.size()-1);
        }
    }
};