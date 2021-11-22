
// Question) 518. Coin Change 2


// Implementation

// Time Complexity = O(coins.size() * amount), Space Complexity = O(amount)
class Solution {
public:    
    int change(int amount, vector<int>& coins) {
        vector<int> dp(amount+1);
        dp[0] = 1;
        for(int itr = 0; itr < coins.size(); itr++){
            for(int jtr = coins[itr]; jtr < dp.size(); jtr++){
                dp[jtr] += dp[jtr - coins[itr]];
            }
        }
        return dp[amount];
    }
};
