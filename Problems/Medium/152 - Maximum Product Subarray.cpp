
// Question) 152. Maximum Product Subarray


// Implementation

// Time Complexity: O(N)
// Space Complexity: O(1)
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxProduct = nums[0], maxVal = nums[0], minVal = nums[0];
        
        for(int itr = 1; itr < nums.size(); itr++){
            
            // if negative value then swap minval & maxVal, bcz
            // lets suppose maxVal = 6, minVal = 3, then for val -2, values will change like 
            // maxVal = -12, and minVal = -6, now max val is in minVal and min val is in maxVal
            // so thats why swapping to maintain the max and min value
            if(nums[itr] < 0){
                swap(maxVal, minVal);
            }
            
            // take max for maxValue & min for minVal, so we can maintain the max & min values
            maxVal = max(nums[itr], maxVal * nums[itr]);
            minVal = min(nums[itr], minVal * nums[itr]);
            
            // always maxVal will have the max val thats why comparing maxVal & maxProduct
            maxProduct = max(maxProduct, maxVal);
        }
        
        return maxProduct;
    }
};
