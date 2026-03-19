// using dfs
class Solution {
  public:
  
    bool isCycleDFS(unordered_map<int, vector<int>>& adj, int u, vector<bool>& visited, int parent){
        visited[u] = true;
        
        for(auto &v : adj[u]){
            if(parent == v) continue;
            if(visited[v] == true) return true;
            if(isCycleDFS(adj, v, visited, u)) return true;
        }
        return false;
    }
    bool isCycle(int V, vector<vector<int>>& edges) {
        // Code here
        unordered_map<int, vector<int>> adj;
        for(auto &edge : edges){
            int u = edge[0];
            int v = edge[1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        vector<bool> visited(V, false);
        for(int i = 0; i < V; i++){
            if(!visited[i] && isCycleDFS(adj, i, visited, -1)){
                return true;
            }
        }
        
        return false;
    }
};

//using BFS
class Solution {
  public:
  
    bool isCycleBFS(unordered_map<int, vector<int>>& adj, int u, vector<bool>& visited){
        queue<pair<int, int>> que;
        visited[u] = true;
        que.push({u, -1});
        
        while(!que.empty()){
            pair<int, int> p = que.front();
            que.pop();
            
            int source = p.first;
            int parent = p.second;
            
            for(int& v : adj[source]){
                if(visited[v] == false){
                    visited[v] = true;
                    que.push({v, source});
                } else if(v != parent){
                    return true;
                }
            }
        }
        return false;
    }
    bool isCycle(int V, vector<vector<int>>& edges) {
        // Code here
        unordered_map<int, vector<int>> adj;
        for(auto &edge : edges){
            int u = edge[0];
            int v = edge[1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        vector<bool> visited(V, false);
        for(int i = 0; i < V; i++){
            if(!visited[i] && isCycleBFS(adj, i, visited)){
                return true;
            }
        }
        
        return false;
    }
};
