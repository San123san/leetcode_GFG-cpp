class Solution {
  public:
    vector<double> getMedian(vector<int> &arr) {
        // code here
     priority_queue<int> leftHeap;
     priority_queue<int, vector<int>, greater<int>> rightHeap;
     
     vector<double> res;
     
     for(int x : arr){
         if(leftHeap.empty() || x < leftHeap.top()){
             leftHeap.push(x);
         } else {
             rightHeap.push(x);
         }
         
         if(leftHeap.size() > rightHeap.size() + 1){
             rightHeap.push(leftHeap.top());
             leftHeap.pop();
         }
         else if(rightHeap.size() > leftHeap.size()){
             leftHeap.push(rightHeap.top());
             rightHeap.pop();
         }
         
         if(leftHeap.size() > rightHeap.size()){
             res.push_back((double)leftHeap.top());
         }
         else if(rightHeap.size() > rightHeap.size()){
             res.push_back((double)rightHeap.top());
         }
         else {
             double med = (leftHeap.top() + rightHeap.top()) / 2.0;
             res.push_back(med);
         }
     }
     return res;
    }
};
