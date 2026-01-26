/*
class Node {
   public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
    int countNodes(Node* root){
        if (root == NULL) return 0;
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
    void fillStore(Node* tree, vector<int> &store, int i, bool &valid){
        if(tree == NULL) return;
        
        if(i >= store.size()){
            valid = false;
            return;
        }
        
        store[i] = tree->data;
        
        fillStore(tree->left, store, 2*i+1, valid);
        fillStore(tree->right, store, 2*i+2, valid);
    }
    bool isHeap(Node* tree) {
        // code here
        
        int n = countNodes(tree);
        
        vector<int> store(n, -1);
        bool valid = true;
        
        fillStore(tree, store, 0, valid);
        
        if(!valid) return false;
        
        for(int val : store){
            if(val == -1) return false;
        }
        
        for(int i = 0; i < n; i++){
            int leftChild = 2*i+1;
            int rightChild = 2*i+2;
            
            if(leftChild < n && store[leftChild] > store[i]) return false;
            if(rightChild < n && store[rightChild] > store[i]) return false;
        }
        return true;
    }
};
