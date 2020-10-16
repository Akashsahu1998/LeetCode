
// Time Complexity = O(NlogN), Space Complexcity = O(N)

class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        map<int, int> mp;
        vector<int> answer(intervals.size());        
        for(int itr = 0; itr < intervals.size(); itr++)
            mp[intervals[itr][0]] = itr;
        for(int itr = 0; itr < intervals.size(); itr++) {
            if(mp.lower_bound(intervals[itr][1]) != end(mp)) answer[itr] = mp.lower_bound(intervals[itr][1]) -> second;
            else answer[itr] = -1;
        }
        return answer;
    }
};
