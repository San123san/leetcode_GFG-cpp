class Solution {
  public:
    vector<vector<int>> directions = {
        {-1, -2}, {-1, 2}, {1, -2}, {1, 2}, {-2, -1}, {-2, 1}, {2, -1}, {2, 1}
    };
    
    bool isValid(int x, int y, int n){
        return (x >= 1 && x <= n & y >= 1 && y <= n);
    }
    int minStepToReachTarget(vector<int>& knightPos, vector<int>& targetPos, int n) {
        // Code here
        int startX = knightPos[0];
        int startY = knightPos[1];
        int targetX = targetPos[0];
        int targetY = targetPos[1];
        
        if(startX == targetX && startY == targetY){
            return 0;
        }
        
        vector<vector<bool>> vis(n + 1, vector<bool>(n + 1, false));
        
        queue<pair<pair<int, int>, int>> q;
        
        q.push({{startX, startY}, 0});
        vis[startX][startY] = true;
        
        while(!q.empty()){
            auto curr = q.front();
            q.pop();
            
            int x = curr.first.first;
            int y = curr.first.second;
            int steps = curr.second;
            
            if(x == targetX && y == targetY){
                return steps;
            }
            
            for(int i = 0; i < 8; i++){
                int newX = x + directions[i][0];
                int newY = y + directions[i][1];
                
                if(isValid(newX, newY, n) && !vis[newX][newY]){
                    vis[newX][newY] = true;
                    q.push({{newX, newY}, steps + 1});
                }
            }
        }
        return -1;
    }
};






