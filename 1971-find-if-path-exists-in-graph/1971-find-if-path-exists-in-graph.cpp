class Solution {
public:
    
    void prepareAdjList(unordered_map<int,set<int>> &adj,vector<vector<int>> &edges){
        for(int i=0;i<edges.size();i++){
            int u = edges[i][0];
            int v = edges[i][1];

            adj[u].insert(v);
            adj[v].insert(u);
        }
    }
    
    void printAdjList(unordered_map<int,set<int>> &adj){
        for(auto i:adj){
            cout<<i.first<<"->";
            for(auto j: i.second){
                cout<<j<<", ";
            }
            cout<<endl;
        }
    }
    
    bool finder(unordered_map<int,set<int>> &adj,int i,int d,unordered_map<int,bool> &visited){
        visited[i] = true;
        if(i==d) return true;
        for(auto j : adj[i]){
            if(!visited[j]){
                if(finder(adj,j,d,visited)==true) return true;   
            }
        }
        return false;
    }
    
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        unordered_map<int,set<int>> adj;
        prepareAdjList(adj,edges);
        unordered_map<int,bool> visited;
        return finder(adj,source,destination,visited);
    }
};