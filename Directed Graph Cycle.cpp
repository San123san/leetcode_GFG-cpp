// using dfs
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


//using bfs
class Solution {
  public:
    bool isCyclic(int V, vector<vector<int>> &edges) {
        // code here
        unordered_map<int, vector<int>> adj;
        vector<int> inDegree(V, 0);
        
        for(auto& edge : edges){
            int u = edge[0];
            int v = edge[1];
            
            adj[u].push_back(v);
            inDegree[v]++;
        }
        
        queue<int> q;
        for(int i = 0; i < V; i++){
            if(inDegree[i] == 0){
                q.push(i);
            }
        }
        
        int count = 0;
        
        while(!q.empty()){
            int u = q.front();
            q.pop();
            count++;
            
            for(int v : adj[u]){
                inDegree[v]--;
                if(inDegree[v] == 0){
                    q.push(v);
                }
            }
        }
        
        return (count != V);
    }
};
