class Solution {
public:
    string intToRoman(int num) {
        int pow = -1;
        stack<int> st;
        while(num > 0){
            int x = num%10;
            num = num/10;
            pow++;
            st.push(x);
        }
        string ans = "";
        while(!st.empty()){
            makeRoman(st.top(),ans,pow);
            pow--;
            st.pop();
        }
        return ans;
    }
    
    void makeRoman(int x,string &str,int pow){
        if(pow == 3){
            while(x > 0){
                str += "M";
                x--;
            }
            return;
        }
        if(pow==2){
             if(x==1)  str += "C";
             if(x==2) str += "CC";
             if(x==3) str += "CCC";
             if(x==4) str += "CD";
             if(x==5) str += "D";
             if(x==6) str += "DC";
             if(x==7) str += "DCC";
             if(x==8) str += "DCCC";
             if(x==9) str += "CM";
        }
        if(pow==1){
             if(x==1)  str += "X";
             if(x==2) str += "XX";
             if(x==3) str += "XXX";
             if(x==4) str += "XL";
             if(x==5) str += "L";
             if(x==6) str += "LX";
             if(x==7) str += "LXX";
             if(x==8) str += "LXXX";
             if(x==9) str += "XC";
            return;
        }
        if(pow==0){
             if(x==1)  str += "I";
             if(x==2) str += "II";
             if(x==3) str += "III";
             if(x==4) str += "IV";
             if(x==5) str += "V";
             if(x==6) str += "VI";
             if(x==7) str += "VII";
             if(x==8) str += "VIII";
             if(x==9) str += "IX";
            return;
        }
        return;  
    }
};