struct Element {
    int val;
    int row;
    int col;
    
    Element(int v, int r, int c) : val(v), row(r), col(c) {};
};

struct Compare {
    bool operator()(Element a, Element b) {
        return a.val > b.val;
    }
};

class Solution {
  public:
    vector<int> findSmallestRange(vector<vector<int>>& mat) {
        // Code here
        int k = mat.size();
        
        priority_queue<Element, vector<Element>, Compare> pq;
        
        int currMax = INT_MIN;
        
        for(int i = 0; i < k; i++) {
            pq.push(Element(mat[i][0], i, 0));
            currMax = max(currMax, mat[i][0]);
        }
        
        int minRange = INT_MAX;
        int start = -1, end = -1;
        
        while (!pq.empty()){
            Element minNode = pq.top();
            pq.pop();
            
            int currMin = minNode.val;
            
            if(currMax - currMin < minRange){
               minRange = currMax - currMin;
               start = currMin;
               end = currMax;
            }
            
            int nextRow = minNode.row;
            int nextCol = minNode.col + 1;
            
            if(nextCol < mat[nextRow].size()){
                int nextVal = mat[nextRow][nextCol];
                
                pq.push(Element(nextVal, nextRow, nextCol));
                currMax = max(currMax, nextVal);
            } else {
                break;
            }
        }
        return {start, end};
    }
};
