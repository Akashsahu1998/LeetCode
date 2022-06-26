
// Question) 136. Single Number


// Implementation

// Using XOR (Bit Manipulation)
// Time Complexity : O(N)
// Space Complexity : O(1)

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int xorValue = nums[0];
        for(int i = 1; i < nums.size(); i++){
            xorValue ^= nums[i];
        }
        return xorValue;
    }
};
