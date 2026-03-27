
class Solution {
  public:
    vector<pair<int, int>> direction = {{1, 0}, {0, -1}, {0, 1}, {-1, 0}};
    string dirLetters = "DLRU";
    
    void dfs(int n, int m, int nCol, int nRow, vector<vector<int>>& maze, vector<vector<int>>& isCheck, string path, vector<string>& pathStore){
        if(nCol-1 == n && nRow-1 == m){
            pathStore.push_back(path);
            return;
        }
        
        isCheck[n][m] = 1;
        
        for(int i = 0; i < 4; i++){
            int x_ = n + direction[i].first;
            int y_ = m + direction[i].second;
            
            if(x_ >= 0 && x_ < nCol && y_ >= 0 && y_ < nRow && maze[x_][y_] == 1 && isCheck[x_][y_] == 0){
                dfs( x_, y_, nCol, nRow, maze, isCheck, path + dirLetters[i], pathStore);
            }
        }
        
        isCheck[n][m] = 0;
        
    }
    vector<string> ratInMaze(vector<vector<int>>& maze) {
        // code here
        int nCol = maze.size();
        if(nCol == 0) return {};
        int nRow = maze[0].size();
        vector<vector<int>> isCheck(nCol, vector<int>(nRow, 0));
        string path = "";
        vector<string> pathStore;
        
        if(maze[0][0] == 0 || maze[nCol - 1][nRow - 1] == 0) return {};
        
        dfs( 0, 0, nCol, nRow, maze, isCheck, path, pathStore);
        
        return pathStore;
    }
};
