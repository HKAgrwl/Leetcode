class Solution {
public:
    int myAtoi(string s) {
        if(s.empty() == 1) return 0;
        // if string contains whitespaces ignore the whitespaces
        int i=0;
        while(s[i] == ' ' && i<s.length() ) i++;
        
        // what if my whole string contains whitespaces
        if(i >= s.length()) return 0;
        
        // if we encounter sign then detect the sign
        short sign = 1;
        if(s[i] == '-') {
            sign = -1;
            i++;
        }
        else if(s[i] == '+'){
            sign = 1;
            i++;
        }

        // now shift the number to left
        long long num = 0;
        while (s[i] >= '0' && s[i] <= '9') {
            num = num*10 + (s[i]-'0');
            // at any moment number gets out ot integer range then we'' simply return INT_MAX or INT_MIN
            if(num <= INT_MIN || num >= INT_MAX) break;
            i++;
        }

        num *= sign;
    
        if(num <= INT_MIN) num = INT_MIN;
        else if(num >= INT_MAX) num = INT_MAX;
        return int(num);
    }
};