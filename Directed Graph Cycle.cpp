class Solution {
  public:
    bool isCycle(unordered_map<int, vector<int>>& adj, int u, vector<bool>& vis, vector<bool>& isPath){
        vis[u] = true;
        isPath[u] = true;
        
        for(auto& v : adj[u]){
            if(!vis[v]){
             bool cycleDetected = isCycle(adj, v, vis, isPath);
            if(cycleDetected) return true;   
            } else if(isPath[v]){
                return true;
            }
        }
        isPath[u] = false;
        return false;
    }
    bool isCyclic(int V, vector<vector<int>> &edges) {
        // code here
        unordered_map<int, vector<int>> adj;
        
        for(auto& edge: edges){
            int u = edge[0];
            int v = edge[1];
            
            adj[u].push_back(v);
        }
        
        vector<bool> vis(V, false);
        vector<bool> isPath(V, false);
        
        for(int i = 0; i < V; i++){
            if(!vis[i] && isCycle(adj, i, vis, isPath)){
                return true;
            }
        }
        return false;
    }
};
