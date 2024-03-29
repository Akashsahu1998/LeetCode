
// Question) 358. Rearrange String k Distance Apart


// Implementation

// Using Max Heap & Queue
// Time Complexity : O(NlogN), where N can be max to max 26 char, so O(Nlog26), so we can say overall TC will be O(N)
// Space Complexity : O(N)

class Solution {
public:
    string rearrangeString(string s, int k) {
        
        unordered_map<char, int> freq;
        for(auto ch : s){
            freq[ch]++;
        }
        
        priority_queue<pair<int, char>> maxHeap;
        for(auto m : freq){
            maxHeap.push({m.second, m.first});
        }
        
        queue<pair<int, char>> q;
        string res;
        while(!maxHeap.empty()){
            auto temp = maxHeap.top();
            maxHeap.pop();
            
            res += temp.second;
            
            q.push({temp.first-1, temp.second});
            if(q.size() >= k){
                auto temp = q.front();
                q.pop();
                
                if(temp.first){
                    maxHeap.push(temp);
                }
            }            
        }
        
        return res.size() == s.size() ? res : "";
    }
};
