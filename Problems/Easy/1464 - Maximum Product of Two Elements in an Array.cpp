
// Question) 1464. Maximum Product of Two Elements in an Array

// 1st Approach
// Implementation

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int max1 = 0, max2 = 0;
        for(int itr = 0; itr < nums.size(); itr++){
            if(nums[itr] > max1){
                max2 = max1;
                max1 = nums[itr];
            }
            else max2 = max(max2, nums[itr]);
        }
        return ((max1 - 1) * (max2 - 1));
    }
};



// 2nd Approach
// Implementation

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int index1 = 0, max = 0;
        for(int itr = 0; itr < nums.size(); itr++){
            if(nums[itr] > nums[index1]) index1 = itr;
        }
        for(int itr = 0; itr < nums.size(); itr++){
            if(itr != index1){
                if(nums[itr] > max) max = nums[itr];     
            }             
        }
        return ((nums[index1] - 1) * (max - 1));
    }
};
