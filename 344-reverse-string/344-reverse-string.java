class Solution {
    public void recursion(char[] s,int i,int n)
    {
        if(n > s.length-1)
            return;
        char c = s[n];
        n++;
        i--;
        recursion(s,i,n);
        s[i+1] = c;
        
    }
    public void reverseString(char[] s) {
        int i = s.length-1;
        int n = 0;
        recursion(s,i,n);
    }
}