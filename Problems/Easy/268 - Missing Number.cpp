
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




// 2nd Approach
// Best Approach
// Using XOR approach 
// Time Complexity = O(N)
// Space Complexity = O(1)
// Approach,  suppose i.e arr = [1,2,3,5], n = 5, and our 1 to n elements are = 1,2,3,4,5
// so, 1^1 is 0, so in this way if we will xor all arr elements with natural elements only 4 will left
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        
        // array elements xor
        int xorArrEle = nums[0];
        for(int itr = 1; itr < n; itr++){
            xorArrEle = xorArrEle ^ nums[itr];
        }
        
        // natural elements xor
        int xorNaturalEle = 1;
        for(int itr = 2; itr <= n; itr++){
            xorNaturalEle = xorNaturalEle ^ itr;
        }
        
        return xorArrEle ^ xorNaturalEle;
    }
};

