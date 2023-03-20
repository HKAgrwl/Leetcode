class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int p = flowerbed.size();
        for(int i=0;i<p;i++){
            if(flowerbed[i]==1) continue;
            bool front = true;
            bool back = true;
            if(i-1>=0 && flowerbed[i-1]==1) back=false;
            if(i+1<p && flowerbed[i+1]==1) front=false;
            if(front && back){
                flowerbed[i]=1;
                n--;
            }
        }
        return (n<=0);
    }
};
