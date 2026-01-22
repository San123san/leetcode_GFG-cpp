// User function Template for C++

class Solution {
  public:
    int kthLargest(vector<int> &arr, int k) {
        // code here
        priority_queue<int, vector<int>, greater<int>> minHeap;
        
        int n = arr.size();
        
        for (int i = 0; i < n; i++) {
            int currSum = 0;
            
            for (int j = i; j < n; j++){
                currSum += arr[j];
                
                minHeap.push(currSum);
                
                if(minHeap.size() > k){
                    minHeap.pop();
                }
            }
        }
        
        return minHeap.top();
    }
};
