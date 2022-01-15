
// Question) 523. Continuous Subarray Sum


// Implementation

// Naive Approach
// Giving TLE
// Time Complexity = O(N^2), Space Complexity = O(1)
class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int sum = nums[0];
        for(int itr = 1; itr < nums.size(); itr++){
            sum += nums[itr];
            if(sum % k == 0) return true;
            
            int temp = sum;
            for(int jtr = 0; jtr < itr-1; jtr++){
                temp -= nums[jtr];
                if(temp % k == 0) return true;
            }
        }
        return false;
    }
};
