class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> visited(n,0);
        int count=0;
        for(int i=0;i<n;i++)
        {
            if(!visited[i])
            {
                count++;
                dfs(i,isConnected[i],visited,isConnected);
            }
        }
        return count;
    }
    
    void dfs(int i,vector<int> &v, vector<int>&visited,vector<vector<int>>& isConnected)
    {
        visited[i]=1;
        for(int j=0;j<isConnected[i].size();j++)
        {
            if(!visited[j] && isConnected[i][j]==1)
                dfs(j,isConnected[j],visited,isConnected);
        }
    }
};