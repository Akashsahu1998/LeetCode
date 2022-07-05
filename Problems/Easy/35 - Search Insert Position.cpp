
// Question) 35. Search Insert Position


// Implementation

// Using Binary Search
// Time Complexity : O(LogN)
// Space Complexity : O(1)

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int low = 0, high = nums.size()-1;
        
        while(low <= high){
            int mid = low + (high - low)/2;
            
            if(nums[mid] == target){
                return mid;
            }
            else if(nums[mid] > target){
                high = mid-1;
            }
            else low = mid+1;
        }
        
        return low;
    }
};
