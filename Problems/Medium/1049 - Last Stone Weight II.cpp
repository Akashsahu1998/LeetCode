
// Question) 1049. Last Stone Weight II


// Implementation

// Using DP
// Time Complexity : O(N * total/2)
// Space Complexity : O(total/2)
// where total is the sum of the elements into stones

// https://www.youtube.com/watch?v=TaZxJt4-FHk&t=679s

class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        
        int total = 0;
        for(auto s : stones){
            total += s;
        }
        
        vector<bool> dp(total/2 + 1, false);
        dp[0] = true;
        
        // from total if we will subtract (maxValue * 2), so we can get whatever the weight is remaining that will be our answer
        int maxValue = 0;
        for(auto stone : stones){
            vector<bool> temp = dp;
            
            for(int num = stone; num <= total/2; num++){
                if(dp[num - stone]){
                    temp[num] = true;
                    maxValue = max(maxValue, num);
                }
                
                if(maxValue == total/2) return total - (maxValue * 2);
            }
            
            dp = temp;
        }
        
        return total - (maxValue * 2);
    }
};
