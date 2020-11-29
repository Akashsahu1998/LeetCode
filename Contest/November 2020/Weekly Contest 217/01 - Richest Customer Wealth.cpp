
// Q1.) 1672. Richest Customer Wealth

// Implementation
// Time Complexity = O(M * N)


class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int sum, res = 0;
        for(int itr1 = 0; itr1 < accounts.size(); itr1++) {
            sum = 0;
            for(int itr2 = 0; itr2 < accounts[itr1].size(); itr2++) {
                sum += accounts[itr1][itr2];
            }   
            res = max(sum, res);
        }
        return res;
    }
};


