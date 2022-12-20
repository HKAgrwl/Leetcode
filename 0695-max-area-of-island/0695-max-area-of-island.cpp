class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        vector<int> ans;
        int max=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1){
                    int count=0;
                    int cnt = dfs(grid,i,j,count);
                    if(max<cnt) max = cnt;
                }
            }
        }
        return max;
        
    }
    
    int dfs(vector<vector<int>>& grid,int x,int y,int &count){
        if(x >= grid.size() || x<0 || y>= grid[0].size() || y<0 || grid[x][y]==0) return NULL;
        grid[x][y]=0;
        count++;
        dfs(grid,x+1,y,count);
        dfs(grid,x-1,y,count);
        dfs(grid,x,y+1,count);
        dfs(grid,x,y-1,count);
        return count;
    }
};