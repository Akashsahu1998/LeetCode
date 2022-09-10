
// Question) 27. Remove Element


// Implementation

// 1st Approach
// This approach is best when we need to remove lots of elements
// Time Complexity : O(N)
// Space Complexity : O(1)

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i = 0;
        for(int j = 0 ; j < nums.size(); j++){
            if(nums[j] != val){
                nums[i] = nums[j];
                i++;
            }
        }
        
        return i;
    }
};


// 2nd Approach
// This approach is best when we need to remove less number of elements
// Time Complexity : O(N)
// Space Complexity : O(1)

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i = 0, n = nums.size();
        while(i < n){
            if(nums[i] == val){
                nums[i] = nums[n-1];
                n--;
            }
            else{
                i++;
            }
        }
        
        return i;
    }
};
