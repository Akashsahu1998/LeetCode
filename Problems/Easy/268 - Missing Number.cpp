
// Question) 268. Missing Number


// Implementation

// 1st Approach
// Using sum approach 
// Time Complexity = O(N)
// Space Complexity = O(1)
// In this approach there is a chance of integer overflow
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        
        // find the total sum of elements from 1 to n
        int totalSum = (n * (n+1)) / 2, sum = 0;
        
        // store the sum of all elements into nums
        for(int itr = 0; itr < nums.size(); itr++){
            sum += nums[itr];
        }
        
        // return the totalSum - sum, bcz the difference is a number which is missed from an array
        return totalSum - sum;
    }
};


