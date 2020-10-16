
// Time Complexity = O(1)

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxProduct = INT_MIN, pre_num1 = 1, pre_num2 = 1;
        for(int itr = 0; itr < nums.size(); itr++){
            if(nums[itr] == 0){
                pre_num2 = 1;
                pre_num1 = 1;
                maxProduct = max(maxProduct,0);
            }
            else{
                pre_num2 *= nums[itr];
                maxProduct = max({maxProduct, pre_num2, pre_num2 / pre_num1});
                if((pre_num2 < 0) && (pre_num1 == 1)) pre_num1 = pre_num2;                    
            }
        }
        return maxProduct;
    }
};
