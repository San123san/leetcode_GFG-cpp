/*
class Node {
  public:
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};
*/

class Solution {
  public:
    Node* mergeKLists(vector<Node*>& arr) {
        // code here
        int len = arr.size();
        
        priority_queue<int, vector<int>, greater<int>> minHeap;
        
        for (int i = 0; i < len; i++){
            Node* curr = arr[i];
            
            while (curr != NULL){
                minHeap.push(curr->data);
                curr = curr->next;
            }
        }
        
        Node* dummy = new Node(0);
        Node* tail = dummy;
        
        while(!minHeap.empty()){
            int t = minHeap.top();
            minHeap.pop();
            
            tail->next = new Node(t);
            tail = tail->next;
        }
        return dummy->next;
    }
};
