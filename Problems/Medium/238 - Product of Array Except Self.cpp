
// Question) 238. Product of Array Except Self


// Implementation

// Note : we can't use the approach, where we will do product of all elements, after that we can iterate again and divide procuct by each number
// and put the result, in this approach there can be a possibility of divide by zero exception, bcz number can be 0 as well and also in this que its mentioned that we can't use the division operator

// 1st Approach
// Naive Solution
// Using leftProduct (Prefix Sum/Product) & rightProduct (Suffix Sum/Product) array
// Time Complexity = O(N)
// Space Complexity = O(N), here we are using extra space as rightProduct, we can assume leftProduct as a part of output

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> leftProduct(n), rightProduct(n);
        
        // Generating the leftProduct & rightProduct array
        for(int i = 0, j = n-1; i < n; i++, j--){
            if(i == 0 || j == n-1){
                leftProduct[i] = 1;
                rightProduct[j] = 1;
            }
            else{
                leftProduct[i] = leftProduct[i-1] * nums[i-1];
                rightProduct[j] = rightProduct[j+1] * nums[j+1];
            }
        }
        
        // multiply the value of leftProduct & rightProduct
        for(int i = 0; i < n; i++){
            leftProduct[i] = leftProduct[i] * rightProduct[i];
        }
        
        // returning leftProduct as a result
        return leftProduct;
    }
};


// 2nd Approach
// Efficient Solution
// Time Complexity = O(N)
// Space Complexity = O(1), / Using leftProduct array only and will use that array as a returning result array as well

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        int n = nums.size(), rightProduct = 1;
        vector<int> leftProduct(n);
        
        // Generating the leftProduct array
        for(int i = 0; i < n; i++){
            if(i == 0){
                leftProduct[i] = 1;
            }
            else{
                leftProduct[i] = leftProduct[i-1] * nums[i-1];
            }
        }
        
        // multiply the value of leftSum array & rightProduct variable
        for(int i = n-1; i >= 0; i--){
            leftProduct[i] = rightProduct * leftProduct[i];
            rightProduct = rightProduct * nums[i];
        }
        
        // returning leftSum as a result
        return leftProduct;
    }
};
