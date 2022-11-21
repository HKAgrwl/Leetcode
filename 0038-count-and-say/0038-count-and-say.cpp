class Solution {
public:
    string countAndSay(int n) {
        return helperFunc("1",1,n);
    }
    
    string helperFunc(string x,int n,int k){
        if (n == k)
	{
		return x;
	}
	string str = "";
	int count = 0;
	int left = 0;
	int right = 0;
	while (right < x.size())
	{
		while (right < x.size() && (x[left] == x[right]))
		{
			right++;
			count++;
		}
		left=right;
		string cnt = to_string(count);
		str += cnt;
		str += x[left-1];
		count=0;
	}
	return helperFunc(str, n+=1, k);
    }
};