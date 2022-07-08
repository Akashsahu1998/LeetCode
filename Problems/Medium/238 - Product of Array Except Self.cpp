
// Question) 238. Product of Array Except Self


// Implementation

// Note : we can't use the approach, where we will do product of all elements, after that we can iterate again and divide procuct by each number and put the result, in this approach there can be a possibility of divide by zero exception, bcz number can be 0 as well and also in this que its mentioned that we can't use the division operator

// 1st Approach
// Naive Solution
// Using LeftSum (Prefix Sum) & rightSum (Suffix Sum) array
// Time Complexity = O(N)
// Space Complexity = O(N)

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> leftSum(n), rightSum(n);
        
        // Generating the leftSum & rightSum array
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
        
        // multiply the value of leftSum & rightSum
        for(int i = 0; i < n; i++){
            leftSum[i] = leftSum[i] * rightSum[i];
        }
        
        // returning leftSum as a result
        return leftSum;
    }
};



// 2nd Approach
// Efficient Solution
// Using LeftSum (Prefix Sum) array only and will use that array as a returning result array as well
// Time Complexity = O(N)
// Space Complexity = O(1), here leftSum is a part of output

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        int n = nums.size(), rightSum = 1;
        vector<int> leftSum(n);
        
        // Generating the leftSum array
        for(int i = 0; i < n; i++){
            if(i == 0){
                leftSum[i] = 1;
            }
            else{
                leftSum[i] = leftSum[i-1] * nums[i-1];
            }
        }
        
        // multiply the value of leftSum array & rightSum variable
        for(int i = n-1; i >= 0; i--){
            if(i == n-1){
                leftSum[i] = rightSum * leftSum[i];
            }
            else{
                leftSum[i] = rightSum * leftSum[i];
            }
            
            rightSum = rightSum * nums[i];
        }
        
        // returning leftSum as a result
        return leftSum;
    }
};
