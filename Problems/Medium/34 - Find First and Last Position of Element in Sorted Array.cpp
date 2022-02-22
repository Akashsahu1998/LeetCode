
// Question) 34. Find First and Last Position of Element in Sorted Array


// Implementation

// 1st Approach
// Time Complexity = O(N)
// Space Complexity = O(1)

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int low = 0, high = nums.size()-1;        
        int pos = -1;
        
        while(low <= high){
            int mid = low + (high - low)/2;
            if(nums[mid] == target) {
                pos = mid;
                break;
            }
            else if(nums[mid] > target) high = mid-1;
            else low = mid+1;
        }
        if(pos == -1) return {-1, -1};
        
        int first = pos, last = pos;
        
        while(first > 0 && nums[first] == nums[first-1]) first--;
        
        while(last < nums.size()-1 && nums[last] == nums[last+1]) last++;
        
        return {first, last};
    }
};
