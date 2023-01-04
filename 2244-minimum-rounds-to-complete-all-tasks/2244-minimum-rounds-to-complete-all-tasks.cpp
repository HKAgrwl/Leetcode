class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int,int> count;
        int round=0;
        int flag=0;
        for(int i=0;i<tasks.size();i++){
            count[tasks[i]]++;
        }
        for(int i=0;i<tasks.size();i++){
            int t = count[tasks[i]];
            if(t==1){
                flag=1;
                continue;
            }
            if(t%3==0) round+=t/3;
            else if(t%3==1){
                round+= (t-4)/3;
                round+=2;
            }
            else if(t%3==2){
                round+=t/3;
                round+=1;
            }
            count[tasks[i]]=0;
        }
        if(flag==1) return -1;
        return round;
    }
};