
// Question) 287. Find the Duplicate Number


// Implementation

// 1st Approach
// By modifying the original array
// Time Complexity = O(N)
// Space Complexity = O(1)

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++){
            int val = abs(nums[i]);
            
            // if any element is less than 0, return the result
            // bcz in the que its given like there will be no negative number\
            // so we are converting values into negative 
            if(nums[val] < 0) return val;
            else nums[val] *= -1;
        }
        
        return -1;
    }
};


// 2nd Approach
// Using slow & fast pointers, without modifying the original array
// Time Complexity = O(N)
// Space Complexity = O(1)

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0], fast = nums[0];
        
        do{
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while(slow != fast);
        
        // run fast as slow
        fast = nums[0];
        while(slow != fast){
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
};
