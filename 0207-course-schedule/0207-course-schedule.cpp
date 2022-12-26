class Solution {
	private:
	int n;
	bool dfs(int node,vector<int> adj[],vector<int> &vis,vector<int> &dfsVis){
		vis[node] = 1;
		dfsVis[node] = 1;
		for(auto i : adj[node]){
			if(!vis[i]){
				if(dfs(i,adj,vis,dfsVis)){
					return true; 
				}
			}else if(dfsVis[i]){
				return true;
			}
		}
		dfsVis[node] = 0;
		return false;
	}

	bool checkCycle(vector<int> adj[],int vertices){
		vector<int> vis(vertices + 1,0),dfsVis(vertices + 1,0);
		for(int i = 0; i < vertices; i++){
			if(!vis[i]){
				if(dfs(i,adj,vis,dfsVis)){
					return true;
				}
			}
		}

		return false;
	}
public:
	bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
		n = numCourses;
		vector<int>adj[n];
		int m = prerequisites.size();
		for(int i = 0; i < m; i++){
			int course = prerequisites[i][0];
			int pre = prerequisites[i][1];
			adj[course].push_back(pre);
		}
		if(checkCycle(adj,n)){
			return false;
		}
		return true;
	}
};