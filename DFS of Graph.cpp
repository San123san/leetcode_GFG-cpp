class Solution {
  public:
    void dfs(vector<vector<int>>& adj, vector<bool>& vis, int u,vector<int>& res){
        if(vis[u] == true) return;
        vis[u] = true;
        res.push_back(u);
        
        for(auto& v : adj[u]){
            if(!vis[v]){
                dfs(adj, vis, v, res);
            }
        }
    }
    vector<int> dfs(vector<vector<int>>& adj) {
        // Code here
        vector<bool> vis(adj.size(), false);
        vector<int> res;
        
        dfs(adj, vis, 0, res);
        
        return res;
    }
};
