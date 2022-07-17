
// Question) 322. Coin Change


// Implementation

// 1st Approach
// Recursive using DP
// Time Complexity = O(amount*coins.size())
// Space Complexity = O(amount)
class Solution {
public:    
    int findLeastCombination(vector<int>& coins, vector<int>& dp, int amount){
        if(amount < 0) return -1;
        if(amount == 0) return 0;
        if(dp[amount] != 0) return dp[amount];
        
        int minimumValue = INT_MAX;
        for(int itr = 0; itr < coins.size(); itr++){
            int temp = findLeastCombination(coins, dp, amount - coins[itr]);
            if(temp >= 0 && temp < minimumValue) minimumValue = temp + 1;
        }
        
        return dp[amount] = (minimumValue != INT_MAX) ? minimumValue : -1;
    }
    
    int coinChange(vector<int>& coins, int amount) {        
        vector<int> dp(amount+1);
        return findLeastCombination(coins, dp, amount);
    }
};


// 2nd Approach
// Iterative using DP
// Time Complexity = O(amount*coins.size())
// Space Complexity = O(amount)
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
