
// Question) 322. Coin Change


// Implementation

// 1st Approach
// Iterative solution using DP
// Time Complexity = O(amount*coins.size()), Space Complexity = O(amount)
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {        
        vector<int> dp(amount+1, amount+1);
        dp[0] = 0;
        for(int itr = 1; itr < dp.size(); itr++){
            for(int jtr = 0; jtr < coins.size(); jtr++){
                if(coins[jtr] > itr) continue;
                dp[itr] = min(dp[itr - coins[jtr]]+1, dp[itr]);
            }
        }        
        return (dp[amount] == amount+1) ? -1 : dp[amount];
    }
};
