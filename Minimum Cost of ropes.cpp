class Solution {
  public:
    int minCost(vector<int>& arr) {
        // code here
        priority_queue<int, vector<int>, greater<int>> pq;
        
        for(auto cost : arr){
            pq.push(cost);
        }
        
        int res = 0;
        int merge = 0;
        
        while(pq.size() > 1){
            int t1 = pq.top();
            pq.pop();
            int t2 = pq.top();
            pq.pop();
            
            merge = t1 + t2;
            
            res += merge;
            
            pq.push(merge);
        }
        
        return res;
    }
};
