
// Question) 287. Find the Duplicate Number


// Implementation

// By modifying the array
// Time Complexity = O(N)
// Space Complexity = O(1)

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++){
            int val = abs(nums[i]);
            
            if(nums[val] < 0) return val;
            else nums[val] *= -1;
        }
        
        return -1;
    }
};


// Using slow & fast pointers
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
        
        fast = nums[0];
        while(slow != fast){
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
};
