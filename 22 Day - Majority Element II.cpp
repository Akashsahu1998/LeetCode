class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> arr;
        if(nums.size() <= 1)
            return nums;
        sort(nums.begin(), nums.end());
        int val = nums.size() / 3;
        int count = 1;
        for(int i = 0; i < nums.size() - 1; i++) {
         if(nums[i] == nums[i+1]) {
             count++;
             if(i+1 == nums.size()-1) {
                 if(count > val)
                     arr.push_back(nums[i]);
             }
         }
         
         else {
             if(count > val) {
                 arr.push_back(nums[i]);                 
             }
             
             count = 1;
             if(i + 1 == nums.size()-1) {
                 if(count > val) {
                     arr.push_back(nums[i + 1]);
                     break;   
                 }
                 
             }
         }            
        }
        return arr;
    }
};
