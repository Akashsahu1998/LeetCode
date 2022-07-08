
// Question) 238. Product of Array Except Self


// Implementation

// Note : we can't use the approach, where we will do product of all elements, after that we can iterate again and divide procuct by each number and put the result, in this approach there can be a possibility of divide by zero exception, bcz number can be 0 as well and also in this que its mentioned that we can't use the division operator

// 1st Approach
// Naive Solution
// Using LeftSum & rightSum array
// Time Complexity = O(N)
// Space Complexity = O(N)

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> leftSum(n), rightSum(n);
        
        for(int i = 0, j = n-1; i < n; i++, j--){
            if(i == 0 || j == n-1){
                leftSum[i] = 1;
                rightSum[j] = 1;
            }
            else{
                leftSum[i] = leftSum[i-1] * nums[i-1];
                rightSum[j] = rightSum[j+1] * nums[j+1];
            }
        }
        
        for(int i = 0; i < n; i++){
            leftSum[i] = leftSum[i] * rightSum[i];
        }
        
        // returning leftSum as a result
        return leftSum;
    }
};
