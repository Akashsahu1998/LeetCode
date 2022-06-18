
// Question) 1086. High Five


// Implementation

// Using Map & Max Heap
// Time Complexity : O(NlogN)
// Space Complexity : O(N)

class Solution {
public:
    vector<vector<int>> highFive(vector<vector<int>>& items) {
        map<int, priority_queue<int>> mp;
        
        for(auto item : items){
            mp[item[0]].push(item[1]);
        }
        
        vector<vector<int>> res;
        for(auto a : mp){
            long long cnt = 1, total = 0;
            auto score = a.second;
            while(cnt <= 5){
                total += score.top();
                score.pop();
                cnt++;
            }
            res.push_back({a.first, (int)total/5});
        }
        
        return res;
    }
};
