class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        map<int,int> m;
        vector<int> v;
        for(auto x : nums){
            if(!m.count(x)) v.push_back(x);
            m[x]+=1;
        }
        sort(v.begin(),v.end());
        int earn1 = 0;
        int earn2 = 0;
        int temp = 0;
        int currEarn = 0;
        for(int i=0;i<v.size();i++){
            currEarn = v[i]*m[v[i]];
            if(i>0 && v[i] == v[i-1]+1){
                temp = earn2;
                earn2 = max(earn1 + currEarn,earn2);
                earn1 = temp;
            }else{
                temp = earn2;
                earn2 = currEarn + earn2;
                earn1 = temp;
            }
        }
        return earn2;
    }
};