class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        int fresh = 0;
        int time = 0;
        int rows  = grid.size();
        int cols = grid[0].size();
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(grid[i][j]==1) fresh++;
                if(grid[i][j]==2){
                    q.push({i,j});
                }
            }
        }
        
        int dx[4] = {0, 0, 1, -1};
        int dy[4] = {1, -1, 0, 0};
        
        while(!q.empty() && fresh>0){
            int l = q.size();
            while(l>0){
                int r  = q.front().first;
                int c = q.front().second;
                q.pop();
                for(int i = 0; i < 4; ++i){
                    int nx = r + dx[i], ny = c + dy[i];
                    if(nx < 0 || ny < 0 || nx >= rows || ny >= cols || grid[nx][ny] != 1) continue;
                    grid[nx][ny] = 2;
                    q.push({nx, ny});
                    fresh--;
                }
                l--;
            }
            time++;
        }
        return fresh? -1 : time;
    }
};