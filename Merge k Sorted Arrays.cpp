class Solution {
  public:
    vector<int> mergeArrays(vector<vector<int>> &mat) {
        // Code here
        priority_queue<int, vector<int>, greater<int>> pq;
        
        for(int i = 0; i < mat.size(); i++){
            for(int j = 0; j < mat[i].size(); j++){
                pq.push(mat[i][j]);
            }
        }
        
        vector<int> result;
        while(!pq.empty()){
            result.push_back(pq.top()); 
            pq.pop(); 
        }
        
        return result;
    }
};
