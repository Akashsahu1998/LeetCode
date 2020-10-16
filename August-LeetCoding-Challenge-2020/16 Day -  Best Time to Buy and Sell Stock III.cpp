
// Time Complexity = O(n), Space Complexity = O(1)

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy1 = INT_MAX, buy2 = INT_MAX, profit1 = 0, profit2 = 0; 
        for(int currentPrice: prices) {
            buy1 = min(buy1, currentPrice);
            profit1 = max(profit1, currentPrice - buy1);
            buy2 = min(buy2, currentPrice - profit1);
            profit2 = max(profit2, currentPrice - buy2);
        }
        return profit2;
    }
};
