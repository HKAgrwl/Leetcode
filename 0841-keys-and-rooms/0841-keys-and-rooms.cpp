class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        unordered_map<int,set<int>> adj;
        unordered_map<int,bool> visited;
        for(int i=0;i<rooms.size();i++){
            for(int j = 0;j<rooms[i].size();j++){
                int y = rooms[i][j];
                adj[i].insert(y);
            }
        }
        dfs(adj,visited,0);
        for(int i=0;i<rooms.size();i++){
            if(!visited[i]) return false;
        }
        return true;
    }
    
    void dfs(unordered_map<int,set<int>> &adj,unordered_map<int,bool> &visited,int node){
        visited[node] = true;
        for(auto i:adj[node]){
            if(!visited[i]){
                dfs(adj,visited,i);
            }
        }
    }
};