class Solution {
public:
    int reverse(int x) {
        long long int sum=0;
        long long int y=x;
        if(y<0){
            y*=-1;
            while(y>0){
                sum = (sum*10) + (y%10);
                y=y/10;
            }
            sum=sum*-1;
            if(sum<INT_MIN){
                return 0;
            }else{
                return sum;
            }
        }else{
             while(y>0){
                sum = (sum*10) + (y%10);
                y=y/10;
             }
        }
        if(sum>INT_MAX){
            return 0;
        }else{
            return sum;
        }
    }
};