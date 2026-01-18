// User function Template for C++

class Solution {
  public:
    vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m) {
        // your code here
        sort(a.begin(), a.end(), greater<int>());
        sort(b.begin(), b.end(), greater<int>());
        
        int ai = 0;
        int bi = 0;
        vector<int> res;
        
        while(ai < n && bi < m){
            if(a[ai] > b[bi]){
                res.push_back(a[ai]);
                ai++;
            }
            else{
                res.push_back(b[bi]);
                bi++;
            }
        }
        
        while (ai < n) {
            res.push_back(a[ai]);
            ai++;
        }

        while (bi < m) {
            res.push_back(b[bi]);
            bi++;
        }
        
        return res;
    }
};
