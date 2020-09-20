
// Time Complexity = O(N)

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res = 0, currMin = INT_MAX;

        for(auto p : prices) {
            currMin = min(currMin, p);
            res = max(res, p - currMin);
        }
        return res;
    }
};
