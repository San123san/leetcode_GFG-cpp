class Solution {
  public:
    int kthSmallest(vector<int> &arr, int k) {
        // code here
        priority_queue<int> pq;
        
        for(int num : arr){
            pq.push(num);
            
            if(pq.size() > k){
                pq.pop();
            }
        }
        
        return pq.top();
    }
};
