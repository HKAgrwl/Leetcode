class Solution {
public:
    bool isHappy(int n) {
        int slowRunner =n;
        int fastRunner = nextGen(n);
        while(slowRunner!=1 && slowRunner!=fastRunner){
            slowRunner = nextGen(slowRunner);
            fastRunner = nextGen(nextGen(fastRunner));
        }
        return slowRunner == 1;
    }
    
    int nextGen(int n){
        int sum=0;
        while(n>0){
            sum+= pow((n%10),2);
            n=n/10;
        }
        return sum;
    }
};