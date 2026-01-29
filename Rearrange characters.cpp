class Solution {
  public:
    string rearrangeString(string s) {
        // code here
        int n = s.length();
        
        unordered_map<char, int> count;
        
        for(char c : s) count[c]++;
        
        priority_queue<pair<int, char>> pq;
        
        for(auto it : count){
            if (it.second > (n + 1)/2) return "";
            pq.push({it.second, it.first});
        }
        
        string res = "";
        
        pair<int, char> prev = {-1, '#'};
        
        while(!pq.empty()){
            pair<int, char> curr = pq.top();
            pq.pop();
            
            res += curr.second;
            curr.first--;
            
            if(prev.first > 0){
                pq.push(prev);
            }
            
            prev = curr;
        }
        if(res.length() == n) return res;
        else return "-1";
    }
};
