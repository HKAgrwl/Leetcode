class Solution {
public:
    bool closeStrings(string word1, string word2) {
        vector<int> v1(128,0);
        vector<int> v2(128,0);
        for(auto ch : word1){
            int t = ch;
            v1[t]++;
        }
        for(auto ch : word2){
            int t = ch;
            v2[t]++;
        }
        for(int i=0;i< v1.size();i++){
            int flag = 0;
            if(v1[i]==v2[i]){
                flag = 1;
                continue;
            }
            for(int j=i+1;j < v2.size();j++){
                if((v1[i] == v2[j]) && v2[j]!=0 && v2[i]!=0){
                    int x = v2[i];
                    v2[i] = v2[j];
                    v2[j] = x;
                    flag = 1;
                    break;
                }
            }
            
            if(flag==0) return false;
        }
        return true;
    }
};