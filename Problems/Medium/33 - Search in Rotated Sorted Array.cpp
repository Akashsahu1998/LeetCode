
// Question) 33. Search in Rotated Sorted Array


// Implementation

// Using Binary Search
// Time Complexity = O(LogN)
// Space Complexity = O(1)
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0, high = nums.size()-1;
        
        while(low <= high){
            int mid = low + (high-low)/2;
             
            if(target == nums[mid]) return mid;
            
            if(nums[low] <= nums[mid]){
                if(nums[low] <= target && target <= nums[mid]) high = mid-1;
                else low = mid+1;
            }
            else{
                if(nums[mid] <= target && target <= nums[high]) low = mid+1;
                else high = mid-1;
            }
        }
        
        return -1;
    }
};
