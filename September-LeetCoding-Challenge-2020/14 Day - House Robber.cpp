
// Using DP
// Time Complexity = O(N), Space Complexity = O(1)

class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        int dp1 = nums[0]; 
        int dp2 = 0;       
        for(int itr = 1; itr < nums.size(); itr++){
            int maxMoney = max(dp1, dp2 + nums[itr]);
            dp2 = dp1;            
            dp1 = maxMoney;
        }
        return max(dp1, dp2);
    }
};
