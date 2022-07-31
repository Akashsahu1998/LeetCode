
// Question) 283. Move Zeroes


// Implementation

// 1st Approach
// Using 1 pointers
// Time Complexity = O(N), Space Complexity = O(1)

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int j = 0;
        for(int i = 0; j < nums.size(); i++){
            if(i >= nums.size()){
                nums[j++] = 0;
            }
            else if(nums[i] != 0){
                nums[j++] = nums[i];
            }
        }
    }
};


// 2nd Approach
// Using 2 pointers 
// Time Complexity = O(N), Space Complexity = O(1)

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i = 0, j = 1;
        while(j < nums.size()){
            if(nums[j] != 0 && nums[i] == 0){
                swap(nums[i], nums[j]);
                i++;
            }
            j++;
            
            if(nums[i] != 0){
                i++;
            }
        }
    }
};
