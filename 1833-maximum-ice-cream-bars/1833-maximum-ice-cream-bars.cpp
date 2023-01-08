class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(),costs.end());
        long int i=0;
        long int count=0;
        while(coins>=0 && i<costs.size()){
            if(coins >= costs[i]){
              coins -= costs[i];
              count++;
              i++;
            }else{
                break;
            }
        }
        return count;
    }
};