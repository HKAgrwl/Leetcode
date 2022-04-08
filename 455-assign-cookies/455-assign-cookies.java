class Solution {
    public int findContentChildren(int[] g, int[] s) {
        Arrays.sort(g); Arrays.sort(s);
		// by sorting, duplicate elements will lie adjacent to each other which makes the comparision process simpler.
		
        int cnt=0; // counts the number of content children
        if(s.length==0)
            return 0; // as per the given constraints
			
        for(int i=0;i<g.length;i++)
        {
            for(int j=0;j<s.length;j++)
            {
                if(s[j]>=g[i])  // as per the given constraints
                {
                    s[j]=-1; // by changing the matched value we can avoid duplicate comparisions with array g
                    cnt++;
                    break;
					//once the values match break out of the checking loop.
                }
            }
        }
        return cnt;
    }
}