class Solution {
  public:
    vector<int> bfs(vector<vector<int>> &adj) {
        // code here
        int V = adj.size();
        vector<bool> vis(V, false);
        vector<int> res;
        queue<int> q;
        
        int src = 0;
        vis[src] = true;
        q.push(src);
        
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            res.push_back(curr);
            
            for(int x : adj[curr]){
                if(!vis[x]){
                    vis[x] = true;
                    q.push(x);
                }
            }
        }
        return res;
    }
};
